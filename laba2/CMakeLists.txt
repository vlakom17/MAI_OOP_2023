cmake_minimum_required(VERSION 3.10)
project(Labn2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(app lab2.cpp Binary.cpp)

enable_testing()
add_subdirectory(googletest)

add_executable(tests2 tests2.cpp)

target_link_libraries(tests2 PRIVATE GTest::gtest_main)
include(GoogleTest)
