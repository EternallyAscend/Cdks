#include <stdio.h>
#include <stdlib.h>

#include "quickSort.h"

void quickSortPointerInt(int* data, unsigned long long int length) {
    return quickSortPointerCoreInt(data, 0, length - 1);
};

int* quickSortPointerCopyInt(int* data, unsigned long long int length) {
    if (NULL == data) {
        return NULL;
    }
    int* copy = (int*)malloc(sizeof(int) * length);
    for (unsigned long long int i = 0; i < length; i++) {
        copy[i] = data[i];
    }
    quickSortPointerCoreInt(copy, 0, length - 1);
    return copy;
};

void quickSortPointerCoreInt(int* data, unsigned long long int left, unsigned long long int right) {
    if (left >= right) {
        return;
    }
    int flag = data[left];
    unsigned long long int l = left;
    unsigned long long int r = right;
    while (r > l) {
        for (; r > l && data[r] >= flag; r--) {}
        if (r > l) {
            data[l] = data[r];
            l++;
        }
        for (; r > l && data[l] <= flag; l++) {}
        if (r > l) {
            data[r] = data[l];
            r--;
        }
    }
    data[l] = flag;
    if (left != l) {
        quickSortPointerCoreInt(data, left, l - 1);
    }
    if (right != r) {
        quickSortPointerCoreInt(data, r + 1, right);
    }
};

void testQuickSortPointerInt() {
    int size = 128;
    unsigned long long int length = 128;
    int* ascend = (int*)malloc(sizeof(int) * size);
    int* descend = (int*)malloc(sizeof(int) * size);
    for (unsigned long long int i = 0; i < size; i++) {
        ascend[i] = i;
        descend[i] = size - i;
    }
    quickSortPointerInt(ascend, length);
    for (unsigned long long int i = 0; i < size; i++) {
        printf("%d ", ascend[i]);
    }
    printf("\n");
    int* copy = quickSortPointerCopyInt(descend, length);
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
