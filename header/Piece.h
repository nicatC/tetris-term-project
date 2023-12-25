//
// Created by nevermind on 12/24/23.
//

#ifndef TETRIS_TERM_PROJECT_PIECE_H
#define TETRIS_TERM_PROJECT_PIECE_H
#include <SFML/Graphics.hpp>
#include "Board.h"
class Board;
class Piece {
public:
    Piece(int initialShape[3][3], sf::Color color, Board& gameBoard);
    void setPosition(sf::Vector2i position);
    void setCenter(sf::RenderWindow& window, int sizeOfBlock);
    void moveDown() ;
    void moveLeft();
    void moveRight();
    void drawPiece(sf::RenderWindow& window, int x, int y, int sizeOfBlock);
    bool checkCollision() const;
    void placeOnBoard();
    void applyBoard() ;
    const sf::Vector2i& getCurrentPosition() const{
        return currentPosition;
    };
    const int (*getShape() const)[3];
private:
    int shape[3][3];
    sf::Color pieceColor;
    sf::Vector2i currentPosition;
    Board& gameBoard;
};


#endif //TETRIS_TERM_PROJECT_PIECE_H
