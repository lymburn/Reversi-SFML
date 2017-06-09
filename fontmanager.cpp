//
//  fontmanager.cpp
//  Reversi
//
//  Created by Eugene Lu on 2017-06-07.
//  Copyright © 2017 Eugene Lu. All rights reserved.
//

#include "fontmanager.hpp"
#include "ResourcePath.hpp"

void FontManager::loadSansation() {
    if (!sansation.loadFromFile(resourcePath() + "sansation.ttf"))
    {
        return EXIT_FAILURE;
    }
}

void FontManager::askPlayerColor(sf::RenderWindow& window, float xPosition, float yPosition) {
    playerInitialColor.setFont(sansation);
    playerInitialColor.setString("Press W/B to play \nas white or black");
    playerInitialColor.setCharacterSize(35);
    playerInitialColor.setPosition(xPosition, yPosition);
    window.draw(playerInitialColor);
}

void FontManager::displayWhiteScore(sf::RenderWindow& window, float xPosition, float yPosition, int whiteScoreNumber) {
    std::string whiteScoreString = std::to_string(whiteScoreNumber);
    
    whiteScoreText.setFont(sansation);
    whiteScoreText.setString("White Score: " + whiteScoreString);
    whiteScoreText.setCharacterSize(40);
    whiteScoreText.setPosition(xPosition, yPosition);
    window.draw(whiteScoreText);
}

void FontManager::displayBlackScore(sf::RenderWindow& window, float xPosition, float yPosition, int blackScoreNumber) {
    std::string blackScoreString = std::to_string(blackScoreNumber);
    
    blackScoreText.setFont(sansation);
    blackScoreText.setString("Black Score: " + blackScoreString);
    blackScoreText.setCharacterSize(40);
    blackScoreText.setPosition(xPosition, yPosition);
    window.draw(blackScoreText);
}

void FontManager::displayTitle(sf::RenderWindow& window, float xPosition, float yPosition) {
    
    titleText.setFont(sansation);
    titleText.setString("REVERSI");
    titleText.setCharacterSize(65);
    titleText.setPosition(xPosition, yPosition);
    titleText.setStyle(sf::Text::Bold | sf::Text::Underlined);
    window.draw(titleText);
}

void FontManager::displayVictory(sf::RenderWindow& window, float xPosition, float yPosition, std::string color) {
    victoryText.setFont(sansation);
    victoryText.setString("Victor: " + color);
    victoryText.setCharacterSize(40);
    victoryText.setPosition(xPosition, yPosition);
    victoryText.setStyle(sf::Text::Bold);
    window.draw(victoryText);
}
