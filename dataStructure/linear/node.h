#ifndef EternallyAscend_Cdks_NODE_H
#define EternallyAscend_Cdks_NODE_H

// Linked List Nodes for Int.

// Forward Linked List o -> o -> o -> NULL

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

// Backward Linked List NULL <- o < -o < -o

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

// Linked List NULL -> o <-> o <-> o <- NULL

struct IntNode {
    struct IntNode* last;
    struct IntNode* next;
    int value;
};

struct IntNode* generateIntNode(int value);

struct IntNode* combineFromFrontIntNode(struct IntNode* front, int value);

struct IntNode* combineFromBackIntNode(struct IntNode* back, int value);

struct IntNode* insertIntNode(struct IntNode* left, struct IntNode* right, int value);

// Unsafe Method if 'node' isn't isolated or on the edge. It will divide this linked list into two pieces at 'node'.
void destroySingleIntNode(struct IntNode* node);

// Unsafe Method if 'head' isn't the Head of Linked List. It will divide linked list into two pieces at 'head'.
struct IntNode* destroySingleFromFront(struct IntNode* head);

// Unsafe Method if 'tail' isn't the Tail of Linked List. It will divide linked list into two pieces at 'tail'.
struct IntNode* destroySingleFromBack(struct IntNode* tail);

void destroyWholeIntNode(struct IntNode* node);

// TODO Add Reverse Linked List.

// TODO Add several basic method for linked list. Such as getLength, insert and so on.

#endif
