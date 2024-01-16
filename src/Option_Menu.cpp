#include <iostream> // i - input    o - output   stream - data streams for input and output
#include <string>
#include "./functions.cpp"
#include <vector>
#include "./IMenu.cpp"
using namespace std;
  
class Option_Menu : public IMenu {
    private :
        string user_URL;
        int choice;
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