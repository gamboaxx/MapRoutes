#include "Route.h"
#include <iostream>

Route::Route() : head(nullptr), tail(nullptr), color(Color::Black) {}

Route::Route(Node* head, Node* tail) : head(head), tail(tail), color(Color::White) {}

void Route::set_start_node(Node* head) {
    this->head = head;
}

Node* Route::get_start_node() {
    return head;
}

void Route::set_end_node(Node* tail) {
    this->tail = tail;
}

Node* Route::get_end_node() {
    return tail;
}

void Route::add_node(Node* node, int route_id) {
    if (route_id == -1) {
        std::cout << "No route selected" << std::endl;
        return;
    }

    std::cout << "Node added to route " << route_id << ": " << node->get_x() << " " << node->get_y() << std::endl;

    if (head == nullptr) {
        head = node;
        tail = node;
    }
    else {
        tail->set_next(node);
        node->set_prev(tail);
        tail = node;
    }
}

// Deletes a node if the click is within 5 pixels of the node
void Route::delete_node(Node* node) {
    // If there are no nodes to delete
    if (head == nullptr) {
        std::cout << "No nodes to delete" << std::endl;
        return;
    }

    // If there is at least one node
    Node* current = head;
    while (current != nullptr) {
        // If the click is within 5 pixels of the node
        if (node->get_x() >= current->get_x() - 10 && node->get_x() <= current->get_x() + 10 &&
            node->get_y() >= current->get_y() - 10 && node->get_y() <= current->get_y() + 10) {
            std::cout << "Node deleted: " << current->get_x() << " " << current->get_y() << std::endl;

            // If the node is the only node
            if (current == head && current == tail) {
                head = nullptr;
                tail = nullptr;
            }
            // If the node is the head
            else if (current == head) {
                head = head->get_next();
                head->set_prev(nullptr);
            }
            // If the node is the tail
            else if (current == tail) {
                tail = tail->get_prev();
                tail->set_next(nullptr);
            }
            // If the node is in the middle
            else {
                current->get_prev()->set_next(current->get_next());
                current->get_next()->set_prev(current->get_prev());
            }

            // Delete current;
            // Note: Commented out for now; consider using 'delete current;' if necessary
            return;
        }
        current = current->get_next();
    }

    std::cout << "Node not found for deletion" << std::endl;
}

void Route::draw(RenderWindow& window) {
    if (!is_drawable) return;

    Node* current = head;
    while (current != nullptr) {
        CircleShape circle(10);
        circle.setFillColor(color);
        circle.setPosition(current->get_x() - 10, current->get_y() - 10);

        if (current->get_next() != nullptr) {
            Vertex line[] = {
                Vertex(Vector2f(current->get_x(), current->get_y())),
                Vertex(Vector2f(current->get_next()->get_x(), current->get_next()->get_y()))
            };
            window.draw(line, 2, Lines);
        }

        window.draw(circle);
        current = current->get_next();
    }
}

void Route::show_hide() {
    is_drawable = !is_drawable;
}

void Route::changeRouteColor(Color color) {
    this->color = color;
}

Color Route::get_color() {
    return color;
}