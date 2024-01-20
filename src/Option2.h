#ifndef OPTION2_H
#define OPTION2_H
#include <iostream>
#include <string>
#include <vector>
#include "ICommand.h"
#include "IOptions.h"

using namespace std; 

class Option2 : public ICommand, IOptions{
    private :
        int firstInputSize;
        int hashTimes;
        int hash1;
        int hash2; 
        int arraySize; 
        long int doHash (int digit, string s);
        bool checkIfUrlExist(vector<string> urls, string newUrl);

    public:
        // Constructor.
        Option2(int firstInputSize,int hashTimes,int hash1,int hash2,int arraySize);
        int getHash1();
        int getHash2();
        void checking1(int* bloomFilter,string url,vector <string>& myVector);
        void checking2(int* bloomFilter,string url,vector <string>& myVector);
        void execute(int* bloomFilter,string url,vector <string>& myVector);

};
#endif // OPTION2_H