cmake_minimum_required(VERSION 3.10)
project(State_machine_project)
project(State_machine_project VERSION 0.1)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(headers)
include_directories(sources)
file(GLOB SOURCES "sources/*.cpp")
file(GLOB TEST "tests/*.cpp")


add_executable(State_machine_project ${SOURCES})



