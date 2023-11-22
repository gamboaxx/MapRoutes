#pragma once

#include <SFML/Graphics.hpp>
#include "Node.h"

using namespace sf;

class Route {
private:
    Node* head;
    Node* tail;
    Color color;
    bool is_drawable;
    int route_id;

public:

    Route();
    Route(Node* head, Node* tail);

    void set_start_node(Node* head);
    Node* get_start_node();
    void set_end_node(Node* tail);
    Node* get_end_node();

    void add_node(Node* node, int selectedRoute);
    void draw(RenderWindow& window);
    void delete_node(Node* node);
    void changeRouteColor(Color color);
    void show_hide();

    Color get_color();
};