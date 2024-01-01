#include <iostream>
#include <SFML/Graphics.hpp>
#include "../header/Piece.h"
#include "../header/Board.h"
using std::cout;


int main() {

    sf::RenderWindow window(sf::VideoMode(900,1500), "TETRIS");
    window.setFramerateLimit(60);
    int defaultBlockSize = 50;
    //int lShape[3][3]= {{1,0,0},{1,0,0},{1,1,1}};
    //int plusShape[3][3] = {{0,1,0},{1,1,1},{0,1,0}};

    Board gameBoard(window, defaultBlockSize);
    Piece currentPiece(window, defaultBlockSize, gameBoard);



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
            if (!currentPiece.checkCollision()) {
                currentPiece.moveDown();
            } else {
                currentPiece.applyBoard();
                currentPiece.setCenter(window, defaultBlockSize);
                currentPiece.selectRandomPiece();
            }

            elapsed = sf::Time::Zero;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            currentPiece.moveLeft();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            currentPiece.moveRight();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            if (!currentPiece.checkCollision()) {
                currentPiece.moveDownFast(gameBoard);
            } else {
                currentPiece.applyBoard();
                currentPiece.setCenter(window, defaultBlockSize);
                currentPiece.selectRandomPiece();
            }
        }
        window.clear(sf::Color::White);
        currentPiece.drawPiece(window, 0,0,defaultBlockSize);
        gameBoard.render(window);

        window.display();

    }

    return 0;
}
