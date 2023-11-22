#include "Node.h"

Node::Node(int x, int y) : x(x), y(y), next(nullptr), prev(nullptr) {}

Node::Node() {}

int Node::get_x() {
    return x;
}

int Node::get_y() {
    return y;
}

Node* Node::get_next() {
    return next;
}


Node* Node::get_prev() {
    return prev;
}

void Node::set_next(Node* nextNode) {
    next = nextNode;
}

void Node::set_prev(Node* prevNode) {
    prev = prevNode;
}