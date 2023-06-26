#include <gtest/gtest.h>
#include "../headers/info_hub.h"

TEST(InfoHubTest, InitializeDataHub) {
    InfoHub InfoHubTest;

    ASSERT_EQ(InfoHubTest.GetName(), "");
}