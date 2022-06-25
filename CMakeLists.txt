cmake_minimum_required(VERSION 3.21)
project(minesweeper)

set(CMAKE_CXX_STANDARD 17)

add_library(default INTERFACE)
target_compile_features(default INTERFACE cxx_std_17)
enable_testing()

add_executable(minesweeper src/main.cpp src/utils.h src/Cell.cpp src/Cell.h src/Field.cpp src/Field.h src/Game.cpp src/Game.h src/utils.h)

# Taken from homework files
add_library(doctest STATIC external/doctest.cpp)
target_include_directories(doctest PUBLIC external/ src/)
set_target_properties(doctest PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED ON)
add_library(doctest::doctest ALIAS doctest)
add_library(Catch2::Catch2 ALIAS doctest)

add_executable(project-tests tests/cell_test.cpp tests/field_test.cpp tests/game_test.cpp src/Cell.cpp src/Field.cpp src/Game.cpp src/Cell.h src/Field.h src/Game.h)
target_link_libraries(project-tests PUBLIC doctest default)
add_test(NAME project-tests COMMAND project-tests --force-colors -d)

