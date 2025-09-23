cmake_minimum_required(VERSION 4.0)
project(Projeto_de_Algoritmos)

set(CMAKE_CXX_STANDARD 20)

add_executable(Projeto_de_Algoritmos
        main.cpp
        InsertionSort/insertionsort.cpp
        InsertionSort/insertionsort.h
        gerarentradas.h
        gerarentradas.cpp
        salvararquivos.h
        salvararquivos.cpp)
