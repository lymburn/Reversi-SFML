//
//  positionchecker.cpp
//  Reversi
//
//  Created by Eugene Lu on 2017-06-05.
//  Copyright © 2017 Eugene Lu. All rights reserved.
//

#include "positionchecker.hpp"

bool PositionChecker::mouseWithinWindow(const float BOARD_SQUARE_LENGTH, sf::Vector2i mousePos) {
    if (mousePos.x/BOARD_SQUARE_LENGTH>0 && mousePos.x/BOARD_SQUARE_LENGTH < 8 && mousePos.y/BOARD_SQUARE_LENGTH>0 && mousePos.y/BOARD_SQUARE_LENGTH < 8) {
        return true;
    } else return false;
}

bool PositionChecker::mouseWithinSquare(const float BOARD_SQUARE_LENGTH, int xCoord, int yCoord, sf::Vector2i mousePos) {
    if (mousePos.x > xCoord*BOARD_SQUARE_LENGTH && mousePos.x < ((xCoord*BOARD_SQUARE_LENGTH)+BOARD_SQUARE_LENGTH) && mousePos.y > yCoord*BOARD_SQUARE_LENGTH && mousePos.y < ((yCoord*BOARD_SQUARE_LENGTH)+BOARD_SQUARE_LENGTH)) {
        return true;
    } else return false;
}




