#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

#include <string>
#include <vector>
#include "Option1.h"
#include "Option2.h"

class BloomFilter {
    int bloomFilter[128]; 
    std::vector<std::string> stringVector;
    int arraySize;
    int result;
    int hash1, hash2;
    Option1* op1;
    Option2* op2;

public:
    BloomFilter();

    void BloomFilter::execute(int choice, const std::string url);

    std::vector<std::string> getStringVector();
    int getArraySize();
    int getResult();

    // Getter methods
    int getHash1();
    int getHash2();

    // Setter methods
    void setHash1(int newHash1);
    void setHash2(int newHash2);
    void setArraySize(int newArraySize);
};

#endif // BLOOMFILTER_H