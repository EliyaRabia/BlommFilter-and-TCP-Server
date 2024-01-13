#include <iostream>
#include <string>
using namespace std; 

long int DoHash (int digit, string s){
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
