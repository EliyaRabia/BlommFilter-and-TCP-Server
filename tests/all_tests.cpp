#include <gtest/gtest.h>
#include "../src/ConsoleMenu.cpp"
#include "../src/Option2.cpp"
#include "../src/Options.cpp"
#include <string>
#include <vector>

using namespace std; 

TEST(kelet,pass){
    ConsoleMenu a;
    EXPECT_EQ(a.getArraySize(),0);
}
TEST(kelet2,pass){
    ConsoleMenu a;
    EXPECT_EQ(a.getFirstInputSize(),0);
}

//false in input size of 2
TEST(outPutFor2a, pass){
    int bloomFilter[8];
    for(int i=0;i<8;i++){
        bloomFilter[i]=0;
    }
    string url = "www.example.com0";
    vector <string> myVector;
    int firstInputSize = 2;
    int hashTimes = 2;
    int hash1 = 0;
    int hash2 = 0;
    int arraySize = 8;
    Option2 p2(firstInputSize, hashTimes, hash1, hash2, arraySize);
    EXPECT_EQ(p2.checking1(bloomFilter, url, myVector),0);
}

//true false in case of 2 inputs
TEST(outPutFor2b, pass){
    int bloomFilter[8];
    for(int i=0;i<8;i++){
        bloomFilter[i]=0;
    }
    string url = "www.example.com";
    vector <string> myVector;
    int firstInputSize = 2;
    int hashTimes = 2;
    bloomFilter[1]=1;
    int hash1 = 0;
    int hash2 = 0;
    int arraySize = 8;
    Option2 p2(firstInputSize, hashTimes, hash1, hash2, arraySize);
    EXPECT_EQ(p2.checking1(bloomFilter, url, myVector),3);
}

//true true in case of 2 inputs
TEST(outPutFor2c, pass){
    int bloomFilter[8];
    for(int i=0;i<8;i++){
        bloomFilter[i]=0;
    }
    string url = "www.example.com";
    vector <string> myVector;
    myVector.push_back(url);
    int firstInputSize = 2;
    int hashTimes = 2;
    bloomFilter[1]=1;
    int hash1 = 0;
    int hash2 = 0;
    int arraySize = 8;
    Option2 p2(firstInputSize, hashTimes, hash1, hash2, arraySize);
    EXPECT_EQ(p2.checking1(bloomFilter, url, myVector),2);
}

//false in case of 3 inputs
TEST(outPutFor3a, pass){
    int bloomFilter[8];
    for(int i=0;i<8;i++){
        bloomFilter[i]=0;
    }
    string url = "www.example.com0";
    vector <string> myVector;
    int firstInputSize = 3;
    int hashTimes = 0;
    int hash1 = 1;
    int hash2 = 2;
    int arraySize = 8;
    Option2 p2(firstInputSize, hashTimes, hash1, hash2, arraySize);
    EXPECT_EQ(p2.checking2(bloomFilter, url, myVector),0);
}

//true false in case of 3 inputs
TEST(outPutFor3b, pass){
    int bloomFilter[8];
    for(int i=0;i<8;i++){
        bloomFilter[i]=0;
    }
    string url = "www.example.com";
    vector <string> myVector;
    int firstInputSize = 3;
    int hashTimes = 0;
    bloomFilter[0]=1;
    bloomFilter[1]=1;
    int hash1 = 1;
    int hash2 = 2;
    int arraySize = 8;
    Option2 p2(firstInputSize, hashTimes, hash1, hash2, arraySize);
    EXPECT_EQ(p2.checking2(bloomFilter, url, myVector),3);
}

//true true in case of 3 inputs
TEST(outPutFor3c, pass){
    int bloomFilter[8];
    for(int i=0;i<8;i++){
        bloomFilter[i]=0;
    }
    string url = "www.example.com";
    vector <string> myVector;
    int firstInputSize = 3;
    int hashTimes = 0;
    int hash1 = 1;
    int hash2 = 2;
    bloomFilter[0]=1;
    bloomFilter[1]=1;
    myVector.push_back(url);
    int arraySize = 8;
    Option2 p2(firstInputSize, hashTimes, hash1, hash2, arraySize);
    EXPECT_EQ(p2.checking2(bloomFilter, url, myVector),2);
}

//these are old tests that we used before refactoring to classes.
/*
// here is the code that we used to check our code by TDD.

//here we do the sanity Test.
TEST(AppTest, Getters) {
App app();
EXPECT_EQ(app.run(), 1);
EXPECT_EQ(app.runMenu(),2);
}



// here we check the tests.

#include "../src/functions.cpp" 
TEST(doHashTest, pass) {
EXPECT_EQ(doHash("www.example.com"), 1);
}
TEST(doDoubleHashTest2, pass) {
EXPECT_EQ(doHash("www.example.com"), 2);
}
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
