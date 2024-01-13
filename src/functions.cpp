#include <iostream>
#include <string>
using namespace std;
int firstInputCheck(const string& input) {
    int countNumbers = 0;
    bool inNumber = false;
    bool isCorrectdigit=false;

    for (char c : input) {
        if (c == ' ') {
            inNumber = false;
            if(isCorrectdigit==true){
                isCorrectdigit=false;
            }
        } 
        else if (isdigit(c)) {
            if (!inNumber) {
                ++countNumbers;
                
                inNumber = true;
            }
            if(countNumbers==2){ //maybe we will need to change it to AND 3 after we realize what to do
                if(isCorrectdigit==false){
                    if(c=='2'||c=='1'){
                    isCorrectdigit=true;
                    }
                    else{
                        return 0;
                    }
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
