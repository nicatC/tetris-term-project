//
// Created by nevermind on 12/24/23.
//

#include "../header/Board.h"
#include <SFML/Graphics.hpp>


Board::Board(sf::RenderWindow& window, int defaultBlockSize) : window(window), defaultBlockSize(defaultBlockSize) {
    for (int i = 0; i < boardHeight; ++i) {
        for (int j = 0; j < boardWidth; ++j) {
            grid[i][j] = 0;
        }
    }
}

void Board::update(Piece& piece, sf::RenderWindow& window, int defaultBlockSize) {
    if (!piece.checkCollision()) {
        piece.moveDown();
    } else {
        piece.applyBoard();
        piece.setCenter(window, defaultBlockSize);
    }
}

void Board::render(sf::RenderWindow &window) {
    for (int i = 0; i < boardHeight; ++i) {
        for (int j = 0; j < boardWidth; ++j) {
            sf::RectangleShape block(sf::Vector2f(30, 30));
            block.setPosition(j * 50, i * 50);
            if (grid[i][j] == 0) {
                block.setFillColor(sf::Color::White);
            } else {
                block.setFillColor(sf::Color::Green);
            }
            window.draw(block);
        }
    }
}
void Board::applyBoard(const Piece& piece) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (piece.getShape()[i][j] == 1) {
                int boardX = piece.getCurrentPosition().x + j;
                int boardY = piece.getCurrentPosition().y + i;
                grid[boardY][boardX] = 1;
            }
        }
    }
}
void Board::setOccupied(int x, int y) {
    grid[y][x] = 1;
}

void Board::setGridCell(int x, int y, int value) {
    grid[y][x] = value;
}
int Board::getBoardWidth() const {
    return boardWidth;
}
bool Board::isCollision(const Piece& piece) const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (piece.getShape()[i][j] == 1) {
                int boardX = piece.getCurrentPosition().x + j;
                int boardY = piece.getCurrentPosition().y + i + 1;
                if (boardY >= boardHeight || isOccupied(boardX, boardY)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Board::isOccupied(int x, int y) const {

    return grid[y][x] == 1;
}