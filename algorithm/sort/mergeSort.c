#include <stdio.h>
#include <stdlib.h>

#include "mergeSort.h"

void mergeSortPointerInt(int* data, unsigned long long int length) {
    mergeSortPointerCoreInt(data, 0, length);
};

int* mergeSortPointerCopyInt(int* data, unsigned long long int length) {
    int* copy = (int*)malloc(sizeof(int) * length);
    for (unsigned long long int cursor = 0; cursor < length; cursor++) {
        copy[cursor] = data[cursor];
    }
    mergeSortPointerInt(copy, length);
    return copy;
};

void mergeSortPointerCoreInt(int* data, unsigned long long int left, unsigned long long int right) {
    if ((left + 1) >= right) {
        return;
    }
    unsigned long long int middle =  right - left;
    middle = middle >> 1;
    middle = left + middle;
    mergeSortPointerCoreInt(data, left, middle);
    mergeSortPointerCoreInt(data, middle, right);
    unsigned long long int tempSize = right - left;
    int* temp = (int*)malloc(sizeof(int) * tempSize);
    unsigned long long int cursor = 0;
    unsigned long long int lc = left;
    unsigned long long int rc = middle;
    while (lc != middle && rc != right) {
        int cache = data[lc];
        if (data[lc] > data[rc]) {
            cache = data[rc++];
        }
        else {
            lc++;
        }
        temp[cursor++] = cache;
    }
    while (lc < middle) {
        temp[cursor++] = data[lc++];
    }
    while (rc < right) {
        temp[cursor++] = data[rc++];
    }
    cursor = 0;
    for (; cursor < tempSize; cursor++) {
        data[left + cursor] = temp[cursor];
    }
    free(temp);
};

void testMergeSortPointerInt() {
    int size = 128;
    unsigned long long int length = 128;
    int* ascend = (int*)malloc(sizeof(int) * size);
    int* descend = (int*)malloc(sizeof(int) * size);
    for (unsigned long long int i = 0; i < size; i++) {
        ascend[i] = i;
        descend[i] = size - i;
    }
    mergeSortPointerInt(ascend, length);
    for (unsigned long long int i = 0; i < size; i++) {
        printf("%d ", ascend[i]);
    }
    printf("\n");
    int* copy = mergeSortPointerCopyInt(descend, length);
    
    for (unsigned long long int i = 0; i < size; i++) {
        printf("%d ", descend[i]);
    }
    printf("\n");
    for (unsigned long long int i = 0; i < size; i++) {
        printf("%d ", copy[i]);
    }
    printf("\n");
    free(ascend);
    free(descend);
    free(copy);
};

void mergeSortPointer(void** data, int(greaterThan(void*, void*)), void(*assign)(void**, void*), unsigned long long int length) {
    mergeSortPointerCore(data, greaterThan, assign, 0, length);
};

void** mergeSortPointerCopy(void** data, int(greaterThan(void*, void*)), void(*assign)(void**, void*), unsigned long long int length) {
    void** copy = (void**)malloc(sizeof(void*) * length);
    // for (unsigned long long int i = 0; i < length; i++) {
    //     printf("%lld %d\n", i, (int)data[i]);
    // }
    // system("pause");
    for (unsigned long long int i = 0; i < length; i++) {
        assign(&(copy[i]), data[i]);
    }
    mergeSortPointerCore(copy, greaterThan, assign, 0, length);
    return copy;
};

void mergeSortPointerCore(void** data, int(greaterThan(void*, void*)), void(*assign)(void**, void*), unsigned long long int left, unsigned long long int right) {
    if ((left + 1) >= right) {
        return;
    }
    unsigned long long int middle = right - left;
    middle = middle >> 1;
    middle += left;
    mergeSortPointerCore(data, greaterThan, assign, left, middle);
    mergeSortPointerCore(data, greaterThan, assign, middle, right);
    unsigned long long int lc = left;
    unsigned long long int rc = middle;
    unsigned long long int tempSize = right - left;
    unsigned long long int cursor = 0;
    void** temp = (void**)malloc(sizeof(void*) * tempSize);
    void* cache;
    while (lc < middle && rc < right) {
        assign(&cache, data[lc]);
        if (greaterThan(data[lc], data[rc])) {
            assign(&cache, data[rc++]);
        }
        else {
            lc++;
        }
        assign(&(temp[cursor++]), cache);
    }
    while (lc < middle) {
        assign(&(temp[cursor++]), data[lc++]);
    }
    while (rc < right) {
        assign(&(temp[cursor++]), data[rc++]);
    }
    for (cursor = 0; cursor < tempSize; cursor++) {
        assign(&(data[left + cursor]), temp[cursor]);
    }
    free(temp);
};

int exampleGreaterThan(void* left, void* right) {
    return (int)left > (int)right;
};

void exampleAssign(void** left, void* right) {
    // printf("Before Assign %d %d\n", *(int*)left, (int)right);
    *left = (int)right;
    // printf("Assign %d %d\n", *(int*)left, (int)right);
}

void testMergeSortPointer() {
    
    // int origin = 1;
    // void* copyInt;
    // exampleAssign(&copyInt, origin);
    // printf("%d %d\n", (int)copyInt, origin);
    // copyInt = origin;
    // printf("%d %d\n", (int)copyInt, origin);
    // exit(0);

    int size = 128;
    unsigned long long int length = 128;
    void** ascend = (void**)malloc(sizeof(void*) * size);
    void** descend = (void**)malloc(sizeof(void*) * size);
    for (unsigned long long int i = 0; i < size; i++) {
        ascend[i] = i;
        descend[i] = size - i;
    }
    mergeSortPointer(ascend, exampleGreaterThan, exampleAssign, length);
    for (unsigned long long int i = 0; i < size; i++) {
        printf("%d ", ascend[i]);
    }
    printf("\n");
    void** copy = (void**)mergeSortPointerCopy(descend, exampleGreaterThan, exampleAssign, length);
    mergeSortPointer(descend, exampleGreaterThan, exampleAssign, length);
    for (unsigned long long int i = 0; i < size; i++) {
        printf("%d ", descend[i]);
    }
    printf("\n");
    for (unsigned long long int i = 0; i < size; i++) {
        printf("%d ", (int)copy[i]);
    }
    printf("\n");
    free(ascend);
    free(descend);
    free(copy);
};
