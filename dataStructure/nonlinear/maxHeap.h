#ifndef EternallyAscend_Cdks_MAXHEAP_H
#define EternallyAscend_Cdks_MAXHEAP_H

// Array Version MaxHeap for Int.

struct MaxHeapInt {
    unsigned long long int tail;
    unsigned long long int size;
    int* maxHeap;
    int(*greaterThan)(int, int);
};

struct MaxHeapInt* generateWithSizeMaxHeapInt(int(*greaterThan)(int, int), unsigned long long int size);

struct MaxHeapInt* generateMaxHeapInt(int(*greaterThan)(int, int));

void destroyMaxHeapInt(struct MaxHeapInt* maxHeap);

int isNullMaxHeapInt(struct MaxHeapInt* maxHeap);

int isEmptyMaxHeapInt(struct MaxHeapInt* maxHeap);

unsigned long long int getLengthMaxHeapInt(struct MaxHeapInt* maxHeap);

void extendMaxHeapInt(struct MaxHeapInt* maxHeap);

int pushMaxHeapInt(struct MaxHeapInt* maxHeap, int value);

int popMaxHeapInt(struct MaxHeapInt* maxHeap);

void printMaxHeapInt(struct MaxHeapInt* maxHeap);

struct MaxHeapInt* copyMaxHeapInt(struct MaxHeapInt* maxHeap);

void testMaxHeapInt();

#endif
