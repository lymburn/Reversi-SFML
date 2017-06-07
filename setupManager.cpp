//
//  setupManager.cpp
//  Reversi
//
//  Created by Eugene Lu on 2017-06-05.
//  Copyright © 2017 Eugene Lu. All rights reserved.
//

#include "setupManager.hpp"

void SetupManager::setupInitialPieces(PieceColors color,const float SQUARE_LENGTH, const float CENTRE_OFFSET, Piece& initialPiece, int row, int col) {
    Piece* piecePtr = &initialPiece;
    piecePtr->setTextureAndColor(color);
    piecePtr->addTextureAndColor(piecePtr->tile);
    piecePtr->tile.setPosition(row*SQUARE_LENGTH + CENTRE_OFFSET, col*SQUARE_LENGTH + CENTRE_OFFSET);
    
    if (!visible) {
        piecePtr->tile.setColor(sf::Color(255,255,255,0));
    }
}

void SetupManager::setupVisiblePieces(Piece initialVisiblePiecesArray[], int size, const float BOARD_SQUARE_LENGTH, const float CENTRE_OFFSET) {
    PieceColors white = PieceColors::white;
    PieceColors black = PieceColors::black;
    visible = true;
    //Sets up initial visible pieces
    setupInitialPieces(white,BOARD_SQUARE_LENGTH,CENTRE_OFFSET, initialVisiblePiecesArray[0], 3, 3);
    setupInitialPieces(white,BOARD_SQUARE_LENGTH,CENTRE_OFFSET, initialVisiblePiecesArray[1], 4, 4);
    setupInitialPieces(black,BOARD_SQUARE_LENGTH,CENTRE_OFFSET, initialVisiblePiecesArray[2], 3, 4);
    setupInitialPieces(black,BOARD_SQUARE_LENGTH,CENTRE_OFFSET, initialVisiblePiecesArray[3], 4, 3);
}

void SetupManager::setupTransparentPieces(Piece initialTransparentPiecesArray[][8], int size, const float BOARD_SQUARE_LENGTH, const float CENTRE_OFFSET) {
    PieceColors white = PieceColors::white;
    visible = false;
    
    for (int i = 0; i<size; i++) {
        for (int j=0;j<size;j++) {
            setupInitialPieces(white, BOARD_SQUARE_LENGTH,CENTRE_OFFSET, initialTransparentPiecesArray[i][j], i, j);
        }
    }
}

void SetupManager::loadTexturesAndBackground(sf::RenderWindow& window, float widthScale, float heightScale) {
    //Loads the board texture
    TextureLoader.loadBoardTexture();
    background.setTexture(TextureLoader.boardTexture);
    background.setScale(widthScale,heightScale);
    window.draw(background);
}

void SetupManager::loadIcon(sf::RenderWindow& window) {
    //Sets the icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}
