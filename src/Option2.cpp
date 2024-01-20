#include <iostream>
#include <string>
#include <vector>
#include "ICommand.h"
#include "IOptions.h"
#include "Option2.h"

using namespace std; 

        long int Option2::doHash (int digit, string s){
            //Gets a number and a string and does hashing or double hashing depends on the number.
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
        bool Option2::checkIfUrlExist(vector<string> urls, string newUrl){
            for (string i : urls) {
                if(i.compare(newUrl)==0){
                    return true;
                }
            }
            return false;
        }

    // Constructor.
    Option2::Option2(int firstInputSize,int hashTimes,int hash1,int hash2,int arraySize): firstInputSize(firstInputSize),hashTimes(hashTimes),hash1(hash1),hash2(hash2),arraySize(arraySize){} 


    int Option2::getHash1(){
        return hash1;
    }
    int Option2::getHash2(){
        return hash2;
    }

    //check in one place in the bloom filter.
    void Option2::checking1(int* bloomFilter,string url,vector <string>& myVector) {
    int place;

    //need to check the url exists in one place.
    place = abs((doHash(hashTimes,url))%arraySize);
    if (bloomFilter[place] != 1) {
        cout << "false" << endl;
        } else {
            // bloom filter was true;
            cout << "true" << " ";

            //checking false positive situation.
            if (checkIfUrlExist(myVector, url)) {
                cout << "true" << endl;
                } else {
                    cout << "false" << endl;
                }
    }
    }

    //check in two places in the bloom filter.
    void Option2::checking2(int* bloomFilter,string url,vector <string>& myVector) {
    //need to check the url exists in two places.
    int place1;
    int place2;

    //the first place.
    place1 = abs((doHash(hash1,url))%arraySize);

    //the second place.
    place2 = abs((doHash(hash2,url))%arraySize);

    if (bloomFilter[place1] != 1 || bloomFilter[place2] != 1) {
        cout << "false" << endl;
        } else {
            // bloom filter was true;
            cout << "true" << " ";

            //checking false positive situation.
            if (checkIfUrlExist(myVector, url)) {
                cout << "true" << endl;
                } else {
                    cout << "false" << endl;
                    }
                }
} 

void Option2::execute(int* bloomFilter,string url,vector <string>& myVector) {
        //checking in the bloom filter one or two times.
        switch (firstInputSize) {
        case 2:
            //need to check the url exists in one place.
            checking1(bloomFilter, url, myVector);
                
            break;
        case 3:
            //need to check the url exists in two places.
            checking2(bloomFilter, url, myVector);
            
            break;
        default:
            break;
        }
    }
