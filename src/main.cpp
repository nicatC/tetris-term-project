#include <iostream>
#include <SFML/Graphics.hpp>
#include "../header/Piece.h"
#include "../header/Board.h"
using std::cout;


int main() {
    sf::RenderWindow window(sf::VideoMode(900,900), "TETRIS");
    int defaultBlockSize = 50;
    int lShape[3][3]= {{1,0,0},{1,1,1},{0,0,0}};

    Piece lPiece(lShape, sf::Color::Green);
    lPiece.setPosition(sf::Vector2i(100,100));

    sf::Clock clock;
    sf::Time elapsed = sf::Time::Zero;
    sf::Time moveInterval = sf::seconds(0.5);

    while (window.isOpen()){
        sf::Event event;

        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        elapsed += clock.restart();
        if (elapsed >= moveInterval) {
            lPiece.moveDown();
            elapsed = sf::Time::Zero;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            lPiece.moveLeft();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            lPiece.moveRight();
        }
        window.clear(sf::Color::White);
        lPiece.drawPiece(window, 50,50,defaultBlockSize);
        window.display();

    }

    return 0;
}
