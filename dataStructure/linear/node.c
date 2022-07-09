#include <stdlib.h>

#include "node.h"

// Linked List Nodes for Int.

// Forward Single Linked List.

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

// Backward Single Linked List.

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

// Two-way Linked List.

struct IntNode* generateIntNode(int value) {
    struct IntNode* pointer = (struct IntNode*)malloc(sizeof(struct IntNode));
    pointer->last = NULL;
    pointer->next = NULL;
    pointer->value = value;
    return pointer;
};

struct IntNode* combineFromFrontIntNode(struct IntNode* front, int value) {
    struct IntNode* pointer = generateIntNode(value);
    if (NULL != front) {
        front->next = pointer;
        pointer->last = front;
    }
    return pointer;
};

struct IntNode* combineFromBackIntNode(struct IntNode* back, int value) {
    struct IntNode* pointer = generateIntNode(value);
    if (NULL != back) {
        back->last = pointer;
        pointer->next = back;
    }
    return pointer;
};

struct IntNode* insertIntNode(struct IntNode* left, struct IntNode* right, int value) {
    struct IntNode* pointer = generateIntNode(value);
    if (NULL != left) {
        left->next = pointer;
        pointer->last = left;
    }
    if (NULL != right) {
        right->last = pointer;
        pointer->next = right;
    }
    return pointer;
};

// Unsafe Method if 'node' isn't isolated or on the edge. It will divide this linked list into two pieces at 'node'.
void destroySingleIntNode(struct IntNode* node) {
    if (NULL != node) {
        if (NULL != node->last) {
            node->last->next = NULL;
        }
        if (NULL != node->next) {
            node->next->last = NULL;
        }
        free(node);
    }
};

// Unsafe Method if 'head' isn't the Head of Linked List. It will divide linked list into two pieces at 'head'.
struct IntNode* destroySingleFromFront(struct IntNode* head) {
    if (NULL != head) {
        struct IntNode* newHead = head->next;
        destroySingleIntNode(head);
        return newHead;
    }
    return NULL;
};

// Unsafe Method if 'tail' isn't the Tail of Linked List. It will divide linked list into two pieces at 'tail'.
struct IntNode* destroySingleFromBack(struct IntNode* tail) {
    if (NULL != tail) {
        struct IntNode* newTail = tail->last;
        destroySingleIntNode(tail);
        return newTail;
    }
    return NULL;
};

void destroyWholeIntNode(struct IntNode* node) {
    if (node != NULL) {
        struct IntNode* flag = NULL;
        struct IntNode* left = node->last;
        struct IntNode* right = node->next;
        destroySingleIntNode(node);
        while (NULL != left) {
            flag = left;
            left = left->last;
            destroySingleIntNode(flag);
        }
        while (NULL != right) {
            flag = right;
            right = right->next;
            destroySingleIntNode(flag);
        }
    }
};
