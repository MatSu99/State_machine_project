cmake_minimum_required(VERSION 3.14)
project(unit_tests)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)
file(GLOB TESTS "*.cpp")
file(GLOB SOURCES "../sources/*.cpp")
list(REMOVE_ITEM SOURCES "../sources/main.cpp")
include_directories(../headers)

enable_testing()

add_executable(
  unit_tests
  ${TESTS}
)
target_link_libraries(
  unit_tests
  GTest::gtest_main
  ${SOURCES}
)

include(GoogleTest)
gtest_discover_tests(unit_tests)
