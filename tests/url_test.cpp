#include <gtest/gtest.h>
#include "../src/task2.cpp" 
TEST(StringTest, BasicTest) {
EXPECT_EQ(isCustomURL("aa"), 0);
}
TEST(StringTest1, BasicTest2) {
EXPECT_EQ(isCustomURL("www.david.com"), 1);
}
