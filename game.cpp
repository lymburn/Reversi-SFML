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
    
    //Set up initial board pieces
    const float BOARD_SQUARE_LENGTH = 151.06;
    const float CENTRE_OFFSET = 11.21;
    const float RADIUS = 61.0;
    
    Piece initialVisiblePiecesArray[4];
    setupVisiblePieces(initialVisiblePiecesArray, 4,BOARD_SQUARE_LENGTH, CENTRE_OFFSET);
    
    Piece initialTransparentPiecesArray[8][8];
    setupTransparentPieces(initialTransparentPiecesArray, 8, BOARD_SQUARE_LENGTH, CENTRE_OFFSET);
    
    // Start the game loop
    while (window.isOpen())
    {
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
        
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        
        //Loads the icon
        loadIcon(window);
        
        //Load the textures and create background
        loadTexturesAndBackground(window);
        
        //Draw the initial 4 visible pieces
        for (int i = 0; i < 4; i++) {
            window.draw(initialVisiblePiecesArray[i].tile);
        }

        //Draw the board of invisible pieces
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                window.draw(initialTransparentPiecesArray[i][j].tile);
            }
        }
        
        int xCoord, yCoord;
        
        if (mousePos.x/BOARD_SQUARE_LENGTH>0 && mousePos.y/BOARD_SQUARE_LENGTH < 8 && mousePos.y/BOARD_SQUARE_LENGTH>0 && mousePos.y/BOARD_SQUARE_LENGTH < 8) {
            xCoord = (int)mousePos.x/BOARD_SQUARE_LENGTH;
            yCoord = (int)mousePos.y/BOARD_SQUARE_LENGTH;
        }
        
        if (mousePos.x > xCoord*BOARD_SQUARE_LENGTH && mousePos.x < ((xCoord*BOARD_SQUARE_LENGTH)+BOARD_SQUARE_LENGTH) && mousePos.y > yCoord*BOARD_SQUARE_LENGTH && mousePos.y < ((yCoord*BOARD_SQUARE_LENGTH)+BOARD_SQUARE_LENGTH) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            
            initialTransparentPiecesArray[xCoord][yCoord].tile.setColor(sf::Color(0,0,0,255));
        }

        // Update the window
        window.display();
    }
}

void Game::loadTexturesAndBackground(sf::RenderWindow& window) {
    //Loads the board texture
    textureLoader.loadBoardTexture();
    //Creates and draw the board background
    createBackground(background,textureLoader.boardTexture);
    window.draw(background);

}

void Game::loadIcon(sf::RenderWindow& window) {
    //Sets the icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

