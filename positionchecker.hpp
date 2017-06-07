//
//  positionchecker.hpp
//  Reversi
//
//  Created by Eugene Lu on 2017-06-05.
//  Copyright © 2017 Eugene Lu. All rights reserved.
//

#ifndef positionchecker_hpp
#define positionchecker_hpp

#include <stdio.h>
#include "SFML/Graphics.hpp"
#include "piece.hpp"

class PositionChecker {
public:
    Piece GamePiece;
    bool mouseWithinWindow(const float BOARD_SQUARE_LENGTH, sf::Vector2i mousePos);
    bool mouseWithinSquare(const float BOARD_SQUARE_LENGTH, int row, int col, sf::Vector2i mousePos);
    
};

#endif /* positionchecker_hpp */