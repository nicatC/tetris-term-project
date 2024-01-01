//
// Created by nevermind on 12/24/23.
//

#ifndef TETRIS_TERM_PROJECT_PIECE_H
#define TETRIS_TERM_PROJECT_PIECE_H

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include "Board.h"

class Board;
class Piece {
public:
    enum PieceType { L, Plus, SmallSquare, CornerPiece, TallTower, Zigzag, UShape, StepShape, ArrowPointingUp, DoubleZigzag, Pyramid};
    Piece(sf::RenderWindow& window, int defaultBlockSize, Board& gameBoard);
    //Piece(int initialShape[3][3], sf::Color color, Board& gameBoard);
    //Piece(int[3]);
    void selectRandomPiece();
    void useCurrentPiece();
    void setPosition(sf::Vector2i position);
    void setCenter(sf::RenderWindow& window, int sizeOfBlock);
    void moveDown() ;
    void moveLeft();
    void moveRight();
    void drawPiece(sf::RenderWindow& window, int x, int y, int sizeOfBlock);
    bool checkCollision() const;
    bool checkCollisionRight() const;
    bool checkCollisionLeft() const;
    bool checkCollisionUp() const;
    void placeOnBoard();
    void moveDownFast(Board& gameBoard);
    void applyBoard() ;

    const sf::Vector2i& getCurrentPosition() const{
        return currentPosition;
    };
    const int (*getShape() const)[3];
    static const int lShape[3][3];
    static const int plusShape[3][3];
private:
    int shape[3][3];
    sf::Color pieceColor;
    sf::Vector2i currentPosition;
    Board& gameBoard;
    float fallSpeedMultiplier;
    //sf::RenderWindow& window;
    PieceType currentPieceType;

};


#endif //TETRIS_TERM_PROJECT_PIECE_H
