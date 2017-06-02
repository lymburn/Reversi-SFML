//
//  game.cpp
//  Reversi
//
//  Created by Eugene Lu on 2017-06-02.
//  Copyright © 2017 Eugene Lu. All rights reserved.
//

#include "game.hpp"

void Game::run() {
    //Creates initial window
    sf::RenderWindow window(sf::VideoMode(1200, 1200), "Reversi");
    
    window.setFramerateLimit(60);
    
    //Sets the icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    //Load the textures and create background
    loadTexturesAndBackground();
    
    // Start the game loop
    while (window.isOpen())
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }
        
        // Clear screen
        window.clear();
        
        //Draw the board
        window.draw(background);
        
        Piece gamePiece;
        pieceColors pieceColor = pieceColors::black;
        gamePiece.setTextureAndColor(pieceColor);
        gamePiece.addTexture(gamePiece.tile);
        
        window.draw(gamePiece.tile);
        
        // Update the window
        window.display();
    }
}

void Game::loadTexturesAndBackground() {
    //Loads the board and game pieces textures
    textureLoader.loadBoardTexture();
    //Creates the board background
    createBackground(background,textureLoader.boardTexture);

}
