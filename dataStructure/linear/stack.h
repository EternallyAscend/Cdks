#ifndef EternallyAscend_Cdks_STACK_H
#define EternallyAscend_Cdks_STACK_H

#include "node.h"

// Array Version Stack for Int.

struct StackInt {
    int tail;
    unsigned long long int size;
    int* stack;
};

struct StackInt* generateWithSizeStackInt(unsigned long long int size);

struct StackInt* generateStackInt();

void destroyStackInt(struct StackInt* stack);

int isNullStackInt(struct StackInt* stack);

int isEmptyStackInt(struct StackInt* stack);

unsigned long long int getLengthStackInt(struct StackInt* stack);

void extendStackInt(struct StackInt* stack);

int pushStackInt(struct StackInt* stack, int value);

int popStackInt(struct StackInt* stack);

void printStackInt(struct StackInt* stack);

struct StackInt* copyStackInt(struct StackInt* stack);

void testStackInt();

// Linked Version Stack for Int.

struct LinkedStackInt {
    struct BackwardIntNode* head;
    struct BackwardIntNode* tail;
};

struct LinkedStackInt* generateLinkedStackInt();

void destroyLinkedStackInt(struct LinkedStackInt* stack);

int isNullLinkedStackInt(struct LinkedStackInt* stack);

int isEmptyLinkedStackInt(struct LinkedStackInt* stack);

unsigned long long int getLengthLinkedStackInt(struct LinkedStackInt* stack);

int pushLinkedStackInt(struct LinkedStackInt* stack, int value);

int popLinkedStackInt(struct LinkedStackInt* stack);

void printLinkedStackInt(struct LinkedStackInt* stack);

struct LinkedStackInt* copyLinkedStackInt(struct LinkedStackInt* stack);

void testLinkedStackInt();

#endif
