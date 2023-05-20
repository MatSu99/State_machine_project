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
get_filename_component(path_to_sources ${CMAKE_CURRENT_SOURCE_DIR}/../sources/*.cpp ABSOLUTE)
message("${path_to_sources}")
file(GLOB SOURCES "${path_to_sources}")
variable_watch(SOURCES)
get_filename_component(full_path_to_main ${CMAKE_CURRENT_SOURCE_DIR}tests/../sources/main.cpp ABSOLUTE)
message("${full_path_to_main}")
list(REMOVE_ITEM SOURCES "${full_path_to_main}")
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
