#include <gtest/gtest.h>
#include "../src/functions.cpp" // here we include the code to be tested
TEST(keletTest, failedTest) {
EXPECT_EQ(firstInputCheck("234  876a"), 0);
}
TEST(keletTest1, failedTest1) {
EXPECT_EQ(firstInputCheck("234  564"), 0);
}
TEST(keletTest2, passedTest) {
EXPECT_EQ(firstInputCheck("234  2"), 2);
}
TEST(keletTest3, passedTest) {
EXPECT_EQ(firstInputCheck("234  2 11"), 3);
}

TEST(UrlTest, basicTest) {
EXPECT_EQ(isCustomURL("aa"), 0);
}
TEST(UrlTest2, basicTest2) {
EXPECT_EQ(isCustomURL("www.work.com"), 1);
}