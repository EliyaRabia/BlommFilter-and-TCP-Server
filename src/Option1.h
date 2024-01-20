#ifndef OPTION1_H
#define OPTION1_H
#include <iostream>
#include <string>
#include <vector>
#include "ICommand.h"
#include "IOptions.h"

using namespace std; 

class Option1 : public IOptions ,ICommand{
    private :
        int firstInputSize;
        int hashTimes;
        int hash1;
        int hash2; 
        int arraySize; 
        long int doHash (int digit, string s);

    public : 
        Option1(int firstInputSize,int hashTimes,int hash1,int hash2,int arraySize);
        void execute(int* bloomFilter,string url,vector <string>& myVector);

};
#endif // OPTION1_H