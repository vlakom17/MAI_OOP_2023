cmake_minimum_required(VERSION 3.10)
project(Labn3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(app main3.cpp array.cpp pentagon.cpp hexagon.cpp rhomb.cpp)

enable_testing()
add_subdirectory(googletest)

add_executable(tests3 tests3.cpp)

target_link_libraries(tests3 PRIVATE GTest::gtest_main)
include(GoogleTest)