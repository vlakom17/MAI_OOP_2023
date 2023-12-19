cmake_minimum_required(VERSION 3.10)
project(Labn6)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(app main6.cpp dragon.cpp knight.cpp observer.cpp frog.cpp npc.cpp)

enable_testing()
add_subdirectory(googletest)

add_executable(tests6 tests6.cpp)

target_link_libraries(tests6 PRIVATE GTest::gtest_main)
include(GoogleTest)