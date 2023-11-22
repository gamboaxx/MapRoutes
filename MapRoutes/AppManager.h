#pragma once
#include "Map.h"
#include "InputHandler.h"
#include <SFML/Graphics.hpp>

class ApplicationManager {
public:
    // Constructor
    ApplicationManager(const char* imagePath);

    // Public methods
    void handleButtonClick(const std::string& buttonName);
    void run();
    sf::Color getColorFromButton(const std::string& buttonName);

    Map mapDisplay; // Instance of MapDisplay

    bool isAddingRoute;

private:
    // Private members
    InputHandler inputHandler;
    sf::RenderWindow window;
    sf::RenderWindow window2;
};
