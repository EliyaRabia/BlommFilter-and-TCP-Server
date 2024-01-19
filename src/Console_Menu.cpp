#include <iostream> // i - input    o - output   stream - data streams for input and output
#include <string>
#include <vector>
#include "./IMenu.h"
using namespace std;  

class Console_Menu : public IMenu {
    private:
        int array_size; 
        int hash_times; 
        int hash1;
        int hash2; 
        int first_input_size;

        int firstInputCheck(const string& input) {
            if(input[0]-'0'==0|| input[0]== ' '){
                return 0;
            }
            int countNumbers = 0;
            bool inNumber = false;
            bool isCorrectdigit=false;
            bool isSpaceNow=false;
            int lastDigit=0;

            for (char c : input) {
                if( c== ' ' && isSpaceNow==true){
                    return 0;
                }
                if (c == ' ') { //case of space
                    inNumber = false;
                    isSpaceNow=true;
                    if(isCorrectdigit==true){
                        isCorrectdigit=false;
                    }
                } 

                else if (isdigit(c)) { // case that the char is a number
                    isSpaceNow=false;
                    if (!inNumber) {
                        if(lastDigit!=(c-'0')){
                            ++countNumbers;
                        }
                        
                        inNumber = true;
                    }
                    if(countNumbers>=2){  // in case we are in the second or three number of the input
                        if(isCorrectdigit==false && (c=='2'||c=='1')){ // here we make sure that the second and third input has only one digit: 2 or 1.
                            isCorrectdigit=true;
                            
                        }

                        else{
                            return 0;
                        } 
                    } 
                    lastDigit=c-'0';
                         
                } 
                else {
                    return 0;
                }
            }

            if(countNumbers==0||countNumbers==1){ //we return 0 in case that there were 0 or 1 values in the input
                return 0;
            } 
            // in this case we have 2 different inputs: array size and 1 or 2,we will check if its 1 or 2 and return it. we have only one hash in this case
            if(countNumbers==2){ 
                isSpaceNow=true;
                int valueNum=0;
                for(char c : input){
                    if( c != ' '&& valueNum==1){
                        return c-'0';
                    }

                    if (c != ' '){
                        isSpaceNow=false;
                    }
                    else if(c == ' ' && isSpaceNow==false){
                        valueNum++; 
                        isSpaceNow=true; 
                    } 
                    
                } 
                return 0;
            }
            //in this case we have 3 different inputs values: first one is array size and the second or third one is 1 or 2: we will return 3 for 2 hash functions
            else{
                return 3;
            }

        }  

    public:
        Console_Menu(){
            array_size=0;
            hash_times=0;
            hash1=0;
            hash2=0;
            first_input_size=0;
        } 
        void runMenu(){
            int split_index2;
            string user_input;
            getline(cin, user_input);
            //get a valid input.
            while (firstInputCheck(user_input) == 0) {
                getline(cin, user_input);
            } 
            // we will clear the input buffer
            cin.clear();

            //this is the right input and it indicates 1 2 or 3 where 1 is one function with 1 as value, 2 is one function with 2 as value, and three is 2 functions with both 1 and 2 as values.
            first_input_size = firstInputCheck(user_input); 
            int split_index = user_input.find(' ');
            array_size = stoi(user_input.substr(0, split_index));
            //in this case there are 2 hash functions where one must have 2 and the other 1.
            if(first_input_size==3){
                hash1=1;
                hash2=2;
            }
            //in this case we have one hash function, the value depends on the var.
            else{
                hash_times=first_input_size;
                first_input_size=2;
            } 
            /*
            //get a valid input.
            while (firstInputCheck(user_input) == 0) {
                getline(cin, user_input);
            } 
            // we will clear the input buffer
            cin.clear();

            //this is the right input
            first_input_size = firstInputCheck(user_input); 
            int split_index = user_input.find(' ');

            //The first input from the user, is the array size.
            array_size = stoi(user_input.substr(0, split_index));

            if (first_input_size == 2) {
                //in case there are two inputs
                //the second input represent which hash to use.
                hash_times = stoi(user_input.substr(split_index + 1));

            }   
            else {
                //in case there are three inputs
                split_index2 = user_input.find(' ', split_index + 1);

                //the second input represent hash1 and the third hash2.
                hash1 = stoi(user_input.substr(split_index + 1, split_index2 - split_index - 1));
                hash2 = stoi(user_input.substr(split_index2 + 1));
            } 
            */

        }  
        int GetArray_size(){
            return array_size;
        } 
        int GetHashTimes(){
            return hash_times;
        }  
        int GetHash1(){
            return hash1;
        } 
        int GetHash2(){
            return hash2;
        } 
        int GetFirstInputSize(){
            return first_input_size;
        }
};