CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
project(Greet_project)
include_directories(Lib)
set(Source main.cpp)

add_executable(Greet_project ${Source})
add_subdirectory(Lib)
target_link_libraries(Greet_project Greet_lib)
