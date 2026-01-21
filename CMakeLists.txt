cmake_minimum_required(VERSION 3.28)
project(hexview VERSION 0.1.0 LANGUAGES C)
file(GLOB SOURCES src/*.c)
add_executable(${PROJECT_NAME} ${SOURCES})
