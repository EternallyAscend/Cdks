#ifndef EternallyAscend_Cdks_MERGESORT_H
#define EternallyAscend_Cdks_MERGESORT_H

void mergeSortPointerInt(int* data, unsigned long long int length);

int* mergeSortPointerCopyInt(int* data, unsigned long long int length);

void mergeSortPointerCoreInt(int* data, unsigned long long int left, unsigned long long int right);

void testMergeSortPointerInt();

#endif
