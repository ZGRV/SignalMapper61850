cmake_minimum_required(VERSION 3.10)

project(SignalMapper61850)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add an executable
add_executable(signal_mapper
        src/main.cpp
        src/comtrade/comtrade_parser.cpp)
target_include_directories(signal_mapper PUBLIC src)





