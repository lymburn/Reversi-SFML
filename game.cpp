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
    
    //Window sizes
    sf::Vector2u size = window.getSize();
    unsigned int windowWidth = size.x;
    unsigned int windowHeight = size.y;
    
    //Scales and dimensions
    float widthBoardScale, heightBoardScale, widthPieceScale, heightPieceScale, widthScoreScale, heightScoreScale, backgroundWidthScale, backgroundHeightScale;
    widthBoardScale = float(size.y)/800;
    heightBoardScale = float(size.y)/800;
    widthScoreScale = float(size.x)/(5*310);
    heightScoreScale = float(size.y)/(6*155);
    backgroundWidthScale = float(size.x)/2560;
    backgroundHeightScale = float(size.y)/1600;
    const float BOARD_SQUARE_LENGTH = 91 * widthBoardScale;
    const float BOARD_LENGTH = BOARD_SQUARE_LENGTH * 8;
    widthPieceScale = float(size.y)/(14*BOARD_SQUARE_LENGTH);
    heightPieceScale = float(size.y)/(14*BOARD_SQUARE_LENGTH);
    float backgroundOffset = 43.875;
    const float RADIUS = 61.0 * widthPieceScale;
    const float CENTRE_OFFSET = (BOARD_SQUARE_LENGTH - 2*RADIUS)/2;
    
    //Variables and objects
    std::string playerColor;
    std::string opponentColor;
    std::string turn;
    int whiteScore = 2;
    int blackScore = 2;
    int xCoord, yCoord;
    int tmpPositionScore, tmpI = 0, tmpJ = 0;
    bool stop = false;
    bool leftClick = false;
    bool playerChoseColor = false;
    bool gameFinished = false;
    Piece GamePiece;
    SetupManager GameSetup;
    FontManager TextGenerator;
    PositionChecker CheckPosition;
    InternalBoard Board;
    
    //Clock to count time between moves
    sf::Clock delayClock;
    sf::Time timeDelay;
    //Clock to get time since clicking
    sf::Clock clickingClock;
    sf::Time timeSinceClick;
    
    //Load the fonts
    TextGenerator.loadSansation();
    
    //Initializes the 4 initial pieces
    Piece InitialVisiblePiecesArray[4];
    GameSetup.setupVisiblePieces(InitialVisiblePiecesArray, 4,BOARD_SQUARE_LENGTH, CENTRE_OFFSET, widthPieceScale, heightPieceScale);
    
    //Initializes the rest of the transparent pieces
    Piece InitialTransparentPiecesArray[8][8];
    GameSetup.setupTransparentPieces(InitialTransparentPiecesArray, 8, BOARD_SQUARE_LENGTH, CENTRE_OFFSET, widthPieceScale, heightPieceScale);
    
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
            
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    leftClick = true;
                    clickingClock.restart();
                }
            }
            
            //Events for beginning when player chooses which color
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W) {
                playerColor = "W";
                playerChoseColor = true;
                turn = "Player";
            } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::B) {
                playerColor = "B";
                playerChoseColor = true;
                turn = "Computer";
            }
        }
        
        //Gets the time since the player clicked
        timeSinceClick  = clickingClock.getElapsedTime();
        
        //Declares opponent color
        opponentColor = GamePiece.oppositeColor(playerColor);
        
        // Clear screen
        window.clear();
        
        //Loads the icon
        GameSetup.loadIcon(window);
        //Loads the background
        GameSetup.loadBackground(window, backgroundWidthScale, backgroundHeightScale);
        //Load the board
        GameSetup.loadTexturesAndBoard(window,widthBoardScale,heightBoardScale, backgroundOffset);
        //Displays the scores
        TextGenerator.displayWhiteScore(window, 880, 350, whiteScore);
        TextGenerator.displayBlackScore(window, 880, 400, blackScore);
        TextGenerator.displayTitle(window, 880, 100);
        
        //Ask player to choose color
        if (playerChoseColor == false) {
            TextGenerator.askPlayerColor(window, 880, 600);
        }
        
        //Victory conditions and display
        if ((whiteScore+blackScore == 64) || whiteScore == 0 || blackScore == 0) {
            if (whiteScore == 0 || blackScore>whiteScore) {
                TextGenerator.displayVictory(window, 880, 500, "Black");
                gameFinished = true;
            } else if (blackScore == 0 || whiteScore>blackScore) {
                TextGenerator.displayVictory(window, 880, 500, "White");
                gameFinished = true;
            }
        }

        //Draw the initial 4 visible pieces
        GameSetup.drawInitialVisiblePieces(window, InitialVisiblePiecesArray);
        
        //Draw the board of initially transparent pieces
        GameSetup.drawInitialTransparentPieces(window, InitialTransparentPiecesArray);
        
        //Gets the mouse position
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        
        //Main game loop
        
        //Player move
        if (turn == "Player" && !gameFinished) {
            //Switches if no available moves
            
            if (!Board.movesAvailable(playerColor)) {
                turn = "Computer";
            }
            
            
            //Gets the x and y coordinates of the board if the mouse is within the window
            if (CheckPosition.mouseWithinWindow(BOARD_SQUARE_LENGTH, mousePos, backgroundOffset)) {
                xCoord = (int)(mousePos.x-backgroundOffset)/BOARD_SQUARE_LENGTH;
                yCoord = (int)(mousePos.y-backgroundOffset)/BOARD_SQUARE_LENGTH;
            }
            
            //Main mechanism when putting a piece
            if (CheckPosition.mouseWithinSquare(BOARD_SQUARE_LENGTH, xCoord, yCoord, mousePos, backgroundOffset) && leftClick && Board.legalSpot(xCoord, yCoord, playerColor) && timeSinceClick.asSeconds() <= 0.1) {
                
                leftClick = false;
                Board.changeBoard(xCoord, yCoord, playerColor);
                Board.flipBoard(xCoord, yCoord, playerColor);
                //Switch turn to computer
                turn = "Computer";
                delayClock.restart();
            }
            
            //Converts the colors of the pieces based on the internal board
            Board.changeVisualColors(InitialTransparentPiecesArray, whiteScore, blackScore);
        }
        
        //Gets the time elapsed to set a time delay in between moves
        timeDelay = delayClock.getElapsedTime();
        //Computer move
        if (turn == "Computer" && timeDelay.asSeconds() >= 1 && !gameFinished) {
            //Switches if no available moves
            
            int positionScore = -5000;
            
            if (!Board.movesAvailable(opponentColor)) {
                turn = "Player";
            }
            
            
            for (int i = 0; i<8; i++) {
                for (int j = 0; j<8; j++) {
                    if (Board.legalSpot(i, j, opponentColor)) {
                        positionScore = Board.positionScoreCalculator(i, j);
                        if (positionScore>tmpPositionScore) {
                            tmpPositionScore = positionScore;
                            std::cout<<tmpPositionScore<<std::endl;
                            tmpI = i;
                            tmpJ = j;
                        }
                    }
                }
            }
            
            tmpPositionScore = 0;

            
            Board.changeBoard(tmpI, tmpJ, opponentColor);
            Board.flipBoard(tmpI, tmpJ, opponentColor);
            tmpI = 0;
            tmpJ = 0;
            //Change the colors that have been flipped
            Board.changeVisualColors(InitialTransparentPiecesArray, whiteScore, blackScore);
            //Switch turn to player
            turn = "Player";
        }
        // Update the window
        window.display();
    }
}


