//
//  fontmanager.hpp
//  Reversi
//
//  Created by Eugene Lu on 2017-06-07.
//  Copyright © 2017 Eugene Lu. All rights reserved.
//

#ifndef fontmanager_hpp
#define fontmanager_hpp

#include <stdio.h>
#include "SFML/Graphics.hpp"

//Manages the creation of text and fonts
class FontManager {
    public:
        void askPlayerColor(sf::RenderWindow& window, float xPosition, float yPosition);
        void loadSansation();
        void displayWhiteScore(sf::RenderWindow& window, float xPosition, float yPosition, int whiteScoreNumber);
        void displayBlackScore(sf::RenderWindow& window, float xPosition, float yPosition, int whiteScoreNumber);
        void displayTitle(sf::RenderWindow& window, float xPosition, float yPosition);
    void displayVictory(sf::RenderWindow& window, float xPosition, float yPosition, std::string color);
    private:
        sf::Font sansation;
        sf::Text playerInitialColor;
        sf::Text whiteScoreText;
        sf::Text blackScoreText;
        sf::Text titleText;
        sf::Text victoryText;

};
#endif /* fontmanager_hpp */
