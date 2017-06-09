//
//  internalboard.hpp
//  Reversi
//
//  Created by Eugene Lu on 2017-06-05.
//  Copyright © 2017 Eugene Lu. All rights reserved.
//

#ifndef internalboard_hpp
#define internalboard_hpp

#include <stdio.h>
#include <iostream>
#include "piece.hpp"

//Manages the interal 8x8 board of strings, checks for moves, flips the pieces, and change the graphics
class InternalBoard {
    public:
        void changeBoard(int xCoord, int yCoord, std::string color);
        bool legalSpot(int xCoord, int yCoord, std::string color);
        void changeVisualColors(Piece visualArray[][8], int& whiteScore, int& blackScore);
        void flipBoard(int xCoord, int yCoord, std::string color);
        bool movesAvailable(std::string color);
        int positionScoreCalculator(int i, int j);
        std::string board[8][8] =
        {
            {"U","U","U","U","U","U","U","U"},
            {"U","U","U","U","U","U","U","U"},
            {"U","U","U","U","U","U","U","U"},
            {"U","U","U","W","B","U","U","U"},
            {"U","U","U","B","W","U","U","U"},
            {"U","U","U","U","U","U","U","U"},
            {"U","U","U","U","U","U","U","U"},
            {"U","U","U","U","U","U","U","U"}
        };
    
    
    private:
        bool checkLegalMove(int xCoord, int yCoord, std::string color, int deltaRow, int deltaCol);
        Piece GamePiece;
        void flipDirection(int xCoord, int yCoord, int deltaX, int deltaY, std::string color);
};

#endif /* internalboard_hpp */
