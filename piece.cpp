//
//  piece.cpp
//  Reversi
//
//  Created by Eugene Lu on 2017-06-01.
//  Copyright © 2017 Eugene Lu. All rights reserved.
//

#include "piece.hpp"

//Sets the color and texture of the piece
void Piece::setTextureAndColor (PieceColors& colorParameter) {
    TextureAdder.loadPieceTexture();
    color = colorParameter;
    texture = TextureAdder.pieceTexture;
}

//Add the texture to the piece
void Piece::addTextureAndColor(sf::Sprite& tile, float widthScale, float heightScale) {
    tile.setTexture(texture);
    if (color == PieceColors::black) {
        tile.setColor(sf::Color(0,0,0,255));
    } else {
        tile.setColor(sf::Color(255,255,255,255));
    }
    
    tile.setScale(widthScale, heightScale);
}

std::string Piece::oppositeColor(std::string color) {
    if (color == "B"){
        return "W";
    } else {
        return "B";
    }
}
