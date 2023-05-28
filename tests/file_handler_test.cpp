#include <gtest/gtest.h>
#include "../headers/file_handler.h"

class FileHandlerFixture : public ::testing::Test {
    protected:
    std::string PathToDummy = "/home/nox/Dev/cpp_projects/state_machine_proj/tests/dummyfile.txt";
    std::vector<int> CoinsVector;
        void SetUp() override {
            // N/A
            CoinsVector.push_back(20);
            CoinsVector.push_back(20);
            CoinsVector.push_back(20);
            CoinsVector.push_back(20);
            CoinsVector.push_back(20);
            CoinsVector.push_back(20);
            CoinsVector.push_back(20);
            CoinsVector.push_back(20);

        }

        void RestoreFilesToDefaultState() {
            std::string coins_default = "20\n20\n20\n20\n20\n20\n20\n20";
            std::string resources_default = "1|Apple Juice|150|20|"
                                            "2|Orange Juice|160|20|"
                                            "3|Milk chocolate|300|10|"
                                            "4|Dark chocolate|310|10|"
                                            "5|Oatmeal bar|400|10|";

            std::ofstream File;
            File.open("/home/nox/Dev/cpp_projects/state_machine_proj/tests/test_res/resources.txt", std::ios::out);

            if(File.good() == false) {
            // ! ERROR
            return;
            }

            File << resources_default;
            File.close();

            File.open("/home/nox/Dev/cpp_projects/state_machine_proj/tests/test_res/coins.txt", std::ios::out);
            if(File.good() == false) {
            // ! ERROR
            return;
            }

            File << coins_default;
            File.close();

            return;
        }

        void TearDown() override {
            // N/A
            CoinsVector.clear();
            CoinsVector.shrink_to_fit();
            RestoreFilesToDefaultState();
        }

};

TEST(FileHandlerTest, CheckIfFileExistsT1) {
    FileHandler Test_FileHandler;

    ASSERT_EQ(Test_FileHandler.CheckIfFileExists("/home/nox/Dev/cpp_projects/state_machine_proj/tests/dummyfile.txt"), true);
}

TEST_F(FileHandlerFixture, ChechIfFileExistsT2) {
    FileHandler Test_FileHandler;

    ASSERT_EQ(Test_FileHandler.CheckIfFileExists(FileHandlerFixture::PathToDummy), true);
}

TEST(FileHandlerTest, GetInfoFromFileT1) {
    FileHandler Test_FileHandler;

    ASSERT_EQ(Test_FileHandler.GetInfoFromFile("/home/nox/Dev/cpp_projects/state_machine_proj/tests/test_res/resources.txt"),
    "1|Apple Juice|150|20|"
    "2|Orange Juice|160|20|"
    "3|Milk chocolate|300|10|"
    "4|Dark chocolate|310|10|"
    "5|Oatmeal bar|400|10|");
}

TEST_F(FileHandlerFixture, GetInfoCoinsT1) {
    FileHandler Test_FileHandler;
    std::vector<int> ResultFromFunction;

    ResultFromFunction = Test_FileHandler.GetInfoCoins("/home/nox/Dev/cpp_projects/state_machine_proj/tests/test_res/coins.txt");
    ASSERT_EQ(ResultFromFunction, CoinsVector);
}

TEST_F(FileHandlerFixture, ModifyFileT1) {
    FileHandler Test_FileHandler;
    std::vector<int> ResultFromFunction;

    Test_FileHandler.ModifyFile("/home/nox/Dev/cpp_projects/state_machine_proj/tests/test_res/coins.txt","10\n20\n20\n20\n20\n20\n20\n20");
    CoinsVector[0] = 10;
    ResultFromFunction = Test_FileHandler.GetInfoCoins("/home/nox/Dev/cpp_projects/state_machine_proj/tests/test_res/coins.txt");

    ASSERT_EQ(ResultFromFunction, CoinsVector);
}