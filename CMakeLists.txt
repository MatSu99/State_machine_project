cmake_minimum_required(VERSION 3.10)
project(State_machine_project)
project(State_machine_project VERSION 0.1)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)
include_directories(headers)
include_directories(sources)
file(GLOB SOURCES "sources/*.cpp")
file(GLOB TEST "tests/*.cpp")

enable_testing()
add_executable(State_machine_project ${SOURCES})



include(GoogleTest)
gtest_discover_tests(State_machine_project)