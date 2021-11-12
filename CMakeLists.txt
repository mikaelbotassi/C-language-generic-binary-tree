cmake_minimum_required(VERSION 3.20)
project(ArvoreBinaria C)

set(CMAKE_C_STANDARD 99)

add_executable(ArvoreBinaria main.c Utils/Studant.c BinaryTree/BinaryTree.c Utils/controleArquivo.c)
