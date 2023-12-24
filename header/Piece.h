//
// Created by nevermind on 12/24/23.
//

#ifndef TETRIS_TERM_PROJECT_PIECE_H
#define TETRIS_TERM_PROJECT_PIECE_H
#include <SFML/Graphics.hpp>

class Piece {
public:
    Piece(int initialShape[3][3], sf::Color color);
    void setPosition(sf::Vector2i position);
    void moveDown();
    void moveLeft();
    void moveRight();
    void drawPiece(sf::RenderWindow& window, int x, int y, int sizeOfBlock);
private:
    int shape[3][3];
    sf::Color pieceColor;
    sf::Vector2i currentPosition;
};


#endif //TETRIS_TERM_PROJECT_PIECE_H
