//
//  setupManager.hpp
//  Reversi
//
//  Created by Eugene Lu on 2017-06-05.
//  Copyright © 2017 Eugene Lu. All rights reserved.
//

#ifndef setupManager_hpp
#define setupManager_hpp

#include <stdio.h>
#include "SFML/Graphics.hpp"
#include "texturemanager.hpp"
#include "piece.hpp"
#include "ResourcePath.hpp"

class SetupManager {
    public:
        void setupVisiblePieces(Piece initialVisiblePiecesArray[], int size, const float BOARD_SQUARE_LENGTH, const float CENTRE_OFFSET);
        void setupTransparentPieces(Piece initialTransparentPiecesArray[][8], int size, const float BOARD_SQUARE_LENGTH, const float CENTRE_OFFSET);
        void loadIcon(sf::RenderWindow& window);
        void loadTexturesAndBackground(sf::RenderWindow& window, float widthScale, float heightScale);
    
    private:
        void setupInitialPieces(PieceColors color,const float SQUARE_LENGTH, const float CENTRE_OFFSET, Piece& initialPiece, int row, int col);
        bool visible;
        sf::Sprite background;
        TextureManager TextureLoader;
};

#endif /* setupManager_hpp */
