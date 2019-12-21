cmake_minimum_required(VERSION 3.10.2)
project(oop_exercise_07)

set(CMAKE_CXX_STANDARD 17)

add_executable(oop_exercise_07 main.cpp point.h hexagon.h hexagon.cpp figure.h point.cpp pentagon.cpp pentagon.h octagon.cpp octagon.h document.h factory.h command.h editor.h document.cpp factory.cpp editor.cpp command.cpp)
