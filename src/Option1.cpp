#include <iostream>
#include <string>
#include <vector>
#include "ICommand.h"
#include "IOptions.h"
#include "Option1.h"
using namespace std;

    long int Option1::doHash (int digit, string s){
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
        Option1::Option1(int firstInputSize,int hashTimes,int hash1,int hash2,int arraySize): firstInputSize(firstInputSize),hashTimes(hashTimes),hash1(hash1),hash2(hash2),arraySize(arraySize){} 

        void Option1::execute(int* bloomFilter,string url,vector <string>& myVector){
            if (firstInputSize == 2) {

                //in case only one bit in the bloom filter need to be changed.
                int place1 = abs((doHash(hashTimes,url))%arraySize);
                bloomFilter[place1]=1; 
            } 
            else {

                //in case two bits in the bloom filter need to be changed.
                //the first place.
                int place1 = abs((doHash(hash1,url))%arraySize);
                bloomFilter[place1]=1;

                //the second place.
                int place2 = abs((doHash(hash2,url))%arraySize);
                bloomFilter[place2]=1;
                
            }

            // adding url to the vector.
            myVector.push_back(url);
            
        }   
