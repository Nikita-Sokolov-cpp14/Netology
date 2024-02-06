cmake_minimum_required(VERSION 3.20)
project(Test_Empty)
file(GLOB src "../../Project/Sources/*.cpp" "../../Project/Headers/*.h")
include_directories("../../Project")

add_subdirectory(../../Catch2 Catch2-build)
add_executable(Test_Empty ${src} test_Empty_main.cpp)
target_link_libraries(Test_Empty PRIVATE Catch2::Catch2)
