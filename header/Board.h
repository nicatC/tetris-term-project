//
// Created by nevermind on 12/24/23.
//

#ifndef TETRIS_TERM_PROJECT_BOARD_H
#define TETRIS_TERM_PROJECT_BOARD_H

#include "Piece.h"
#include <SFML/Graphics.hpp>
class Piece;
class Board {
public:
    Board(sf::RenderWindow& window, int defaultBlockSize);
    void update(Piece& piece, sf::RenderWindow& window, int defaultBlockSize);
    void render(sf::RenderWindow& window);
    void setGridCell(int x, int y, int value);
    void setOccupied(int x, int y);
    bool isCollision(const Piece& piece) const;
    bool isOccupied(int x, int y) const;
    int getBoardWidth() const;
    void applyBoard(const Piece& piece);
    void setGameOver(bool value);
    bool isGameOver() const;
    void restart();
    void clearBoard();
    int getBoardHeight() const {
        return boardHeight;
    }
private:
    sf::RenderWindow& window;
    int defaultBlockSize;
    static const int boardWidth = 18;
    static const int boardHeight = 24;
    int grid[boardHeight][boardWidth];
    bool gameOver = false;
};



#endif //TETRIS_TERM_PROJECT_BOARD_H
