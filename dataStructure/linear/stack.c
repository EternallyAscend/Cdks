#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "../../error.h"

// Array Version Stack for Int.

struct StackInt* generateWithSizeStackInt(unsigned long long int size) {
    struct StackInt* pointer = (struct StackInt*)malloc(sizeof(struct StackInt));
    pointer->tail = 0;
    pointer->size = size;
    pointer->stack = (int*)malloc(sizeof(int) * pointer->size);
    return pointer;
};

struct StackInt* generateStackInt() {
    return generateWithSizeStackInt(16);
};

void destroyStackInt(struct StackInt* stack) {
    if (NULL == stack) {
        return;
    }
    if (NULL != stack->stack) {
        free(stack->stack);
    }
    free(stack);
};

int isNullStackInt(struct StackInt* stack) {
    if (NULL == stack) {
        return ErrorEmptyPointer;
    }
    if (NULL == stack->stack) {
        return ErrorEmptyPointer;
    }
    return False;
};

int isEmptyStackInt(struct StackInt* stack) {
    int error = isNullStackInt(stack);
    if (error) {
        return error;
    }
    if (0 == stack->tail) {
        return ErrorEmptyStruct;
    }
    return False;
};

unsigned long long int getLengthStackInt(struct StackInt* stack) {
    if (isNullStackInt(stack)) {
        return 0;
    }
    else {
        return stack->tail;
    }
};

void extendStackInt(struct StackInt* stack) {
    if (isNullStackInt(stack)) {
        return;
    }
    unsigned long long int cursor = 0;
    unsigned long long int newSize = stack->size;
    // TODO Check limit for newSize.
    newSize = newSize << 1;
    int* newStack = (int*)malloc(sizeof(int) * newSize);
    for (; cursor < stack->tail; cursor++) {
        newStack[cursor] = stack->stack[cursor];
    }
    free(stack->stack);
    stack->stack = newStack;
    stack->size = newSize;
};

int pushStackInt(struct StackInt* stack, int value) {
    int error = isNullStackInt(stack);
    if (error) {
        return error;
    }
    if (stack->tail == stack->size) {
        extendStackInt(stack);
    }
    stack->stack[stack->tail++] = value;
    return True;
};

int popStackInt(struct StackInt* stack) {
    int error = isEmptyStackInt(stack);
    if (error) {
        return error;
    }   
    return stack->stack[--stack->tail];
};

void printStackInt(struct StackInt* stack) {
    if (isNullStackInt(stack)) {
        return;
    }
    for (unsigned long long int cursor = 0; cursor < stack->size; cursor++) {
        printf("%d ", stack->stack[cursor]);
    }
    printf("\nStack Int: length %lld, size %lld.\n", stack->tail, stack->size);
};

struct StackInt* copyStackInt(struct StackInt* stack) {
    if (isNullStackInt(stack) || 0 == stack->size) {
        return NULL;
    }
    struct StackInt* copy = generateWithSizeStackInt(stack->size);
    for (; copy->tail < stack->tail; copy->tail++) {
        copy->stack[copy->tail] = stack->stack[copy->tail];
    }
    return copy;
};

void testStackInt() {
    struct StackInt* stackInt = generateStackInt();
    for (int cursor = 0; cursor < 64; cursor++) {
        pushStackInt(stackInt, cursor);
    }
    struct StackInt* stackIntCopy = copyStackInt(stackInt);
    printStackInt(stackInt);
    printStackInt(stackIntCopy);
    for (int cursor = 0; cursor < 65; cursor++) {
        printf("%d ", popStackInt(stackInt));
    }
    printStackInt(stackInt);
    printStackInt(stackIntCopy);
    destroyStackInt(stackInt);
    destroyStackInt(stackIntCopy);
};

// Linked Version Stack for Int.

struct LinkedStackInt* generateLinkedStackInt() {
    struct LinkedStackInt* pointer = (struct LinkedStackInt*)malloc(sizeof(struct LinkedStackInt));
    pointer->head = NULL;
    pointer->tail = NULL;
    return pointer;
};

void destroyLinkedStackInt(struct LinkedStackInt* stack) {
    if (isNullLinkedStackInt(stack)) {
        return;
    }
    if (!isEmptyLinkedStackInt(stack)) {
        destroyWholeBackwardIntNode(stack->tail);
    }
    free(stack);
};

int isNullLinkedStackInt(struct LinkedStackInt* stack) {
    if (NULL == stack) {
        return ErrorEmptyPointer;
    }
    return False;
};

int isEmptyLinkedStackInt(struct LinkedStackInt* stack) {
    int error = isNullLinkedStackInt(stack);
    if (error) {
        return error;
    }
    if (NULL == stack->head) {
        return ErrorEmptyStruct;
    }
    return False;
};

unsigned long long int getLengthLinkedStackInt(struct LinkedStackInt* stack) {
    if (isNullLinkedStackInt(stack)) {
        return 0;
    }
    unsigned long long int length = 0;
    struct BackwardIntNode* pointer = stack->tail;
    while (NULL != pointer) {
        pointer = pointer->last;
        length++;
    }
    return length;
};

int pushLinkedStackInt(struct LinkedStackInt* stack, int value) {
    int error = isNullLinkedStackInt(stack);
    if (error) {
        return error;
    }
    if (isEmptyLinkedStackInt(stack)) {
        stack->head = stack->tail = generateBackwardIntNode(value);
    } else {
        stack->tail = combineBackwardIntNode(stack->tail, value);
    }
    return True;
};

int popLinkedStackInt(struct LinkedStackInt* stack) {
    int error = isEmptyLinkedStackInt(stack);
    if (error) {
        return error;
    }
    int value = stack->tail->value;
    stack->tail = destroyLastBackwardIntNode(stack->tail);
    // Reset as Empty Linked Stack.
    if (NULL == stack->tail) {
        stack->head = NULL;
    }
    return value;
};

void printLinkedStackInt(struct LinkedStackInt* stack) {
    if (isNullLinkedStackInt(stack)) {
        return;
    }
    unsigned long long int length = 0;
    struct BackwardIntNode* pointer = stack->tail;
    while (NULL != pointer) {
        printf("%d ", pointer->value);
        pointer = pointer->last;
        length++;
    }
    printf("\nLinked Stack Int: length %lld.\n", length);
};

struct LinkedStackInt* copyLinkedStackInt(struct LinkedStackInt* stack) {
    if (!isEmptyLinkedStackInt(stack)) {
        struct LinkedStackInt* copy = generateLinkedStackInt();
        copy->tail = generateBackwardIntNode(stack->tail->value);
        struct BackwardIntNode* reader = stack->tail->last;
        struct BackwardIntNode* writer = copy->tail;
        while (NULL != reader) {
            writer->last = generateBackwardIntNode(reader->value);
            reader = reader->last;
            writer = writer->last;
        }
        copy->head = writer;
        return copy;
    }
    return NULL;
};

void testLinkedStackInt() {
    struct LinkedStackInt* stack = generateLinkedStackInt();
    for (int cursor = 0; cursor < 64; cursor++) {
        pushLinkedStackInt(stack, cursor);
    }
    struct LinkedStackInt* stackCopy = copyLinkedStackInt(stack);
    printLinkedStackInt(stack);
    printLinkedStackInt(stackCopy);
    for (int cursor = 0; cursor < 65; cursor++) {
        printf("%d ", popLinkedStackInt(stack));
    }
    printLinkedStackInt(stack);
    printLinkedStackInt(stackCopy);
    destroyLinkedStackInt(stack);
    destroyLinkedStackInt(stackCopy);
};
