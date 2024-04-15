#include <iostream> 
#include <string>
#include <vector>
#include "BloomFilter.h"
#include "Option1.h"
#include "Option2.h"

using namespace std;

BloomFilter::BloomFilter() : arraySize(128), result(false) {
    for(int i = 0; i < 128; i++) {
        bloomFilter[i] = 0;
    }
    hash1 =1;
    hash2 =2;
    op1 = new Option1(3,2,hash1,hash2,arraySize); 
    op2 = new Option2(3,2,hash1,hash2,arraySize); 
}

void execute(int choice, const std::string url) {
    if(choice == 1){
        result = op1->pushToArray(bloomFilter, url, stringVector); 
    } else {
        result = op2->checking2(bloomFilter, url, stringVector);
    }
}


vector<string> BloomFilter::getStringVector() {
    return stringVector;
}

int BloomFilter::getArraySize() {
    return arraySize;
}

int BloomFilter::getResult() {
    return result;
}

// Getter methods
int BloomFilter::getHash1() {
    return hash1;
}

int BloomFilter::getHash2() {
    return hash2;
}

// Setter methods
void BloomFilter::setHash1(int newHash1) {
    hash1 = newHash1;
}

void BloomFilter::setHash2(int newHash2) {
    hash2 = newHash2;
}

void BloomFilter::setArraySize(int newArraySize) {
    arraySize = newArraySize;
}
