cmake_minimum_required(VERSION 3.10)
project(Labn7)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(app main7.cpp dragon.cpp knight.cpp frog.cpp npc.cpp)

enable_testing()
add_subdirectory(googletest)

add_executable(tests7 tests7.cpp)

target_link_libraries(tests7 PRIVATE GTest::gtest_main)


find_package(Threads REQUIRED)
target_link_libraries(app Threads::Threads)

include(GoogleTest)