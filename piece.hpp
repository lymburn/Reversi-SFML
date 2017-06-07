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

enum class PieceColors {black,white};

class Piece {
    public:
        sf::Sprite tile;
        void setTextureAndColor(PieceColors& color);
        void addTextureAndColor(sf::Sprite& tile);
        std::string oppositeColor(std::string color);
    private:
        PieceColors color;
        sf::Texture texture;
        TextureManager TextureAdder;
};

#endif /* piece_hpp */
