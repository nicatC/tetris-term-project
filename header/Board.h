//
// Created by nevermind on 12/24/23.
//

#ifndef TETRIS_TERM_PROJECT_BOARD_H
#define TETRIS_TERM_PROJECT_BOARD_H

#include "Piece.h"
#include <SFML/Graphics.hpp>
class Board {
public:
    Board();
    void update();
    void render(sf::RenderWindow& window);
private:
    static const int boardWidth = 10;
    static const int boardHeight = 20;
    int grid[boardHeight][boardWidth];
};



#endif //TETRIS_TERM_PROJECT_BOARD_H
