#ifndef EternallyAscend_Cdks_QUEUE_H
#define EternallyAscend_Cdks_QUEUE_H

#include "node.h"

// Array Version Queue for Int.

struct QueueInt {
    unsigned long long int head;
    unsigned long long int tail;
    unsigned long long int size;
    int* queue;
};

struct QueueInt* generateWithSizeQueueInt(unsigned long long int size);

struct QueueInt* generateQueueInt();

void destroyQueueInt(struct QueueInt* queue);

int isNullQueueInt(struct QueueInt* queue);

int isEmptyQueueInt(struct QueueInt* queue);

void extendQueueInt(struct QueueInt* queue);

int pushQueueInt(struct QueueInt* queue, int value);

int popQueueInt(struct QueueInt* queue);

void printQueueInt(struct QueueInt* queue);

struct QueueInt* copyQueueInt(struct QueueInt* queue);

void testQueueInt();

// Linked Version Queue for Int.

struct LinkedQueueInt {
    struct ForwardIntNode* head;
    struct ForwardIntNode* tail;
};

struct LinkedQueueInt* generateLinkedQueueInt();

void destroyLinkedQueueInt(struct LinkedQueueInt* queue);

int isNullLinkedQueueInt(struct LinkedQueueInt* queue);

int isEmptyLinkedQueueInt(struct LinkedQueueInt* queue);

int pushLinkedQueueInt(struct LinkedQueueInt* queue, int value);

int popLinkedQueueInt(struct LinkedQueueInt* queue);

void printLinkedQueueInt(struct LinkedQueueInt* queue);

struct LinkedQueueInt* copyLinkedQueueInt(struct LinkedQueueInt* queue);

void testLinkedQueueInt();

#endif
