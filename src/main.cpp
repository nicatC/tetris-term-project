#include <iostream>
#include <SFML/Graphics.hpp>
#include "../header/Piece.h"
#include "../header/Board.h"
using std::cout;


int main() {

    sf::RenderWindow window(sf::VideoMode(900,1500), "TETRIS");
    int defaultBlockSize = 50;
    int lShape[3][3]= {{1,0,0},{1,1,1},{0,0,0}};
    int plusShape[3][3] = {{0,1,0},{1,1,1},{0,1,0}};

    Board gameBoard(window, defaultBlockSize);

    Piece lPiece(lShape, sf::Color::Green, gameBoard);
    Piece plusPiece(plusShape,sf::Color::Yellow, gameBoard);
    lPiece.setCenter(window,defaultBlockSize);

    sf::Clock clock;
    sf::Time elapsed = sf::Time::Zero;
    sf::Time moveInterval = sf::seconds(0.5);

    while (window.isOpen()){
        sf::Event event;
        window.setFramerateLimit(60);

        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        elapsed += clock.restart();
        if (elapsed >= moveInterval) {
            if (!lPiece.checkCollision()) {
                lPiece.moveDown();
            } else {
                lPiece.applyBoard();
                lPiece.setCenter(window, defaultBlockSize);
            }

            elapsed = sf::Time::Zero;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            lPiece.moveLeft();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            lPiece.moveRight();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            lPiece.moveDownFast(gameBoard);
        }
        window.clear(sf::Color::White);
        lPiece.drawPiece(window, 0,0,defaultBlockSize);
        gameBoard.render(window);

        window.display();

    }

    return 0;
}
