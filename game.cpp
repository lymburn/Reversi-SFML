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
    sf::RenderWindow window(sf::VideoMode(1200, 900), "Reversi", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    
    
    sf::Vector2u size = window.getSize();
    float widthBoardScale, heightBoardScale, widthPieceScale, heightPieceScale, widthButtonScale, heightButtonScale;
    unsigned int windowWidth = size.x;
    unsigned int windowHeight = size.y;
    
    //Scales
    widthBoardScale = float(size.y)/722;
    heightBoardScale = float(size.y)/722;
    widthPieceScale = float(size.y)/(10*122);
    heightPieceScale = float(size.y)/(10*122);
    widthButtonScale = float(size.x)/(5*310);
    heightButtonScale = float(size.y)/(6*155);
    
    //Board and piece dimensions
    const float BOARD_SQUARE_LENGTH = 91 * widthBoardScale;
    const float BOARD_LENGTH = BOARD_SQUARE_LENGTH * 8;
    const float CENTRE_OFFSET = 7 * widthBoardScale;
    const float RADIUS = 61.0 * widthPieceScale;
    

    //Variables and objects
    std::string playerColor;
    std::string opponentColor;
    int whiteScore = 2;
    int blackScore = 2;
    std::string turn = "P";
    int xCoord, yCoord;
    bool stop = false;
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
    GameSetup.setupVisiblePieces(InitialVisiblePiecesArray, 4,BOARD_SQUARE_LENGTH, CENTRE_OFFSET, widthPieceScale, heightPieceScale);
    
    //Initializes the rest of the transparent pieces
    Piece InitialTransparentPiecesArray[8][8];
    GameSetup.setupTransparentPieces(InitialTransparentPiecesArray, 8, BOARD_SQUARE_LENGTH, CENTRE_OFFSET, widthPieceScale, heightPieceScale);
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
        
        //Load the textures and create background
        GameSetup.loadTexturesAndBackground(window,widthBoardScale,heightBoardScale);
        
        GameSetup.loadResolutionButtons(window,widthButtonScale, heightButtonScale, BOARD_LENGTH + ((windowWidth - BOARD_LENGTH)/10), windowHeight, BOARD_SQUARE_LENGTH);
        
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


