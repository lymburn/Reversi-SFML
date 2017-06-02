//
//  piece.hpp
//  Reversi
//
//  Created by Eugene Lu on 2017-06-01.
//  Copyright © 2017 Eugene Lu. All rights reserved.
//

#ifndef piece_hpp
#define piece_hpp

#include <stdio.h>

class Piece {
    public:
        void setColor(int color);
    private:
        int color;
};

#endif /* piece_hpp */
