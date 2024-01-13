#include <gtest/gtest.h>
#include "../src/temp.cpp" // here we include the code to be tested
TEST(keletTest, failedTest) {
EXPECT_EQ(firstInputCheck("234  876a"), 0);
}
TEST(keletTest, passedTest) {
EXPECT_EQ(firstInputCheck("234  564"), 1);
}
