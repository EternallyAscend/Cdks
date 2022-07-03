#include <stdlib.h>

#include "queue.h"
#include "../../error.h"

struct QueueInt* generateWithSizeQueueInt(int size) {
    struct QueueInt* pointer = (struct QueueInt*)malloc(sizeof(struct QueueInt));
    pointer->head = 0;
    pointer->tail = 0;
    pointer->size = size;
    pointer->queue = (int*)malloc(sizeof(int) * size);
    return pointer;
};

struct QueueInt* generateQueueInt() {
    return generateWithSizeQueueInt(16);
};

void destroyQueueInt(struct QueueInt* queue) {
    if (NULL == queue) {
        return;
    }
    if (NULL != queue->queue) {
        free(queue->queue);
    }
    free(queue);
};

int isNullQueueInt(struct QueueInt* queue) {
    if (NULL == queue) {
        return ErrorEmptyPointer;
    }
    if (NULL == queue->queue) {
        return ErrorEmptyPointer;
    }
    return False;
};

int isEmptyQueueInt(struct QueueInt* queue) {
    int error = isNullQueueInt(queue);
    if (error) {
        return error;
    }
    if (0 == queue->tail) {
        return ErrorEmptyPointer;
    }
    return False;
};

void extendQueueInt(struct QueueInt* queue) {
    if (isNullQueueInt(queue)) {
        return;
    }
    int newSize = queue->size;
    newSize = newSize << 1;
    int* newQueue = (int*)malloc(sizeof(int) * newSize);
    int cursor = 0;
    // for (; cursor < queue->size; cursor++) {
    //     newQueue[cursor] = queue->queue[(cursor + queue->head) % queue->size];
    // }
    int flag = queue->head;
    if (queue->head < queue->tail) {
        for (; flag < queue->tail; cursor++, flag++) {
            newQueue[cursor] = queue->queue[flag];
        }
    }
    else {
        for (; flag < queue->size; cursor++, flag++) {
            newQueue[cursor] = queue->queue[flag];
        }
        for (flag = 0; flag < queue->tail; cursor++, flag++) {
            newQueue[cursor] = queue->queue[flag];
        }
    }
    free(queue->queue);
    queue->queue = newQueue;
    queue->size = newSize;
    queue->head = 0;
    queue->tail = cursor;
};

int pushQueueInt(struct QueueInt* queue, int value) {
    int error = isNullQueueInt(queue);
    if (error) {
        return error;
    }
    if (queue->tail == queue->head) {
        if (0 != queue->head) {
            extendQueueInt(queue);
        }
    }
    else if (queue->tail == queue->size) {
        if (0 == queue->head) {
            extendQueueInt(queue);
        }
        else {
            queue->tail = 0;
        }
    }
    queue->queue[queue->tail++] = value;
    return True;
};

int popQueueInt(struct QueueInt* queue) {
    int error = isEmptyQueueInt(queue);
    if (error) {
        return error;
    }
    int value;
    if (queue->head < queue->tail) {
        value = queue->queue[queue->head++];
        if (queue->head == queue->tail) {
            queue->head = queue->tail = 0;
        }
    }
    else {
        value = queue->queue[queue->head++];
        if (queue->head == queue->size) {
            queue->head = 0;
        }
    }
    return value;
};

void printQueueInt(struct QueueInt* queue) {
    int length = queue->tail - queue->head;
    int cursor = queue->head;
    if (queue->head < queue->tail) {
        for (; cursor < queue->tail; cursor++) {
            printf("%d ", queue->queue[cursor]);
        }
    }
    else {
        length += queue->size;
        for (; cursor < queue->size; cursor++) {
            printf("%d ", queue->queue[cursor]);
        }
        for (cursor = 0; cursor < queue->tail; cursor++) {
            printf("%d ", queue->queue[cursor]);
        }
    }
    printf("\nQueue Int: length %d, size %d.\n", length, queue->size);
};

struct QueueInt* copyQueueInt(struct QueueInt* queue) {
    struct QueueInt* copy = (struct QueueInt*)malloc(sizeof(struct QueueInt));
    copy->head = 0;
    copy->tail = 0;
    copy->size = queue->size;
    copy->queue = (int*)malloc(sizeof(int) * copy->size);
    int cursor = 0;
    int flag = queue->head;
    if (queue->head < queue->tail) {
        for (; flag < queue->tail; cursor++, flag++) {
            copy->queue[cursor] = queue->queue[flag];
        }
    }
    else {
        for (; flag < queue->size; cursor++, flag++) {
            copy->queue[cursor] = queue->queue[flag];
        }
        for (flag = 0; flag < queue->tail; cursor++, flag++) {
            copy->queue[cursor] = queue->queue[flag];
        }
    }
    return copy;
};
