cmake_minimum_required(VERSION 3.28)
project(hexview VERSION 0.1.0 LANGUAGES C)
file(GLOB SOURCES src/*.c)
add_executable(${PROJECT_NAME} ${SOURCES})

# Testing
include(CTest)
enable_testing()

# Show output even on success
set(CMAKE_CTEST_ARGUMENTS "--output-on-failure" "--verbose")

add_test(NAME check_txt 
         COMMAND $<TARGET_FILE:${PROJECT_NAME}> ${CMAKE_SOURCE_DIR}/assets/file.txt)