#include <gtest/gtest.h>
#include "../headers/file_handler.h"

TEST(FileHandlerTest, CheckIfFileExists) {
    FileHandler Test_FileHandler;

    ASSERT_EQ(Test_FileHandler.CheckIfFileExists("/home/nox/Dev/cpp_projects/state_machine_proj/tests/dummyfile.txt"), true);
}