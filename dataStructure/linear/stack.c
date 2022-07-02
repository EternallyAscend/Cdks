#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "../../error.h"

struct StackInt* generateWithSizeStackInt(unsigned int size) {
    struct StackInt* pointer = (struct StackInt*)malloc(sizeof(struct StackInt));
    pointer->tail = 0;
    pointer->size = size;
    pointer->stack = (int*)malloc(sizeof(int) * pointer->size);
    return pointer;
};

struct StackInt* generateStackInt() {
    return generateWithSizeStackInt(16);
};

void destroyStackInt(struct StackInt* pointer) {
    if (NULL != pointer->stack) {
        free(pointer->stack);
    }
    free(pointer);
};

int isNullStackInt(struct StackInt* stack) {
    if (NULL == stack) {
        return ErrorEmptyPointer;
    }
    if (NULL == stack) {
        return ErrorEmptyPointer;
    }
    return False;
};

int isEmptyStackInt(struct StackInt* stack) {
    if (0 == stack->size) {
        return ErrorEmptyStruct;
    }
    return False;
};

void extendStackInt(struct StackInt* stack) {
    if (isNullStackInt(stack)) {
        return;
    }
    int cursor = 0;
    int newSize = stack->size;
    newSize = newSize << 1;
    int* newStack = (int*)malloc(sizeof(int) * newSize);
    for (; cursor < stack->tail; cursor++) {
        newStack[cursor] = stack->stack[cursor];
    }
    free(stack->stack);
    stack->stact = newStack;
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
        printf("Empty.\n");
        return;
    }
    printf("Stack Int: length %d, size %d.\n", stack->tail, stack->size);
    for (int cursor = 0; cursor < stack->size; cursor++) {
        printf("%d ", stack->stack[cursor]);
    }
    printf("\n");
};

struct StackInt* copyStackInt(struct StackInt* stack) {
    struct StackInt* copy = generateWithSizeStackInt(stack->size);
    for (; copy->tail < stack->tail; copy->tail++) {
        copy->stack[copy->tail] = stack->stack[copy->tail];
    }
    return copy;
};
