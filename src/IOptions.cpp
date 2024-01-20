#include <iostream>
#include <string>
#include "IOptions.h"

using namespace std;  
    long int IOptions::doHash (int digit, string s){
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

