cmake_minimum_required(VERSION 3.10)
project(Labn5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(app main5.cpp alloc.hpp list.hpp)

enable_testing()
add_subdirectory(googletest)

add_executable(tests05 tests5.cpp)

target_link_libraries(tests05 PRIVATE GTest::gtest_main)
include(GoogleTest)