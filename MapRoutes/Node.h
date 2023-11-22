#pragma once

class Node {
private:
    int x;
    int y;
    Node* next;
    Node* prev;

public:
    // Constructors
    Node(int x, int y);
    Node();

    // Getter methods
    int get_x();
    int get_y();
    Node* get_next();
    Node* get_prev();

    // Setter methods
    void set_next(Node* next_node);
    void set_prev(Node* prev_node);
};
