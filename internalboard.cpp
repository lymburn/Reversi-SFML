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
        
        //Prevent accessing outside of array
        if (xCoord < 0 || xCoord > 7 || yCoord < 0 || yCoord > 7) {
            break;
        }
        
        if (board[xCoord][yCoord] == GamePiece.oppositeColor(color)) {
            count++;
            numOfFlips++;
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

void InternalBoard::changeVisualColors(Piece visualArray[][8], int& whiteScore, int& blackScore) {
    int numbOfWhites = 0;
    int numOfBlacks = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j<8; j++) {
            if (board[i][j] == "W") {
                visualArray[i][j].tile.setColor(sf::Color(255,255,255,255));
                numbOfWhites++;
            } else if (board[i][j] == "B") {
                visualArray[i][j].tile.setColor(sf::Color(0,0,0,255));
                numOfBlacks++;
            }
        }
    }
    
    whiteScore = numbOfWhites;
    blackScore = numOfBlacks;
}

bool InternalBoard::movesAvailable(std::string color) {
    bool stop = false;
    int possibleMove = 0;
    for (int i = 0; i<8; i++) {
        for (int j = 0; j<8; j++) {
            if (legalSpot(i, j, color)) {
                possibleMove++;
                stop = true;
                break;
            }
        }
        if (stop) { //End the loop after putting a piece
            break;
        }
    }
    
    if (possibleMove > 0) {
        return true;
    } else return false;

}

int InternalBoard::positionScoreCalculator(int i, int j) {
    if ((i==0 && j==0) || (i==0 && j==7) || (i==7 && j==0) || (i==7 && j==0)) {
        return 10000;
    } else if ((i==1 && j==0) || (i==0 && j==1) || (i==7 && j==6) || (i==6 && j==7) || (i==0 && j==6) || (i==1 && j==7) || (i==6 && j==0) || (i==7 && j==1)) {
        return -3000;
    } else if ((i==0 && j==2) || (i==2 && j==0) || (i==5 && j==0) || (i==7 && j==2) || (i==0 && j==5) || (i==2 && j==7) || (i==5 && j==7) || (i==7 && j==5)) {
        return 1000;
    } else if ((i==0 && j==3) || (i==3 && j==0) || (i==0 && j==4) || (i==4 && j==7) || (i==4 && j==0) || (i==7 && j==3) || (i==7 && j==4) || (i==3 && j==7)) {
        return 800;
    }else if ((i==1 && j==3) || (i==3 && j==1) || (i==1 && j==4) || (i==4 && j==1)|| (i==6 && j==3) || (i==3 && j==6) || (i==6 && j==4) || (i==4 && j==6)) {
        return -500;
    }else if ((i==1 && j==2) || (i==2 && j==1) || (i==1 && j==5) || (i==5 && j==1) || (i==6 && j==2) || (i==2 && j==6) || (i==6 && j==5) || (i==5 && j==6)) {
        return -450;
    }else if ((i==2 && j==2) || (i==5 && j==2) || (i==2 && j==5) || (i==5 && j==5)) {
        return 30;
    }else if ((i==1 && j==1) || (i==1 && j==6) || (i==6 && j==1) || (i==6 && j==6)) {
        return -5000;
    }else if ((i==2 && j==3) || (i==3 && j==2) || (i==2 && j==4) || (i==4 && j==2) || (i==5 && j==3) || (i==3 && j==5) || (i==5 && j==4) || (i==4 && j==5)) {
        return 10;
    }else if ((i==3 && j==3) || (i==3 && j==4) || (i==4 && j==3) || (i==4 && j==4)) {
        return 50;
    }
}


