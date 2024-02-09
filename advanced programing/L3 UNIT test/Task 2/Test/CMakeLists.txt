cmake_minimum_required(VERSION 3.20)
project(Test_List)
file(GLOB src "../src/List.cpp" "../src/List.h")
include_directories("../src")

add_subdirectory(../Catch2 Catch2-build)
add_executable(Test_List ${src} test_List_main.cpp)
target_link_libraries(Test_List PRIVATE Catch2::Catch2)
