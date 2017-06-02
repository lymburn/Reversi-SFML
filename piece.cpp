//
//  piece.cpp
//  Reversi
//
//  Created by Eugene Lu on 2017-06-01.
//  Copyright © 2017 Eugene Lu. All rights reserved.
//

#include "piece.hpp"

//Sets the color for the piece, 1 is for white and 2 for black
void Piece::setColor (int color) {
    if (color == 1) {
        color = 1;
    } else {
        color = 2;
    }
}
