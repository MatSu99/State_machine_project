#include <gtest/gtest.h>
#include "../headers/type_resource.h"
#include "../headers/file_handler.h"
#include "../headers/resource_manager.h"
class ResourceManagerSuite : public ::testing::Test {
    protected:

        void SetUp() override {
        }


        void TearDown() override {
            // N/A

        }
};

TEST_F(ResourceManagerSuite, InitializationT1) {
    ResourceManager ResourceManagerTest;

    ASSERT_EQ(ResourceManagerTest.checkConnectionPayment(false),false);
}