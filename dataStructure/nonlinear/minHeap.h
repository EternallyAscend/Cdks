#ifndef EternallyAscend_Cdks_MINHEAP_H
#define EtenrallyAscend_Cdks_MINHEAP_H

// Array Version MinHeap for Int.

// TODO Using greaterThan function instead of '<' operator.

struct MinHeapInt {
    unsigned long long int tail;
    unsigned long long int size;
    int* minHeap;
};

struct MinHeapInt* generateWithSizeMinHeapInt(unsigned long long int size);

struct MinHeapInt* generateMinHeapInt();

void destroyMinHeapInt(struct MinHeapInt* minHeap);

int isNullMinHeapInt(struct MinHeapInt* minHeap);

int isEmptyMinHeapInt(struct MinHeapInt* minHeap);

unsigned long long int getLengthMinHeapInt(struct MinHeapInt* minHeap);

void extendMinHeapInt(struct MinHeapInt* minHeap);

int pushMinHeapInt(struct MinHeapInt* minHeap, int value);

int popMinHeapInt(struct MinHeapInt* minHeap)
;

void printMinHeapInt(struct MinHeapInt* minHeap);

struct MinHeapInt* copyMinHeapInt(struct MinHeapInt* minHeap);

void testMinHeapInt();

#endif
