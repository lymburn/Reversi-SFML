//
//  initialSetup.cpp
//  Reversi
//
//  Created by Eugene Lu on 2017-06-01.
//  Copyright © 2017 Eugene Lu. All rights reserved.
//

#include "initialSetup.hpp"



void createBackground(sf::Sprite& background, sf::Texture& texture) {
    background.setTexture(texture);
    background.setScale(1.66f,1.66f);
}

void setupInitialPieces(pieceColors color,const float SQUARE_LENGTH, const float CENTRE_OFFSET, Piece& initialPiece, int row, int col, bool visible) {
        Piece* piecePtr = &initialPiece;
        piecePtr->setTextureAndColor(color);
        piecePtr->addTextureAndColor(piecePtr->tile);
        piecePtr->tile.setPosition(row*SQUARE_LENGTH + CENTRE_OFFSET, col*SQUARE_LENGTH + CENTRE_OFFSET);
    
        if (!visible) {
            piecePtr->tile.setColor(sf::Color(255,255,255,0));
    }
}

void setupVisiblePieces(Piece initialVisiblePiecesArray[], int size, const float BOARD_SQUARE_LENGTH, const float CENTRE_OFFSET) {
    pieceColors white = pieceColors::white;
    pieceColors black = pieceColors::black;
    bool visible = true;
    //Sets up initial visible pieces
    setupInitialPieces(white,BOARD_SQUARE_LENGTH,CENTRE_OFFSET, initialVisiblePiecesArray[0], 3, 3, visible);
    setupInitialPieces(white,BOARD_SQUARE_LENGTH,CENTRE_OFFSET, initialVisiblePiecesArray[1], 4, 4, visible);
    setupInitialPieces(black,BOARD_SQUARE_LENGTH,CENTRE_OFFSET, initialVisiblePiecesArray[2], 3, 4, visible);
    setupInitialPieces(black,BOARD_SQUARE_LENGTH,CENTRE_OFFSET, initialVisiblePiecesArray[3], 4, 3, visible);
}

void setupTransparentPieces(Piece initialTransparentPiecesArray[][8], int size, const float BOARD_SQUARE_LENGTH, const float CENTRE_OFFSET) {
    pieceColors white = pieceColors::white;
    bool visible = false;
    
    for (int i = 0; i<size; i++) {
        for (int j=0;j<size;j++) {
            setupInitialPieces(white,BOARD_SQUARE_LENGTH,CENTRE_OFFSET, initialTransparentPiecesArray[i][j], i, j, visible);
            initialTransparentPiecesArray[i][j].row = i*BOARD_SQUARE_LENGTH;
            initialTransparentPiecesArray[i][j].col = j*BOARD_SQUARE_LENGTH;
        }
    }

}
