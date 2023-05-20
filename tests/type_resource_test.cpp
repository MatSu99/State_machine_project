#include <gtest/gtest.h>
#include "../headers/type_resource.h"

TEST(TypeResource, Initialization) {
    Resource Test_Resource;

    EXPECT_EQ(Test_Resource.GetResourceID() , 0);
    EXPECT_EQ(Test_Resource.GetResourceName(), "");
    EXPECT_EQ(Test_Resource.GetReourcePrice(), 0);
    EXPECT_EQ(Test_Resource.GetAmountOfResource(), 0);
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

TEST( TypeResource, SettingNewPrice) {
    Resource Test_Resource;

    Test_Resource.SetPrice(4000);

    EXPECT_EQ(Test_Resource.GetReourcePrice(), 4000);

}

TEST(TypeResource, GetResourceDataAsString) {
    Resource Test_Resource;

    std::string Expected_Result = "Resource ID: 0\n"
    "Resource name: \nPrice: 0\nAmount: 0";

    EXPECT_EQ(Test_Resource.GetResourceData(), Expected_Result);
}