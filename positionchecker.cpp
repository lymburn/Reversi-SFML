//
//  positionchecker.cpp
//  Reversi
//
//  Created by Eugene Lu on 2017-06-05.
//  Copyright © 2017 Eugene Lu. All rights reserved.
//

#include "positionchecker.hpp"

bool PositionChecker::mouseWithinWindow(const float BOARD_SQUARE_LENGTH, sf::Vector2i mousePos, float offset) {
    if ((mousePos.x>offset) && (mousePos.x < (BOARD_SQUARE_LENGTH*8)+offset) && mousePos.y > offset && (mousePos.y < (BOARD_SQUARE_LENGTH*8)+offset)) {
        return true;
    } else return false;
}

bool PositionChecker::mouseWithinSquare(const float BOARD_SQUARE_LENGTH, int xCoord, int yCoord, sf::Vector2i mousePos, float offset) {
    if (mousePos.x > (xCoord*BOARD_SQUARE_LENGTH) + offset && mousePos.x < ((xCoord*BOARD_SQUARE_LENGTH)+BOARD_SQUARE_LENGTH)+offset && mousePos.y > yCoord*BOARD_SQUARE_LENGTH + offset && mousePos.y < ((yCoord*BOARD_SQUARE_LENGTH)+BOARD_SQUARE_LENGTH) + offset) {
        return true;
    } else return false;
}




