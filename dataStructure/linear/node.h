#ifndef EternallyAscend_Cdks_NODE_H
#define EternallyAscend_Cdks_NODE_H

// Linked List Nodes for Int.

struct ForwardIntNode {
    struct ForwardIntNode* next;
    int value;
};

struct ForwardIntNode* generateForwardIntNode(int value);

struct ForwardIntNode* combineNewForwardIntNode(struct ForwardIntNode* forward, int value);

// Unsafe Method. It won't modify previous node's next pointer.
void destroySingleForwardIntNode(struct ForwardIntNode* node);

// Unsafe Method if 'head' isn't the Head of Linked List. It won't modify previous node's next pointer.
struct ForwardIntNode* destroyFirstForwardIntNode(struct ForwardIntNode* head);

// Unsafe Method if 'head' isn't the Head of Linked List. It won't modify previous node's next pointer.
void destroyWholeForwardIntNode(struct ForwardIntNode* head);

// TODO Add Reverse Linked List.

struct BackwardIntNode {
    struct BackwardIntNode* last;
    int value;
};

struct BackwardIntNode* generateBackwardIntNode(int value);

struct BackwardIntNode* combineBackwardIntNode(struct BackwardIntNode* backward, int value);

// Unsafe Method. It won't modify next node's previous pointer.
void destroySingleBackwardIntNode(struct BackwardIntNode* node);

// Unsafe Method if 'tail' isn't the Tail of Linked List. It won't modify next node's previous pointer.
struct BackwardIntNode* destroyLastBackwardIntNode(struct BackwardIntNode* tail);

// Unsafe Method if 'tail' isn't the Tail of Linked List. It won't modify next node's previous pointer.
void destroyWholeBackwardIntNode(struct BackwardIntNode* tail);

// TODO Add Reverse Linked List.

struct IntNode {
    struct IntNode* last;
    struct IntNode* next;
    int value;
};

struct IntNode* generateIntNode(int value);

// TODO Add Reverse Linked List.

#endif
