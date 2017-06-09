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
        void setupVisiblePieces(Piece initialVisiblePiecesArray[], int size, const float BOARD_SQUARE_LENGTH, const float CENTRE_OFFSET, float widthScale, float heightScale);
        void setupTransparentPieces(Piece initialTransparentPiecesArray[][8], int size, const float BOARD_SQUARE_LENGTH, const float CENTRE_OFFSET, float widthScale, float heightScale);
        void drawInitialTransparentPieces(sf::RenderWindow& window, Piece initialTransParentPiecesArray[][8]);
        void drawInitialVisiblePieces(sf::RenderWindow& window, Piece initialVisiblePiecesArray[4]);
        void loadIcon(sf::RenderWindow& window);
        void loadTexturesAndBoard(sf::RenderWindow& window, float widthScale, float heightScale, float offset);
        void loadBackground(sf::RenderWindow& window, float widthScale, float heightScale);
    
    private:
        void setupInitialPieces(PieceColors color,const float SQUARE_LENGTH, const float CENTRE_OFFSET, Piece& initialPiece, int row, int col, float widthScale, float heightScale);
        bool visible;
        sf::Sprite background;
        sf::Sprite board;
        TextureManager TextureLoader;
        sf::Sprite whiteScoreboard;
        sf::Sprite blackScoreboard;
        float boardOffset = 43.875;
};

#endif /* setupManager_hpp */
