//
// Created by nevermind on 12/24/23.
//

#include "../header/Piece.h"
#include "../header/Board.h"
#include <SFML/Graphics.hpp>

Piece::Piece(sf::RenderWindow& window, int defaultBlockSize, Board& gameBoard)
        : pieceColor(sf::Color::Green), gameBoard(gameBoard), fallSpeedMultiplier(2.0f) {
    // İlk parçayı rastgele seç
    srand(static_cast<unsigned int>(time(nullptr)));
    selectRandomPiece();
}



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
                if (currentPosition.y <= 0) {
                    gameBoard.setGameOver(true);
                }
            }
        }
    }
    currentPosition = sf::Vector2i(-1, -1);


}

void::Piece::selectRandomPiece(){
    PieceType types[] = { L, Plus , SmallSquare, CornerPiece, TallTower, Zigzag, UShape, StepShape, ArrowPointingUp, DoubleZigzag, Pyramid };
    currentPieceType = types[rand() % (sizeof(types) / sizeof(types[0]))];

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            shape[i][j] = 0;
        }
    }

    switch (currentPieceType) {
        case L:
            pieceColor = sf::Color::Black;
            shape[0][0] = shape[1][0] = shape[2][0] = shape[2][1] = 1;
            break;

        case Plus:
            pieceColor = sf::Color::Yellow;
            shape[0][1] = shape[1][1] = shape[2][1] = shape[1][0] = shape[1][2] = 1;
            break;
        case SmallSquare:
            pieceColor = sf::Color::Red;
            shape[0][0] = shape[0][1] = shape[1][0] = shape[1][1] = 1;
            break;

        case CornerPiece:
            pieceColor = sf::Color::Blue;
            shape[0][1] = shape[1][1] = shape[1][0] = 1;
            break;

        case TallTower:
            pieceColor = sf::Color::Cyan;
            shape[0][0] = shape[1][0] = shape[2][0] = 1;
            break;

        case Zigzag:
            pieceColor = sf::Color::Transparent;
            shape[0][1] = shape[1][0] = shape[1][1] = shape[2][0] = 1;
            break;

        case UShape:
            pieceColor = sf::Color::Black;
            shape[0][0] = shape[0][2] = shape[1][0] = shape[1][1] = shape[1][2] = 1;
            break;

        case StepShape:
            pieceColor = sf::Color::Red;
            shape[0][0] = shape[1][0] = shape[1][1] = shape[2][1] = 1;
            break;

        case ArrowPointingUp:
            pieceColor = sf::Color::Blue;
            shape[0][1] = shape[1][0] = shape[1][1] = shape[1][2] = shape[2][1] = 1;
            break;

        case DoubleZigzag:
            pieceColor = sf::Color::Red;
            shape[0][1] = shape[1][0] = shape[1][1] = shape[2][2] = 1;
            break;

        case Pyramid:
            pieceColor = sf::Color::Yellow;
            shape[0][1] = shape[1][0] = shape[1][1] = shape[1][2] = 1;
            break;

        default:
            break;
    }
}
void Piece::useCurrentPiece() {

    gameBoard.applyBoard(*this);
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
//-1 gun
void Piece::rotate() {
    int tempShape[3][3];
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            tempShape[i][j] = shape[i][j];
        }
    }

    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            shape[i][j] = tempShape[2 - j][i];
        }
    }

    rotationState = (rotationState + 1) % 4;
}
