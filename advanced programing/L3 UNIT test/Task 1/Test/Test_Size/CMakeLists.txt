cmake_minimum_required(VERSION 3.20)
project(Test_Size)
file(GLOB src "../../Project/Sources/*.cpp" "../../Project/Headers/*.h")
include_directories("../../Project")

add_subdirectory(../../Catch2 Catch2-build)
add_executable(Test_Size ${src} test_Size_main.cpp)
target_link_libraries(Test_Size PRIVATE Catch2::Catch2)
