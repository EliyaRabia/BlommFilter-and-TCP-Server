#include <iostream> // i - input    o - output   stream - data streams for input and output
#include <string>
#include <vector>
#include "IMenu.h"
#include "OptionMenu.h"
using namespace std;
  
        string userURL;
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
            userURL = "";
            choice = -1;
        }
        void OptionMenu::runMenu(){
            string userInput;
            getline(cin, userInput);

            //need to check the input
            while (!checkStringFun(userInput)) {
            // we will clear the input buffer
	        cin.clear();
            getline(cin, userInput);
            }
            //split the input into choice and URL.
            int splitIndex = userInput.find(' ');
            choice = stoi(userInput.substr(0, splitIndex));
            userURL = userInput.substr(splitIndex + 1);
        }

        int OptionMenu::getChoice(){
            return choice;
        }
        string OptionMenu::getUserUrl(){
            return userURL;
        }