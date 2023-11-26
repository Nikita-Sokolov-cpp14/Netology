CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
project(Greet_lib)
set(Source_LIB class.cpp)
add_library(Greet_lib STATIC ${Source_LIB})
