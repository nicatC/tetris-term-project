//
// Created by nevermind on 12/24/23.
//

#include "../header/Piece.h"
#include "../header/Board.h"
#include <SFML/Graphics.hpp>
Piece::Piece(int (*initialShape)[3], sf::Color color, Board& gameBoard) : pieceColor(color), gameBoard(gameBoard), fallSpeedMultiplier(2.0f) {
    for(int i=0; i<3; i++){
        for (int j = 0; j < 3; ++j) {
            shape[i][j]= initialShape[i][j];
        }
    }
};
void Piece::setPosition(sf::Vector2i position) {
    currentPosition = position;
}

void Piece::setCenter(sf::RenderWindow& window, int sizeOfBlock) {
    int centerX= window.getSize().x/ 2 - (3*sizeOfBlock) /2;
    int centerY= window.getSize().y /6 - (3* sizeOfBlock) /2;

    currentPosition = sf::Vector2i(centerX / sizeOfBlock, centerY / sizeOfBlock);
}

void Piece::moveDown() {
    if (!checkCollision()) {
        currentPosition.y += 1;
    } else {
        currentPosition.y -= 1;
        applyBoard();
    }
}
void Piece::moveDownFast(Board& gameBoard) {
    if (checkCollision()) {
        applyBoard();
    } else {
        currentPosition.y += static_cast<int>(fallSpeedMultiplier);
    }
}
void Piece::moveLeft() {
    if (!checkCollisionLeft()) {
        currentPosition.x -= 1;
    }

}

void Piece::moveRight() {
    if (!checkCollisionRight()) {
        currentPosition.x += 1;
    }
}


bool Piece::checkCollision() const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (shape[i][j] == 1) {
                int boardX = currentPosition.x + j;
                int boardY = currentPosition.y + i + 1;
                if (boardY >= gameBoard.getBoardHeight() || gameBoard.isOccupied(boardX, boardY)) {
                    return true;
                }
            }
        }
    }
    return false;
}
bool Piece::checkCollisionRight() const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (shape[i][j] == 1) {
                int boardX = currentPosition.x + j + 1;
                int boardY = currentPosition.y + i;
                if (boardX >= gameBoard.getBoardWidth()) {
                    return true;
                }
                if (boardX < gameBoard.getBoardWidth() && gameBoard.isOccupied(boardX, boardY)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Piece::checkCollisionLeft() const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (shape[i][j] == 1) {
                int boardX = currentPosition.x + j - 1;
                int boardY = currentPosition.y + i;

                if (boardX < 0 || gameBoard.isOccupied(boardX, boardY)) {
                    return true;
                }
            }
        }
    }
    return false;
}


void Piece::placeOnBoard() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (shape[i][j] == 1) {
                int boardX = currentPosition.x + j;
                int boardY = currentPosition.y + i;
                gameBoard.setGridCell(boardX, boardY, 1);
            }
        }
    }
}


const int (*Piece::getShape() const)[3] {
    return shape;
}
void Piece::applyBoard() {

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (shape[i][j] == 1) {
                int boardX = currentPosition.x + j;
                int boardY = currentPosition.y + i;
                gameBoard.setOccupied(boardX, boardY); // tahtada bu konumu işaretlemek icin
            }
        }
    }
    currentPosition = sf::Vector2i(-1, -1);
}
void Piece::drawPiece(sf::RenderWindow &window, int x, int y, int sizeOfBlock) {
    sf::RectangleShape block(sf::Vector2f(sizeOfBlock, sizeOfBlock));
    block.setOutlineThickness(1);
    block.setOutlineColor(sf::Color::Black);
    for (int i = 0; i <3 ; ++i) {
        for (int j = 0; j <3 ; ++j) {
            if(shape[i][j]==1){
                block.setFillColor(pieceColor);
                block.setPosition((currentPosition.x+j)* sizeOfBlock, (currentPosition.y +i)* sizeOfBlock);
                window.draw(block);

            }
        }
    }
}
