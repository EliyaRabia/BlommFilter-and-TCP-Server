#include <iostream> // i - input    o - output   stream - data streams for input and output
#include <string>
#include <vector>
#include "IMenu.h"
using namespace std;
  
class Option_Menu : public IMenu {
    private :
        string user_URL;
        int choice;

        bool checkStringFun(string s){
            //Gets a string and check if the string is in the form of "1\2 "some url" "
            if (s[0]!='1'&& s[0]!='2'){
                return false;
            } 
            //some exceptions check
            if(s[1]!=' ' || s[2]==' ' || s[s.length()-1]==' '){
                return false;
            } 

            
            return true;
            
        }   

    public : 
    // constructor
        Option_Menu(){
            user_URL = "";
            choice = -1;
        }
        void runMenu(){
            string user_input;
            getline(cin, user_input);

            //need to check the input
            while (!checkStringFun(user_input)) {
            // we will clear the input buffer
	        cin.clear();
            getline(cin, user_input);
            }
            //split the input into choice and URL.
            int split_index = user_input.find(' ');
            choice = stoi(user_input.substr(0, split_index));
            user_URL = user_input.substr(split_index + 1);
        }

        int GetChoice(){
            return choice;
        }
        string GetUserUrl(){
            return user_URL;
        }
};