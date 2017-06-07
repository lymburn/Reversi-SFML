//
//  game.hpp
//  Reversi
//
//  Created by Eugene Lu on 2017-06-02.
//  Copyright © 2017 Eugene Lu. All rights reserved.
//

#ifndef game_hpp
#define game_hpp

#include <iostream>
#include <stdio.h>
#include "SFML/Graphics.hpp"
#include "ResourcePath.hpp"
#include "piece.hpp"
#include "setupManager.hpp"
#include "positionchecker.hpp"
#include "internalboard.hpp"

class Game {
    public:
        void run();
};

#endif /* game_hpp */
