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
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(sf::VideoMode(1200, 1200), "Reversi");
    window.setFramerateLimit(60);
    
    //Board and piece dimensions
    const float BOARD_SQUARE_LENGTH = 151.06;
    const float CENTRE_OFFSET = 11.21;
    const float RADIUS = 61.0;
    
    float widthScale, heightScale;
    bool stop = false;
    //Variables and objects
    std::string playerColor;
    std::string opponentColor;
    int whiteScore = 2;
    int blackScore = 2;
    std::string turn = "P";
    int xCoord, yCoord;
    Piece GamePiece;
    SetupManager GameSetup;
    //Object to check positions and legal moves
    PositionChecker CheckPosition;
    InternalBoard Board;
    sf::Clock clock;
    //Player's chosen color
    playerColor = "W";
    opponentColor = GamePiece.oppositeColor(playerColor);

    
    //Initializes the 4 initial pieces
    Piece InitialVisiblePiecesArray[4];
    GameSetup.setupVisiblePieces(InitialVisiblePiecesArray, 4,BOARD_SQUARE_LENGTH, CENTRE_OFFSET);
    
    //Initializes the rest of the transparent pieces
    Piece InitialTransparentPiecesArray[8][8];
    GameSetup.setupTransparentPieces(InitialTransparentPiecesArray, 8, BOARD_SQUARE_LENGTH, CENTRE_OFFSET);
    int i = 0;
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
        
        //Loads the icon
        GameSetup.loadIcon(window);
        
        sf::Vector2u size = window.getSize();
        unsigned int width = size.x;
        unsigned int height = size.y;
        widthScale = float(size.x)/722;
        heightScale = float(size.y)/722;
        
        std::cout << widthScale << " " << heightScale << std::endl;
        //Load the textures and create background
        GameSetup.loadTexturesAndBackground(window,widthScale,heightScale);
        
        //Draw the initial 4 visible pieces
        for (int i = 0; i < 4; i++) {
            window.draw(InitialVisiblePiecesArray[i].tile);
        }
        
        //Draw the board of invisible pieces
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                window.draw(InitialTransparentPiecesArray[i][j].tile);
            }
        }
        
        
        //Gets the mouse position
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        
        //Main game loop
            
        //Player move
        if (turn == "P") {
            
            if (CheckPosition.mouseWithinWindow(BOARD_SQUARE_LENGTH, mousePos)) {
                xCoord = (int)mousePos.x/BOARD_SQUARE_LENGTH;
                yCoord = (int)mousePos.y/BOARD_SQUARE_LENGTH;
            }
                
            if (CheckPosition.mouseWithinSquare(BOARD_SQUARE_LENGTH, xCoord, yCoord, mousePos) && sf::Mouse::isButtonPressed(sf::   Mouse::Left) && Board.legalSpot(xCoord, yCoord, playerColor)) {
                    
                Board.changeBoard(xCoord, yCoord, playerColor);
                Board.flipBoard(xCoord, yCoord, playerColor);
                turn = "O";
                clock.restart();
            }
            
            //Converts the colors of the pieces based on the internal board
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j<8; j++) {
                    if (Board.board[i][j] == "W") {
                        InitialTransparentPiecesArray[i][j].tile.setColor(sf::Color(255,255,255,255));
                        whiteScore++;
                    } else if (Board.board[i][j] == "B") {
                        InitialTransparentPiecesArray[i][j].tile.setColor(sf::Color(0,0,0,255));
                        blackScore++;
                    }
                }
            }
        }
        
        sf::Time timeElapsed = clock.getElapsedTime();
        //Computer move
        if (turn == "O" && timeElapsed.asSeconds() >= 1) {
            for (int i = 0; i<8; i++) {
                for (int j = 0; j<8; j++) {
                    if (Board.legalSpot(i, j, opponentColor)) {
                        Board.changeBoard(i, j, opponentColor);
                        Board.flipBoard(i, j, opponentColor);
                        stop = true;
                        break;
                    }
                }
                if (stop) {
                    break;
                }
            }
                
            stop = false;
            turn = "P";
            
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j<8; j++) {
                    if (Board.board[i][j] == "W") {
                        InitialTransparentPiecesArray[i][j].tile.setColor(sf::Color(255,255,255,255));
                        whiteScore++;
                    } else if (Board.board[i][j] == "B") {
                        InitialTransparentPiecesArray[i][j].tile.setColor(sf::Color(0,0,0,255));
                        blackScore++;
                    }
                }
            }
        }
        // Update the window
        window.display();
    }
}


