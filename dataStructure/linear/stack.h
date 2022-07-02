#ifndef EternallyAscend_Cdks_STACK_H
#define EternallyAscend_Cdks_STACK_H

struct StackInt {
    int tail;
    int size;
    int* stack;
};

struct StackInt* generateWithSizeStackInt(unsigned int size) {};

struct StackInt* generateStackInt() {};

void destroyStackInt(struct StackInt* pointer) {};

int isNullStackInt(struct StackInt* stack) {};

int isEmptyStackInt(struct StackInt* stack) {};

void extendStackInt(struct StackInt* stack) {};

int pushStackInt(struct StackInt* stack, int value) {};

int popStackInt(struct StackInt* stack) {};

void printStackInt(struct StackInt* stack) {};

struct StackInt* copyStackInt(struct StackInt* stack) {};

#endif
