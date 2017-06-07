//
//  internalboard.cpp
//  Reversi
//
//  Created by Eugene Lu on 2017-06-05.
//  Copyright © 2017 Eugene Lu. All rights reserved.
//

#include "internalboard.hpp"

bool InternalBoard::checkLegalMove(int xCoord, int yCoord, std::string color, int deltaX, int deltaY) {
    int count = 0;
    
    if (board[xCoord][yCoord] == "U") {
        while (xCoord < 8 && yCoord < 8 && board[xCoord][yCoord] != color && xCoord >=0 && yCoord >=0) {
            
            xCoord = xCoord + deltaX;
            yCoord = yCoord + deltaY;
            if (board[xCoord][yCoord] == GamePiece.oppositeColor(color)) {
                count++;
            } else break;
            
            if (board[xCoord][yCoord] == "U") {
                break;
            }
            
            if (board[xCoord + deltaX][yCoord+deltaY] == color && count > 0 && xCoord < 8 && yCoord < 8 && xCoord >=0 && yCoord >=0) {
                return true;
            }
        } return false;
    } else return false;
}

bool InternalBoard::legalSpot(int xCoord, int yCoord, std::string color) {
    
    if (checkLegalMove(xCoord, yCoord, color, 0, 1)
        || checkLegalMove(xCoord, yCoord, color, -1, 1)
        || checkLegalMove(xCoord, yCoord, color, -1, 0)
        || checkLegalMove(xCoord, yCoord, color, -1, -1)
        || checkLegalMove(xCoord, yCoord, color, 0, -1)
        || checkLegalMove(xCoord, yCoord, color, 1, -1)
        || checkLegalMove(xCoord, yCoord, color, 1, 0)
        || checkLegalMove(xCoord, yCoord, color, 1, 1)) {
        
        return true;
        
    } else return false;
}


void InternalBoard::changeBoard(int xCoord, int yCoord, std::string color) {
    if (color == "B") {
        board[xCoord][yCoord] = "B";
    } else {
        board[xCoord][yCoord] = "W";
    }
}



void InternalBoard::flipDirection(int xCoord, int yCoord, int deltaX, int deltaY, std::string color) {
    int count = 0;
    
    while (xCoord < 8 && yCoord < 8 && xCoord>=0 && yCoord>=0) {
        xCoord += deltaX;
        yCoord += deltaY;
        
        if (board[xCoord][yCoord] == GamePiece.oppositeColor(color)) {
            count++;
        }
        
        if (board[xCoord][yCoord] == "U") {
            break;
        }
        
        if (board[xCoord][yCoord] == color) {
            for (int i = 1; i <= count; i++) {
                board[xCoord - deltaX*i][yCoord - deltaY*i] = color;
            }
            
            break;
        }
    }
}

void InternalBoard::flipBoard(int xCoord, int yCoord, std::string color) {
    flipDirection(xCoord, yCoord, 0, 1, color);
    flipDirection(xCoord, yCoord, -1, 1, color);
    flipDirection(xCoord, yCoord, -1, 0, color);
    flipDirection(xCoord, yCoord, -1, -1, color);
    flipDirection(xCoord, yCoord, 0, -1, color);
    flipDirection(xCoord, yCoord, 1, -1, color);
    flipDirection(xCoord, yCoord, 1, 0, color);
    flipDirection(xCoord, yCoord, 1, 1, color);
    
}
 
