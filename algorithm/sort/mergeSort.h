#ifndef EternallyAscend_Cdks_MERGESORT_H
#define EternallyAscend_Cdks_MERGESORT_H

void mergeSortPointerInt(int* data, unsigned long long int length);

int* mergeSortPointerCopyInt(int* data, unsigned long long int length);

void mergeSortPointerCoreInt(int* data, unsigned long long int left, unsigned long long int right);

void testMergeSortPointerInt();

void mergeSortPointer(void* data, int(*greaterThan(void*, void*)), void(*assign)(void*, void*), unsigned long long int typeSize, unsigned long long int length);

void* mergeSortPointerCopy(void* data, int(*greaterThan(void*, void*)), void(*assign)(void*, void*), unsigned long long int length, unsigned long long int typeSize);

void mergeSortPointerCore(void* data, int(*greaterThan(void*, void*)), void(*assign)(void*, void*), unsigned long long int typeSize, unsigned long long int left, unsigned long long int right);

void testMergeSortPointer();

#endif
