//
// Created by nevermind on 12/24/23.
//

#include "../header/Piece.h"
#include <SFML/Graphics.hpp>
Piece::Piece(int (*initialShape)[3], sf::Color color) : pieceColor(color) {
    for(int i=0; i<3; i++){
        for (int j = 0; j < 3; ++j) {
            shape[i][j]= initialShape[i][j];
        }
    }
};

void Piece::setPosition(sf::Vector2i position) {
    currentPosition = position;
}

void Piece::moveDown() {
    currentPosition.y += 1;
}

void Piece::moveLeft() {
    currentPosition.x -= 1;
}

void Piece::moveRight() {
    currentPosition.x += 1;
}

void Piece::drawPiece(sf::RenderWindow &window, int x, int y, int sizeOfBlock) {
    sf::RectangleShape block(sf::Vector2f(sizeOfBlock, sizeOfBlock));
    block.setOutlineThickness(1);
    block.setOutlineColor(sf::Color::Black);
    for (int i = 0; i <3 ; ++i) {
        for (int j = 0; j <3 ; ++j) {
            if(shape[i][j]==1){
                block.setFillColor(pieceColor);
                block.setPosition((j)* sizeOfBlock, (i)*sizeOfBlock);
                window.draw(block);

            }
        }
    }
}
