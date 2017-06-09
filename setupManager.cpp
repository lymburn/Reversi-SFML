//
//  setupManager.cpp
//  Reversi
//
//  Created by Eugene Lu on 2017-06-05.
//  Copyright © 2017 Eugene Lu. All rights reserved.
//

#include "setupManager.hpp"

void SetupManager::setupInitialPieces(PieceColors color,const float SQUARE_LENGTH, const float CENTRE_OFFSET, Piece& initialPiece, int row, int col, float widthScale, float heightScale) {
    Piece* piecePtr = &initialPiece;
    piecePtr->setTextureAndColor(color);
    piecePtr->addTextureAndColor(piecePtr->tile, widthScale, heightScale);
    piecePtr->tile.setPosition(row*SQUARE_LENGTH + boardOffset + CENTRE_OFFSET, col*SQUARE_LENGTH + boardOffset + CENTRE_OFFSET);
    
    if (!visible) {
        piecePtr->tile.setColor(sf::Color(255,255,255,0));
    }
    
    
}

void SetupManager::setupVisiblePieces(Piece initialVisiblePiecesArray[], int size, const float BOARD_SQUARE_LENGTH, const float CENTRE_OFFSET, float widthScale, float heightScale) {
    PieceColors white = PieceColors::white;
    PieceColors black = PieceColors::black;
    visible = true;
    //Sets up initial visible pieces
    setupInitialPieces(white,BOARD_SQUARE_LENGTH,CENTRE_OFFSET, initialVisiblePiecesArray[0], 3, 3, widthScale, heightScale);
    setupInitialPieces(white,BOARD_SQUARE_LENGTH,CENTRE_OFFSET, initialVisiblePiecesArray[1], 4, 4, widthScale, heightScale);
    setupInitialPieces(black,BOARD_SQUARE_LENGTH,CENTRE_OFFSET, initialVisiblePiecesArray[2], 3, 4, widthScale, heightScale);
    setupInitialPieces(black,BOARD_SQUARE_LENGTH,CENTRE_OFFSET, initialVisiblePiecesArray[3], 4, 3, widthScale, heightScale);
}

void SetupManager::setupTransparentPieces(Piece initialTransparentPiecesArray[][8], int size, const float BOARD_SQUARE_LENGTH, const float CENTRE_OFFSET, float widthScale, float heightScale) {
    PieceColors white = PieceColors::white;
    visible = false;
    
    for (int i = 0; i<size; i++) {
        for (int j=0;j<size;j++) {
            setupInitialPieces(white, BOARD_SQUARE_LENGTH,CENTRE_OFFSET, initialTransparentPiecesArray[i][j], i, j, widthScale, heightScale);
        }
    }
}

void SetupManager::loadTexturesAndBoard(sf::RenderWindow& window, float widthScale, float heightScale, float offset) {
    //Loads the board texture
    TextureLoader.loadBoardTexture();
    board.setTexture(TextureLoader.boardTexture);
    board.setScale(widthScale,heightScale);
    board.setPosition(offset,offset);
    window.draw(board);
}

void SetupManager::loadIcon(sf::RenderWindow& window) {
    //Sets the icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}


void SetupManager::loadBackground(sf::RenderWindow& window, float widthScale, float heightScale) {
    TextureLoader.loadBackgroundTexture();
    background.setTexture(TextureLoader.backgroundTexture);
    background.setScale(widthScale,heightScale);
    window.draw(background);
}

void SetupManager::drawInitialTransparentPieces(sf::RenderWindow& window, Piece (*initialTransparentPiecesArray)[8]) {

    //Draw the board of initially transparent pieces
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            window.draw(initialTransparentPiecesArray[i][j].tile);
        }
    }
}


void SetupManager::drawInitialVisiblePieces(sf::RenderWindow& window, Piece initialVisiblePiecesArray[4]) {
    //Draw the initial 4 visible pieces
    for (int i = 0; i < 4; i++) {
        window.draw(initialVisiblePiecesArray[i].tile);
    }
}
