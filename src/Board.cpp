//
// Created by nevermind on 12/24/23.
//

#include "../header/Board.h"
#include <SFML/Graphics.hpp>

Board::Board() {
    for (int i = 0; i <boardHeight ; ++i) {
        for (int j = 0; j <boardWidth ; ++j) {
            grid[i][j] = 0;
        }
    }
}

void Board::update() {
    //for future implementation amk
}

void Board::render(sf::RenderWindow &window) {
    for (int i = 0; i <boardHeight ; ++i) {
        for (int j = 0; j < boardWidth; ++j) {
            sf::RectangleShape block(sf::Vector2f(30,30));
            block.setPosition(j*50, i*50);
            if (grid[i][j]==0){
                block.setFillColor(sf::Color::White);
            }else{
                block.setFillColor(sf::Color::Green);
            }
            window.draw(block);
        }
    }
}