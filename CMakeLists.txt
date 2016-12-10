cmake_minimum_required(VERSION 3.6)
project(olga)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Converter.cpp Converter.h List.cpp List.h Mass.cpp Mass.h)
add_executable(olga ${SOURCE_FILES} List.h List.cpp)