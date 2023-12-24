cmake_minimum_required(VERSION 3.26)
project(tetris_term_project)

set(CMAKE_CXX_STANDARD 17)
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(tetris_term_project src/main.cpp
        src/Piece.cpp
        header/Piece.h
        src/Board.cpp
        header/Board.h)
target_link_libraries(tetris_term_project PRIVATE sfml-graphics sfml-window sfml-system)