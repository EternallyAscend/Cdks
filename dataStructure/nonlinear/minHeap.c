#include <stdio.h>
#include <stdlib.h>

#include "minHeap.h"
#include "../../error.h"

int greaterThanInt(int left, int right) {
    return left > right;
};

struct MinHeapInt* generateWithSizeMinHeapInt(int(*greaterThan)(int, int), unsigned long long int size) {
    struct MinHeapInt* pointer = (struct MinHeapInt*)malloc(sizeof(struct MinHeapInt));
    pointer->tail = 0;
    pointer->size = size;
    pointer->minHeap = (int*)malloc(sizeof(int) * size);
    pointer->greaterThan = greaterThan;
    return pointer;
};

struct MinHeapInt* generateMinHeapInt(int(*greaterThan)(int, int)) {
    return generateWithSizeMinHeapInt(greaterThan, 16);
};

void destroyMinHeapInt(struct MinHeapInt* minHeap) {
    if (NULL == minHeap) {
        return;
    }
    if (NULL != minHeap->minHeap) {
        free(minHeap->minHeap);
    }
    free(minHeap);
};

int isNullMinHeapInt(struct MinHeapInt* minHeap) {
    if (NULL == minHeap) {
        return ErrorEmptyPointer;
    }
    if (NULL == minHeap->minHeap) {
        return ErrorEmptyPointer;
    }
    return False;
};

int isEmptyMinHeapInt(struct MinHeapInt* minHeap) {
    int error = isNullMinHeapInt(minHeap);
    if (error) {
        return error;
    }
    if (0 == minHeap->tail) {
        return ErrorEmptyStruct;
    }
    return False;
};

unsigned long long int getLengthMinHeapInt(struct MinHeapInt* minHeap) {
    if (isNullMinHeapInt(minHeap)) {
        return 0;
    }
    else {
        return minHeap->tail;
    }
};

void extendMinHeapInt(struct MinHeapInt* minHeap) {
    if (isNullMinHeapInt(minHeap)) {
        return;
    }
    unsigned newSize = minHeap->size;
    // TODO Check limit for newSize.
    newSize = newSize << 1;
    minHeap->minHeap = (int*)realloc(minHeap->minHeap, sizeof(int) * newSize);
    minHeap->size = newSize;
};

int pushMinHeapInt(struct MinHeapInt* minHeap, int value) {
    int error = isNullMinHeapInt(minHeap);
    if (error) {
        return error;
    }
    if (minHeap->tail == minHeap->size) {
        extendMinHeapInt(minHeap);
    }
    minHeap->minHeap[minHeap->tail++] = value;
    // Adjust the minHeap after insert.
    unsigned long long int current = minHeap->tail - 1;
    while(current) {
        // Find parent node and compare.
        unsigned long long int parent = (current - 1) >> 1;
        if (minHeap->greaterThan(minHeap->minHeap[parent], minHeap->minHeap[current])) {
        // if (minHeap->minHeap[current] < minHeap->minHeap[parent]) {
            int temporary = minHeap->minHeap[parent];
            minHeap->minHeap[parent] = minHeap->minHeap[current];
            minHeap->minHeap[current] = temporary;
            current = parent;
        }
        else {
            break;
        }
    }
    return True;
};

int popMinHeapInt(struct MinHeapInt* minHeap) {
    int error = isEmptyMinHeapInt(minHeap);
    if (error) {
        return error;
    }
    int value = minHeap->minHeap[0];
    // Adjust the minHeap after pop, replace with last value and adjust.
    minHeap->minHeap[0] = minHeap->minHeap[--minHeap->tail];
    // Find min value in current node and sub nodes.
    unsigned long long int current = 0;
    while (current < minHeap->tail) {
        unsigned long long int left = (current << 1) + 1;
        unsigned long long int right = left + 1;
        if (left < minHeap->tail) {
            if (right < minHeap->tail && minHeap->minHeap[left] > minHeap->minHeap[right]) {
                // Compare right.
                if (minHeap->greaterThan(minHeap->minHeap[current], minHeap->minHeap[right])) {
                // if (minHeap->minHeap[current] > minHeap->minHeap[right]) {
                    int temporary = minHeap->minHeap[right];
                    minHeap->minHeap[right] = minHeap->minHeap[current];
                    minHeap->minHeap[current] = temporary;
                    current = right;
                }
                else {
                    break;
                }
            }
            else {
                // Compare left.
                if (minHeap->greaterThan(minHeap->minHeap[current], minHeap->minHeap[left])) {
                // if (minHeap->minHeap[current] > minHeap->minHeap[left]) {
                    int temporary = minHeap->minHeap[left];
                    minHeap->minHeap[left] = minHeap->minHeap[current];
                    minHeap->minHeap[current] = temporary;
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

void printMinHeapInt(struct MinHeapInt* minHeap) {
    if (isNullMinHeapInt(minHeap)) {
        return;
    }
    for (unsigned long long int cursor = 0; cursor < minHeap->tail; cursor++) {
        printf("%d ", minHeap->minHeap[cursor]);
    }
    printf("\nMinHeap Int: length %lld, size %lld.\n", minHeap->tail, minHeap->size);
};

struct MinHeapInt* copyMinHeapInt(struct MinHeapInt* minHeap) {
    if (isNullMinHeapInt(minHeap)) {
        return NULL;
    }
    struct MinHeapInt* copy = generateWithSizeMinHeapInt(minHeap->greaterThan, minHeap->size);
    for (; copy->tail < minHeap->tail; copy->tail++) {
        copy->minHeap[copy->tail] = minHeap->minHeap[copy->tail];
    }
    return copy;
};

void testMinHeapInt() {
    struct MinHeapInt* minHeap = generateMinHeapInt(greaterThanInt);
    for (int cursor = 0; cursor < 32; cursor++) {
        pushMinHeapInt(minHeap, 64 - cursor);
    }
    printMinHeapInt(minHeap);
    struct MinHeapInt* copy = copyMinHeapInt(minHeap);
    for (int cursor = 0; cursor < 32; cursor++) {
        printf("%d ", popMinHeapInt(minHeap));
    }
    printf("\n");
    printMinHeapInt(minHeap);
    printMinHeapInt(copy);
    destroyMinHeapInt(minHeap);
    destroyMinHeapInt(copy);
};
