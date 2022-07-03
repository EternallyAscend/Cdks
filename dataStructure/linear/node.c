#include <stdlib.h>

#include "node.h"

// Linked List Nodes for Int.

struct ForwardIntNode* generateForwardIntNode(int value) {
    struct ForwardIntNode* pointer = (struct ForwardIntNode*)malloc(sizeof(struct ForwardIntNode));
    pointer->next = NULL;
    pointer->value = value;
    return pointer;
};

struct ForwardIntNode* combineNewForwardIntNode(struct ForwardIntNode* backward, int value) {
    struct ForwardIntNode* pointer = generateForwardIntNode(value);
    if (NULL != backward) {
        backward->next = pointer;
    }
    return pointer;
};

// Unsafe Method. It won't modify previous node's next pointer.
void destroySingleForwardIntNode(struct ForwardIntNode* node) {
    free(node);
};

// Unsafe Method if 'head' isn't the Head of Linked List. It won't modify previous node's next pointer.
struct ForwardIntNode* destroyFirstForwardIntNode(struct ForwardIntNode* head) {
    if (NULL == head) {
        return NULL;
    }
    struct ForwardIntNode* newHead = head->next;
    destroySingleForwardIntNode(head);
    return newHead;
};

// Unsafe Method if 'head' isn't the Head of Linked List. It won't modify previous node's next pointer.
void destroyWholeForwardIntNode(struct ForwardIntNode* head) {
    struct ForwardIntNode* pointer = head;
    while(NULL != head) {
        head = head->next;
        destroySingleForwardIntNode(pointer);
        pointer = head;
    }
};

struct BackwardIntNode* generateBackwardIntNode(int value) {
    struct BackwardIntNode* pointer = (struct BackwardIntNode*)malloc(sizeof(struct BackwardIntNode));
    pointer->last = NULL;
    pointer->value = value;
    return pointer;
};

struct BackwardIntNode* combineBackwardIntNode(struct BackwardIntNode* backward, int value) {
    struct BackwardIntNode* pointer = generateBackwardIntNode(value);
    pointer->last = backward;
    return pointer;
};

// Unsafe Method. It won't modify next node's previous pointer.
void destroySingleBackwardIntNode(struct BackwardIntNode* node) {
    free(node);
};

// Unsafe Method if 'tail' isn't the Tail of Linked List. It won't modify next node's previous pointer.
struct BackwardIntNode* destroyLastBackwardIntNode(struct BackwardIntNode* tail) {
    struct BackwardIntNode* pointer = tail->last;
    destroySingleBackwardIntNode(tail);
    return pointer;
};

// Unsafe Method if 'tail' isn't the Tail of Linked List. It won't modify next node's previous pointer.
void destroyWholeBackwardIntNode(struct BackwardIntNode* tail) {
    struct BackwardIntNode* pointer = tail;
    while(NULL != tail) {
        tail = tail->last;
        destroyLastBackwardIntNode(pointer);
        pointer = tail;
    }
};
