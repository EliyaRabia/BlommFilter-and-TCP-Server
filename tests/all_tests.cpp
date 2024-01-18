#include <gtest/gtest.h>
#include "../src/Console_Menu.cpp"
TEST(kelet,pass){
    Console_Menu a;
    EXPECT_EQ(a.GetArray_size(),0);
}
TEST(kelet2,pass){
    Console_Menu a;
    EXPECT_EQ(a.GetFirstInputSize(),0);
}
/*
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
EXPECT_EQ(firstInputCheck("234  2 1"), 3);
}

TEST(UrlTest, basicTest) {
EXPECT_EQ(isCustomURL("aa"), 0);
}
TEST(UrlTest2, basicTest2) {
EXPECT_EQ(isCustomURL("www.example.com1"), 1);
} 

TEST(KeletTest4, passedTest1) {
EXPECT_EQ(checkStringFun("ofek"), 0);
}
TEST(KeletTest5, falseTest2) {
EXPECT_EQ(checkStringFun("2 www.example.com1"), 1);
} 

TEST(mainTest, passedTest) {
EXPECT_EQ(checkStringFun("2 www.example.com1"), 1);
}
*/
