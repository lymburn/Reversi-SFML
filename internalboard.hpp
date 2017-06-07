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
        void initializeBoard();
        void changeBoard(int xCoord, int yCoord, std::string color);
        void flipDirection(int xCoord, int yCoord, int deltaX, int deltaY, std::string color);
        void flipBoard(int xCoord, int yCoord, std::string color);
        bool checkLegalMove(int xCoord, int yCoord, std::string color, int deltaRow, int deltaCol);
        bool legalSpot(int xCoord, int yCoord, std::string color);

    
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
        Piece GamePiece;
};

#endif /* internalboard_hpp */
