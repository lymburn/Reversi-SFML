//
//  piece.cpp
//  Reversi
//
//  Created by Eugene Lu on 2017-06-01.
//  Copyright © 2017 Eugene Lu. All rights reserved.
//

#include "piece.hpp"

//Sets the color and texture of the piece
void Piece::setTextureAndColor (pieceColors& colorParameter) {
    textureAdder.loadPieceTexture();
    color = colorParameter;
    texture = textureAdder.pieceTexture;
}

//Add the texture to the piece
void Piece::addTextureAndColor(sf::Sprite& tile) {
    tile.setTexture(texture);
    if (color == pieceColors::black) {
        tile.setColor(sf::Color(0,0,0,255));
    } else {
        tile.setColor(sf::Color(255,255,255,255));
    }
}

