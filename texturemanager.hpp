//
//  texturemanager.hpp
//  Reversi
//
//  Created by Eugene Lu on 2017-06-01.
//  Copyright © 2017 Eugene Lu. All rights reserved.
//

#ifndef texturemanager_hpp
#define texturemanager_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class TextureManager {
    public:
        void loadBoardTexture();
        void loadPieceTexture();
        void loadIncreaseResolutionButton();
        void loadDecreaseResolutionButton();
        sf::Texture increaseResolutionTexture;
        sf::Texture decreaseResolutionTexture;
        sf::Texture boardTexture;
        sf::Texture pieceTexture;
};

#endif /* texturemanager_hpp */
