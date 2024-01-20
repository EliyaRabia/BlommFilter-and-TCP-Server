#include <iostream> // i - input    o - output   stream - data streams for input and output
#include <string>
#include <vector>
#include "IMenu.h"
#include "OptionMenu.h"
using namespace std;
  
        string user_URL;
        int choice;

        bool OptionMenu::checkStringFun(string s){
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

    // constructor
        OptionMenu::OptionMenu(){
            user_URL = "";
            choice = -1;
        }
        void OptionMenu::runMenu(){
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

        int OptionMenu::GetChoice(){
            return choice;
        }
        string OptionMenu::GetUserUrl(){
            return user_URL;
        }