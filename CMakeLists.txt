cmake_minimum_required(VERSION 3.6)
project(olga)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Person.cpp Person.h)
add_executable(olga ${SOURCE_FILES} Person.cpp Person.h)