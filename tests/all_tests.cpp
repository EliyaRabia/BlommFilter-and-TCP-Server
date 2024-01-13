#include <gtest/gtest.h>
#include "../src/functions.cpp" 
TEST(StringTest, BasicTest) {
EXPECT_EQ(isCustomURL("aa"), 0);
}
TEST(StringTest1, BasicTest2) {
EXPECT_EQ(isCustomURL("www.david.com"), 1);
}
TEST(keletTest, failedTest) {
EXPECT_EQ(firstInputCheck("234  876a"), 0);
}
TEST(keletTest1, passedTest) {
EXPECT_EQ(firstInputCheck("234  564"), 1);
}