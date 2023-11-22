#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "Route.h"
#include <vector>

class Map {
public:
    // Constructor
    Map(const char* imagePath);

    // Public methods
    void displayMap(sf::RenderWindow& window);
    void loadButtonTextures();
    void configureButtonSprites();
    void displayButtons(sf::RenderWindow& window);
    void addRoute();
    void deleteRoute();
    std::string getClickedButton(sf::Vector2i mousePosition);
    Route& getCurrentRoute();
    int getSelectedRoute() const;
    void drawAllRoutes(sf::RenderWindow& window);
    void showHideRoute();
    void save_routes();
    void load_routes();

    std::vector<Route> routes;
    int selected_route;
    bool editMode;

private:
    // Private members
    sf::Texture mapTexture;
    sf::Sprite mapSprite;
    sf::Texture textureAdd, textureDelete, textureEdit, textureSave, textureShowHide, textureUpload;
    sf::Sprite spriteAdd, spriteDelete, spriteEdit, spriteSave, spriteShowHide, spriteUpload;
    CircleShape redCircle;
    CircleShape blueCircle;
    CircleShape greenCircle;
    Route currentRoute;
};


