#include <iostream> // i - input    o - output   stream - data streams for input and output
#include <string>
#include "./functions.cpp"
#include <vector>
#include "./IMenu.cpp"
using namespace std;  

class Console_Menu : public IMenu {
    private:
        int array_size; 
        int hash_times; 
        int hash1;
        int hash2;
    public:
        Console_Menu(){
            array_size=0;
            hash_times=0;
            hash1=0;
            hash2=0;
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

            //this is the right input
            int first_input_size = firstInputCheck(user_input); 
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
};