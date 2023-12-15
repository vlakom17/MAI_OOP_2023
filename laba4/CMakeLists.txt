cmake_minimum_required(VERSION 3.10)
project(Labn4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(app main.cpp array.hpp pentagon.hpp hexagon.hpp rhomb.hpp)

enable_testing()
add_subdirectory(googletest)

add_executable(tests04 tests04.cpp)

target_link_libraries(tests04 PRIVATE GTest::gtest_main)
include(GoogleTest)