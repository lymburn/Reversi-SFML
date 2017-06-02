//
//  piece.hpp
//  Reversi
//
//  Created by Eugene Lu on 2017-06-01.
//  Copyright © 2017 Eugene Lu. All rights reserved.
//

#ifndef piece_hpp
#define piece_hpp

#include <stdio.h>
#include "SFML/Graphics.hpp"
#include "texturemanager.hpp"

enum class pieceColors {black,white};

class Piece {
    public:
        sf::Sprite tile;
        void setTextureAndColor(pieceColors& color);
        void addTexture(sf::Sprite& tile);
        TextureManager textureAdder;
    private:
        pieceColors color;
        sf::Texture texture;
};

#endif /* piece_hpp */
