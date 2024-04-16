#include <iostream> 
#include <string>
#include <vector>
#include "BloomFilter.h"

using namespace std;

// BloomFilter::BloomFilter() : arraySize(128), result(false) {
//     for(int i = 0; i < 128; i++) {
//         bloomFilter[i] = 0;
//     }
//     hash1 =1;
//     hash2 =2;
// }

BloomFilter::BloomFilter(int size, int hash1 , int hash2) : result(false) {
    bloomFilter = new int[size]; // Allocate memory for bloomFilter
    cout << "BloomFilter created with size: " << size << endl;
    cout << "Hash1: " << hash1 << endl;
    cout << "Hash2: " << hash2 << endl;
    cout << "before for" << endl;
    for(int i = 0; i < size; i++) {
        bloomFilter[i] = 0;
    }
    cout << "after for" << endl;
    arraySize = size;
    this->hash1 = hash1;
    this->hash2 = hash2;
}

BloomFilter::~BloomFilter() {
    delete[] bloomFilter; // Deallocate memory when the object is destroyed
}

int BloomFilter::execute(int choice, const std::string url) {
    if(choice == 1){
        this->result = this->pushToArray(url); 
    } else {
        this->result = this->checking2(url);
    }
    return this->result;
}

bool BloomFilter::checkIfUrlExist(string newUrl){
            for (string i : stringVector) {
                if(i.compare(newUrl)==0){
                    return true;
                }
            }
            return false;
        }
        
long int BloomFilter::doHash (int digit, string s){
        hash<string> hashF;
        long int val=hashF(s);
        if(digit==1){
            return val;
        } 
        if(digit==2){
            string second = to_string(val);  
            return hashF(second);
        }
        else{
            return -1;
        }
    } 

bool BloomFilter::pushToArray(string url){

        //in case two bits in the bloom filter need to be changed.
        //the first place.
        int place1 = abs((doHash(hash1,url))%arraySize);
        bloomFilter[place1]=1;

        //the second place.
        int place2 = abs((doHash(hash2,url))%arraySize);
        bloomFilter[place2]=1;
        // adding url to the vector.
        cout << url << endl;
        stringVector.push_back(url);
        return 1;
    }

int BloomFilter::checking2(string url) {
    //need to check the url exists in two places.
    int place1;
    int place2;
    //the first place.
    place1 = abs((doHash(hash1,url))%arraySize);
    //the second place.
    place2 = abs((doHash(hash2,url))%arraySize);
    if (bloomFilter[place1] != 1 || bloomFilter[place2] != 1) {
        cout << "false" << endl;
        return 0;
        } else {
            // bloom filter was true;
            cout << "true" << " ";

            //checking false positive situation.
            if (checkIfUrlExist(url)) {
                cout << "true" << endl;
                return 2;
                } else {
                    cout << "false" << endl;
                    return 3;
                    }
                }
    return 1;
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
