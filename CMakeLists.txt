cmake_minimum_required(VERSION 3.6)
project(neurons)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Neuron.cpp Neuron.h Network.cpp Network.h)
add_executable(neurons ${SOURCE_FILES})
