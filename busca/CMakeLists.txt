cmake_minimum_required(VERSION 2.4)

project(AlgoritmosDeBusca)

include_directories(./include)

add_executable(buscas ./src/main.cpp ./src/utils.cpp ./src/linear-search.cpp ./src/binary-search.cpp ./src/ternary-search.cpp ./src/fibonacci-search.cpp ./src/jump-search.cpp)
