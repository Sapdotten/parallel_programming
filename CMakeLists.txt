cmake_minimum_required(VERSION 3.16)
project(App LANGUAGES CXX)


add_executable(App
        src/main.cpp
        src/matrix.cpp
        include/matrix.h
)

