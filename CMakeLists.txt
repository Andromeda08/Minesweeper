cmake_minimum_required(VERSION 3.17)
project(Minesweeper C)

set(CMAKE_C_STANDARD 99)

add_executable(Minesweeper main.c minesweeper.c minesweeper.h render.c render.h mainMenu.c mainMenu.h)