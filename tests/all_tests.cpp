#include <gtest/gtest.h>
#include "../src/functions.cpp" // here we include the code to be tested
TEST(keletTest, failedTest) {
EXPECT_EQ(firstInputCheck("234  876a"), 0);
}
TEST(keletTest1, passedTest) {
EXPECT_EQ(firstInputCheck("234  564"), 1);
}
TEST(UrlTest, basicTest) {
EXPECT_EQ(isCustomURL("aa"), 0);
}
TEST(UrlTest2, basicTest2) {
EXPECT_EQ(isCustomURL("www.work.com"), 1);
}