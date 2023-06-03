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

TEST_F(ResourceManagerSuite, CreateResourceObjectT1) {
    ResourceManager ResourceManagerTest;
    std::shared_ptr<Resource> SPtrToResource = ResourceManagerTest.CreateResourceObject(0, "", 0, 0);
    
    std::string Expected_ResultOneResource = "Resource ID: 0\n"
    "Resource name: \nPrice: 0\nAmount: 0";
    ASSERT_EQ(SPtrToResource->GetResourceData(), Expected_ResultOneResource);
}

TEST_F(ResourceManagerSuite, PutResourceIntoVectorT1) {
    ResourceManager ResourceManagerTest;
    std::shared_ptr<Resource> SPtrToResource = ResourceManagerTest.CreateResourceObject(0, "", 0, 0);
    ResourceManagerTest.PutResourceIntoVector(*SPtrToResource);

    Resource* PtrToObject = ResourceManagerTest.GetSpecificResourceRP(0);
    std::string Expected_ResultOneResource = "Resource ID: 0\n"
    "Resource name: \nPrice: 0\nAmount: 0";

    ASSERT_EQ(PtrToObject->GetResourceData(),Expected_ResultOneResource);
}