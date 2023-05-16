#include <gtest/gtest.h>
#include "../headers/type_resource.h"

TEST(TypeResource, Initialization) {
    Resource Test_Resource;

    EXPECT_EQ(Test_Resource.GetResourceID() , 0);
    EXPECT_EQ(Test_Resource.GetResourceName(), "");
    EXPECT_EQ(Test_Resource.GetReourcePrice(), 0);

}

TEST(TypeResource, FetchingData) {
    Resource Test_Resource;

    int ID = 1;
    std::string Name = "Test_name";
    int Price = 10;
    int Amount = 20;

    Test_Resource.FetchResoucreData(ID, Name, Price, Amount);

    EXPECT_EQ(Test_Resource.GetResourceID() , ID);
    EXPECT_EQ(Test_Resource.GetResourceName(), Name);
    EXPECT_EQ(Test_Resource.GetReourcePrice(), Price);
    EXPECT_EQ(Test_Resource.GetAmountOfResource(), Amount);
}