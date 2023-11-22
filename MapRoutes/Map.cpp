#include "Map.h"

using namespace std;

Map::Map(const char* imagePath)
    : mapTexture(), mapSprite(), selected_route(-1), editMode(false) {
    if (!mapTexture.loadFromFile(imagePath)){
        cerr<< "Error loading map image" <<imagePath<< endl;
    }
    mapSprite.setTexture(mapTexture);

    float scale = std::min(1100.0f / mapSprite.getLocalBounds().width, 824.0f / mapSprite.getLocalBounds().height);
    mapSprite.setScale(scale + 0.001, scale);

    loadButtonTextures();
    configureButtonSprites();

    redCircle.setRadius(20);
    redCircle.setFillColor(sf::Color::Red);
    redCircle.setPosition(875, 745);

    blueCircle.setRadius(20);
    blueCircle.setFillColor(sf::Color::Blue);
    blueCircle.setPosition(935, 745);

    greenCircle.setRadius(20);
    greenCircle.setFillColor(sf::Color::Green);
    greenCircle.setPosition(995, 745);
}

void Map::displayMap(sf::RenderWindow& window) {
    // display each <route> by calling .draw on route
    window.draw(mapSprite);
    currentRoute.draw(window);
    drawAllRoutes(window);
}

void Map::loadButtonTextures() {
    try {
        if (!textureAdd.loadFromFile("./resources/ButtonAdd.jpg")) {
            throw std::runtime_error("Failed to load ButtonAdd texture");
        }
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        if (!textureDelete.loadFromFile("./resources/ButtonDelete.jpg")) {
            throw std::runtime_error("Failed to load ButtonDelete texture");
        }
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        if (!textureEdit.loadFromFile("./resources/ButtonEdit.jpg")) {
            throw std::runtime_error("Failed to load ButtonEdit texture");
        }
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        if (!textureSave.loadFromFile("./resources/ButtonSave.jpg")) {
            throw std::runtime_error("Failed to load ButtonSave texture");
        }
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        if (!textureShowHide.loadFromFile("./resources/ButtonShow_Hide.jpg")) {
            throw std::runtime_error("Failed to load ButtonShowHide texture");
        }
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        if (!textureUpload.loadFromFile("./resources/ButtonUpload.jpg")) {
            throw std::runtime_error("Failed to load ButtonUpload texture");
        }
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

void Map::configureButtonSprites() {
    float buttonScale = 0.2f;

    spriteAdd.setTexture(textureAdd);
    spriteDelete.setTexture(textureDelete);
    spriteEdit.setTexture(textureEdit);
    spriteSave.setTexture(textureSave);
    spriteShowHide.setTexture(textureShowHide);
    spriteUpload.setTexture(textureUpload);

    spriteAdd.setScale(buttonScale + 0.001, buttonScale + 0.001);
    spriteDelete.setScale(buttonScale, buttonScale);
    spriteEdit.setScale(buttonScale - 0.01, buttonScale - 0.001);
    spriteSave.setScale(buttonScale, buttonScale);
    spriteShowHide.setScale(buttonScale, buttonScale);
    spriteUpload.setScale(buttonScale, buttonScale);

    spriteAdd.setPosition(855, 170);
    spriteDelete.setPosition(834, 270);
    spriteEdit.setPosition(834, 220);
    spriteSave.setPosition(834, 520);
    spriteShowHide.setPosition(840, 370);
    spriteUpload.setPosition(831, 560);
}

void Map::displayButtons(sf::RenderWindow& window) {
    window.draw(spriteAdd);
    window.draw(spriteDelete);
    window.draw(spriteEdit);
    window.draw(spriteSave);
    window.draw(spriteShowHide);
    window.draw(spriteUpload);

    window.draw(redCircle);
    window.draw(blueCircle);
    window.draw(greenCircle);

    // debug routes printing
}


std::string Map::getClickedButton(sf::Vector2i mousePosition) {
    if (spriteAdd.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
        return "AddRoute";
    }
    else if (spriteDelete.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
        return "DeleteRoute";
    }
    else if (spriteEdit.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
        return "Edit";
    }
    else if (spriteSave.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
        return "Save";
    }
    else if (spriteShowHide.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
        return "ShowHide";
    }
    else if (spriteUpload.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
        return "Upload";
    }
    else if (redCircle.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
        return "Rojo";
    }
    else if (blueCircle.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
        return "Azul";
    }
    else if (greenCircle.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
        return "Verde";
    }
    return "";
}

void Map::addRoute() {
    if (selected_route != -1) {
        Route newRoute;
        routes.push_back(newRoute);

        currentRoute = routes[selected_route];
        selected_route = routes.size() - 1;
    }
    else if (selected_route == -1) {
        Route newRoute;
        routes.push_back(newRoute);

        selected_route = routes.size() - 1;
    }
    else {
        std::cout << "No route selected" << std::endl;
    }

    std::cout << "Selected Route: " << selected_route << std::endl;
}

void Map::deleteRoute() {
    routes.erase(routes.begin() + selected_route);
    selected_route = selected_route - 1;

    std::cout << "Selected Route: " << selected_route << std::endl;
}

Route& Map::getCurrentRoute() {
    return currentRoute;
}

int Map::getSelectedRoute() const {
    return selected_route;
}

void Map::showHideRoute() {
    if (selected_route != -1) {
        routes[selected_route].show_hide();
    }
    else {
        std::cout << "No route selected" << std::endl;
    }
}

void Map::drawAllRoutes(sf::RenderWindow& window) {
    for (int i = 0; i < routes.size(); i++) {
        routes[i].draw(window);
    }
}

void Map::save_routes() {
    ofstream file("data/routes.txt");
    if (!file.is_open()) {
        cerr << "Error." << endl;
        return;
    }

    for (int i = 0; i < routes.size(); ++i) {
        file << "Color: " << routes[i].get_color().toInteger() << endl;

        Node* current = routes[i].get_start_node();
        while (current != nullptr) {
            file << "Node: " << current->get_x() << " " << current->get_y() << endl;
            current = current->get_next();
        }

        file << endl;
    }

    file.close();
}

void Map::load_routes() {
    ifstream file("data/routes.txt");
    if (!file.is_open()) {
        cerr << "EL ARCHIVO ESPECIFICADO NO EXISTE" << endl;
        return;
    }

    string line;
    Route currentRoute;
    Color currentColor;

    while (getline(file, line)) {
        if (line.find("Color:") != string::npos) {
            currentColor = Color(stoul(line.substr(line.find(" ") + 1)));
        }
        else if (line.find("Node:") != string::npos) {
            size_t spacePos = line.find(" ");
            int x = stoi(line.substr(spacePos + 1, line.find(" ", spacePos + 1)));
            int y = stoi(line.substr(line.find(" ", spacePos + 1) + 1));
            currentRoute.add_node(new Node(x, y), selected_route);
        }
        else if (line.empty()) {
            currentRoute.changeRouteColor(currentColor);
            routes.push_back(currentRoute);

            currentRoute = Route(); // RESETS THE ROUTE
        }
    }

    currentRoute.changeRouteColor(currentColor);
    routes.push_back(currentRoute);
}