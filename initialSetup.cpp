//
//  initialSetup.cpp
//  Reversi
//
//  Created by Eugene Lu on 2017-06-01.
//  Copyright © 2017 Eugene Lu. All rights reserved.
//

#include "initialSetup.hpp"

//Creates board background

void createBackground(sf::Sprite& background, sf::Texture& texture) {
    background.setTexture(texture);
    background.setScale(1.66f,1.66f);
}
