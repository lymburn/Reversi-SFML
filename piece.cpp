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
    textureAdder.loadWhiteTexture();
    textureAdder.loadBlackTexture();
    color = colorParameter;
    
    if (colorParameter == pieceColors::black) {
        texture = textureAdder.blackTexture;
    } else {
        texture = textureAdder.whiteTexture;
    }
}

//Add the texture to the piece
void Piece::addTexture(sf::Sprite& tile) {
    if (color == pieceColors::black) {
        tile.setTexture(texture);
    } else {
        tile.setTexture(texture);
    }
    
    /*
    tile.setScale(0.88, 0.88);
    int radius = 75;
    tile.setPosition(mousePos.x-radius, mousePos.y-radius);
     */
}
