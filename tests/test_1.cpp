#include <gtest/gtest.h>
#include "../headers/type_resource.h"

// Demonstrate some basic assertions.

TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

TEST(FirstTest, TestOne) {
  Resource Test_Resource;
  int ID = Test_Resource.GetResourceID();
  EXPECT_EQ(ID , 0);
}
