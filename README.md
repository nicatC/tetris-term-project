
This project is about creating a Tetris game using C++ and SFML. The main goal is to build a game with interactive features, like moving and rotating pieces, and a graphical display.
Methodology
I tried to approached the project by breaking it into two main parts: the Piece and the Board. The main aim of the piece class is  handling individual tetris pieces, and the board class manages the game board. I used sfml to deal with graphics and user input.
The new things that learned are how to rotate pieces, checking for collisions, and manage when the game is over. I tried to organized the code using object-oriented programming principles.
Implementation
    • Piece Class
        ◦ Represents Tetris pieces with different shapes and colors.
        ◦ Takes care of moving, rotating, and avoiding collisions.
        ◦ Randomly selects pieces.
    • Board Class:
        ◦ Manages the game board grid and keeps track of filled cells.
        ◦ Checks for game over conditions and updates the game state.
        ◦ Works with the Piece class to run the game.
    • User Interface:
        ◦ Uses SFML for drawing graphics and handling user input.
        ◦ Handles basic window functions.
Decisions:
    • The game uses a fixed-size grid, which might limit how big it can get.
    • I tried to focus more on making the game work rather than making it look fancy.
Results
The game not works so well because there is some bugs in code and I cant catch them so the game frequently crash and snoozed but the good things are players can move, rotate, and drop pieces accurately. The game knows when pieces hit the bottom, and it stops when the board is full.
Conclusion
In short, our Tetris Game project successfully brings the classic game to life using C++ and SFML. We designed it so that it can grow in the future. However, there's room to make it look better and add more features. Future work might involve improving how it looks and making it run even smoother.

