cmake_minimum_required(VERSION 3.20)
project(zert)

set(CMAKE_CXX_STANDARD 17)

add_executable(zert main.cpp lexer.h token.h)
