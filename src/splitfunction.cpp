#include <iostream>
#include <string>
#include "functions.cpp"
using namespace std; 

bool checkStringFun(string s){
    if (s[0]!='1'&& s[0]!='2'){
        return false;
    } 
    if(s[1]!=' '){
        return false;
    } 
    string url = s.substr(2); 
    return isCustomURL(url);
    
} 
