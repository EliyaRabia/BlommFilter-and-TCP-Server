#include <iostream>
#include <string>
using namespace std;

int firstInputCheck(const string& input) {
    int countNumbers = 0;
    bool inNumber = false;
    bool isCorrectdigit=false;

    for (char c : input) {
        if (c == ' ') { //case of space
            inNumber = false;
            if(isCorrectdigit==true){
                isCorrectdigit=false;
            }
        } 
        else if (isdigit(c)) { // case that the char is a number
            if (!inNumber) {
                ++countNumbers;
                
                inNumber = true;
            }
            if(countNumbers==2||countNumbers==3){  // in case we are in the second or three number of the input
                if(isCorrectdigit==false && (c=='2'||c=='1')){
                    isCorrectdigit=true;
                    
                }

                else{
                    return 0;
                } 
            }
        } 
        else {
            return 0;
        }
    }

    if(countNumbers==2){
        return 2;
    } 
    if(countNumbers==3){
        return 3;
    }
    else {
        return 0;
    }

}

bool isCustomURL(string input) {
    // Check if the input starts with "www." and ends with ".com"
    return (input.compare(0, 4, "www.") == 0);
} 

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
