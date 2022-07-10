#include <stdio.h>
#include <stdlib.h>

#include "maxHeap.h"
#include "../../error.h"
#include "../../algorithm/compare/basic.h"

struct MaxHeapInt* generateWithSizeMaxHeapInt(int(*greaterThan)(int, int), unsigned long long int size) {
    struct MaxHeapInt* pointer = (struct MaxHeapInt*)malloc(sizeof(struct MaxHeapInt));
    pointer->tail = 0;
    pointer->size = size;
    pointer->maxHeap = (int*)malloc(sizeof(int) * size);
    pointer->greaterThan = greaterThan;
    return pointer;
};

struct MaxHeapInt* generateMaxHeapInt(int(*greaterThan)(int, int)) {
    return generateWithSizeMaxHeapInt(greaterThan, 16);
};

void destroyMaxHeapInt(struct MaxHeapInt* maxHeap) {
    if (NULL == maxHeap) {
        return;
    }
    if (NULL != maxHeap->maxHeap) {
        free(maxHeap->maxHeap);
    }
    free(maxHeap);
};

int isNullMaxHeapInt(struct MaxHeapInt* maxHeap) {
    if (NULL == maxHeap) {
        return ErrorEmptyPointer;
    }
    if (NULL == maxHeap->maxHeap) {
        return ErrorEmptyPointer;
    }
    return False;
};

int isEmptyMaxHeapInt(struct MaxHeapInt* maxHeap) {
    int error = isNullMaxHeapInt(maxHeap);
    if (error) {
        return error;
    }
    if (0 == maxHeap->tail) {
        return ErrorEmptyStruct;
    }
    return False;
};

unsigned long long int getLengthMaxHeapInt(struct MaxHeapInt* maxHeap) {
    int error = isNullMaxHeapInt(maxHeap);
    if (error) {
        return 0;
    }
    else {
        return maxHeap->tail;
    }
};

void extendMaxHeapInt(struct MaxHeapInt* maxHeap) {
    int error = isNullMaxHeapInt(maxHeap);
    if (error) {
        return;
    }
    unsigned long long int newSize = maxHeap->size;
    // TODO Check limit for newSize.
    newSize = newSize << 1;
    maxHeap->maxHeap = (int*)realloc(maxHeap->maxHeap, sizeof(int) * newSize);
    maxHeap->size = newSize;
};

int pushMaxHeapInt(struct MaxHeapInt* maxHeap, int value) {
    int error = isNullMaxHeapInt(maxHeap);
    if (error) {
        return error;
    }
    if (maxHeap->tail == maxHeap->size) {
        extendMaxHeapInt(maxHeap);
    }
    maxHeap->maxHeap[maxHeap->tail++] = value;
    // Adjust the maxHeap after insert.
    unsigned long long int current = maxHeap->tail - 1;
    while (current) {
        unsigned long long int parent = (current - 1) >> 1;
        if (maxHeap->greaterThan(maxHeap->maxHeap[current], maxHeap->maxHeap[parent])) {
            int temporary = maxHeap->maxHeap[parent];
            maxHeap->maxHeap[parent] = maxHeap->maxHeap[current];
            maxHeap->maxHeap[current] = temporary;
            current = parent;
        }
        else {
            break;
        }
    }
    return True;
};

int popMaxHeapInt(struct MaxHeapInt* maxHeap) {
    int error = isEmptyMaxHeapInt(maxHeap);
    if (error) {
        return error;
    }
    int value = maxHeap->maxHeap[0];
    maxHeap->maxHeap[0] = maxHeap->maxHeap[--maxHeap->tail];
    unsigned long long int current = 0;
    while (current < maxHeap->tail) {
        unsigned long long int left = (current << 1) + 1;
        unsigned long long int right = left + 1;
        if (left < maxHeap->tail) {
            if (right < maxHeap->tail && maxHeap->greaterThan(maxHeap->maxHeap[right], maxHeap->maxHeap[left])) {
                if (maxHeap->greaterThan(maxHeap->maxHeap[right], maxHeap->maxHeap[current])) {
                    int temporary = maxHeap->maxHeap[right];
                    maxHeap->maxHeap[right] = maxHeap->maxHeap[current];
                    maxHeap->maxHeap[current] = temporary;
                    current = right;
                }
                else {
                    break;
                }
            }
            else {
                if (maxHeap->greaterThan(maxHeap->maxHeap[left], maxHeap->maxHeap[current])) {
                    int temporary = maxHeap->maxHeap[left];
                    maxHeap->maxHeap[left] = maxHeap->maxHeap[current];
                    maxHeap->maxHeap[current] = temporary;
                    current = left;
                }
                else {
                    break;
                }
            }
        }
        else {
            break;
        }
    }
    return value;
};

void printMaxHeapInt(struct MaxHeapInt* maxHeap) {
    if (isNullMaxHeapInt(maxHeap)) {
        return;
    }
    for (unsigned long long int cursor = 0; cursor < maxHeap->tail; cursor++) {
        printf("%d ", maxHeap->maxHeap[cursor]);
    }
    printf("\nMaxHeap Int: length %lld, size %lld.\n", maxHeap->tail, maxHeap->size);
};

struct MaxHeapInt* copyMaxHeapInt(struct MaxHeapInt* maxHeap) {
    if (isNullMaxHeapInt(maxHeap)) {
        return NULL;
    }
    struct MaxHeapInt* copy = generateWithSizeMaxHeapInt(maxHeap->greaterThan, maxHeap->size);
    for (; copy->tail < maxHeap->tail; copy->tail++) {
        copy->maxHeap[copy->tail] = maxHeap->maxHeap[copy->tail];
    }
    return copy;
};

void testMaxHeapInt() {
    struct MaxHeapInt* maxHeap = generateMaxHeapInt(greaterThanInt);
    for (int cursor = 0; cursor < 32; cursor++) {
        pushMaxHeapInt(maxHeap, cursor);
    }
    printMaxHeapInt(maxHeap);
    struct MaxHeapInt* copy = copyMaxHeapInt(maxHeap);
    for (int cursor = 0; cursor < 32; cursor++) {
        printf("%d ", popMaxHeapInt(maxHeap));
    }
    printf("\n");
    printMaxHeapInt(maxHeap);
    printMaxHeapInt(copy);
    destroyMaxHeapInt(maxHeap);
    destroyMaxHeapInt(copy);
};
