#include "InputHandler.h"

InputHandler::InputHandler() : mouseClicked(false), clickClock() {}

void InputHandler::handleInput(const sf::Event& event, sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        if (clickClock.getElapsedTime() >= clickThreshold) {
            mouseClicked = true;
            mousePosition = sf::Mouse::getPosition(window);
            clickClock.restart();
        }
    }
}

bool InputHandler::isMouseClicked() {
    if (mouseClicked) {
        mouseClicked = false;
        return true;
    }
    return false;
}

sf::Vector2i InputHandler::getMousePosition() const {
    return mousePosition;
}

void InputHandler::handleAddNode(sf::RenderWindow& window, Map& mapDisplay) {
    sf::Vector2i mousePosition = getMousePosition();
    Node* newNode = new Node(mousePosition.x, mousePosition.y);

    if (mapDisplay.getSelectedRoute() == -1) {
        std::cout << "No route selected" << std::endl;
        return;
    }
    else {
        mapDisplay.routes[mapDisplay.getSelectedRoute()].add_node(newNode, mapDisplay.getSelectedRoute());
    }
}

void InputHandler::handleDeleteNode(sf::RenderWindow& window, Map& mapDisplay) {
    sf::Vector2i mousePosition = getMousePosition();
    Node* newNode = new Node(mousePosition.x, mousePosition.y);

    if (mapDisplay.getSelectedRoute() == -1) {
        std::cout << "No route selected" << std::endl;
        return;
    }
    else {
        mapDisplay.routes[mapDisplay.getSelectedRoute()].delete_node(newNode);
    }
}