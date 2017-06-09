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


class InternalBoard {
    public:
        void changeBoard(int xCoord, int yCoord, std::string color);
        void flipBoard(int xCoord, int yCoord, std::string color);
        bool legalSpot(int xCoord, int yCoord, std::string color);
        void changeVisualColors(Piece visualArray[][8], int& whiteScore, int& blackScore);
        bool movesAvailable(std::string color);
        int numOfFlips = 0;
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
    
    protected:
        bool checkLegalMove(int xCoord, int yCoord, std::string color, int deltaRow, int deltaCol);
    private:
        Piece GamePiece;
        void flipDirection(int xCoord, int yCoord, int deltaX, int deltaY, std::string color);
};

#endif /* internalboard_hpp */
