#include <iostream>
#include <SFML/Graphics.hpp>
#include "../header/Piece.h"
#include "../header/Board.h"
using std::cout;


int main() {

    sf::RenderWindow window(sf::VideoMode(900,1500), "TETRIS");
    window.setFramerateLimit(60);
    int defaultBlockSize = 50;

    Board gameBoard(window, defaultBlockSize);
    Piece currentPiece(window, defaultBlockSize, gameBoard);

    sf::Text text;
    sf::Text restartText;
    sf::Font font;

    sf::Clock clock;
    sf::Clock debounceClock;// rotation icin enter a basildiginda bir cok kez rotate ediyor, tusa basmaya sinirlama getirmek icin ekledim.
    const sf::Time debounceTime = sf::milliseconds(200);
    sf::Time elapsed = sf::Time::Zero;
    sf::Time moveInterval = sf::seconds(0.5);

    while (window.isOpen()){
        sf::Event event;


        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        if (gameBoard.isGameOver()) {



            if (!font.loadFromFile("../fonts/font.ttf")) {
                return EXIT_FAILURE;
            }

            text.setFont(font);
            text.setString("Game Over!");
            text.setCharacterSize(50);
            text.setPosition(300, 500);
            text.setFillColor(sf::Color::Red);

            restartText.setFont(font);
            restartText.setString("Restart?");
            restartText.setCharacterSize(50);
            restartText.setPosition(300, 300);
            restartText.setFillColor(sf::Color::Blue);

            window.draw(restartText);
            window.draw(text);
            window.display();

            sf::sleep(sf::seconds(10));//restart a basabilmek icin 10 saniye aksi takdirde oyudan cikacak fakat, restart a basmayi bir turlu beceremedim cunku oyun her seferinde cokuyor
            window.close();
            return 0;
        }
        elapsed += clock.restart();
        if (elapsed >= moveInterval) {
            if (!currentPiece.checkCollision()) {
                currentPiece.moveDown();
            } else {
                currentPiece.applyBoard();
                currentPiece.setCenter(window, defaultBlockSize);
                currentPiece.selectRandomPiece();

                if (currentPiece.checkCollision()) {
                    gameBoard.setGameOver(true);
                }
            }

            elapsed = sf::Time::Zero;
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            if (restartText.getGlobalBounds().contains(static_cast<float>(mousePosition.x),
                                                       static_cast<float>(mousePosition.y))) {
                gameBoard.restart();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            currentPiece.moveLeft();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            currentPiece.moveRight();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            if (debounceClock.getElapsedTime() > debounceTime) {
                currentPiece.rotate();
                debounceClock.restart();
            }
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
