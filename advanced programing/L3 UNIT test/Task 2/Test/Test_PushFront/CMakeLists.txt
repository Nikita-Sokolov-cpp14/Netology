cmake_minimum_required(VERSION 3.20)
project(Test_PushFront)
file(GLOB src "../../Project/Sources/*.cpp" "../../Project/Headers/*.h")
include_directories("../../Project")

add_subdirectory(../../Catch2 Catch2-build)
add_executable(Test_PushFront ${src} test_PushFront_main.cpp)
target_link_libraries(Test_PushFront PRIVATE Catch2::Catch2)
