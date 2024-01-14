#include <iostream>
#include <string>
#include <vector>
using namespace std;
//this file contains our functions we use in task2 

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
                if(isCorrectdigit==false && (c=='2'||c=='1')){ // here we make sure that the second and third input has only one digit: 2 or 1.
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

    if(countNumbers==2){ //we return 2 in case that there were 2 values in the input
        return 2;
    } 
    if(countNumbers==3){//we return 3 in case that there were 3 values in the input
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
    //Gets a string and check if the string is in the form of "1\2 "some url" "
    if (s[0]!='1'&& s[0]!='2'){
        return false;
    } 
    if(s[1]!=' '){
        return false;
    } 
    string url = s.substr(2); 
    return isCustomURL(url);
    
}   
bool checkIfUrlExist(vector<string> urls, string new_url){
    for (string i : urls) {
        if(i.compare(new_url)==0){
            return true;
        }
    }
    return false;
}

long int DoHash (int digit, string s){
    //Gets a number and a string and does hashing or double hashing depends on the number.
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

void mainChecking() {

    string user_input;
    string user_URL;
    int hash_times = 0;
    int choice;
    int array_size;
    int split_index2;
    int hash1 = 0;
    int hash2 = 0;
    int place1;
    int place2;
    int first_input_size;
    vector <string> my_vector;
    getline(cin, user_input);

    //get a valid input.
    while (firstInputCheck(user_input) == 0) {
        getline(cin, user_input);
    }

    // we will clear the input buffer
    cin.clear();

    first_input_size = firstInputCheck(user_input);
    int split_index = user_input.find(' ');

    //The first input from the user, is the array size.
    array_size = stoi(user_input.substr(0, split_index));

    if (first_input_size == 2) {
        //in case there are two inputs
        //the second input represent which hash to use.
        hash_times = stoi(user_input.substr(split_index + 1));

    }   else {
        //in case there are three inputs
        split_index2 = user_input.find(' ', split_index + 1);

        //the second input represent hash1 and the third hash2.
        hash1 = stoi(user_input.substr(split_index + 1, split_index2 - split_index - 1));
        hash2 = stoi(user_input.substr(split_index2 + 1));
    }
    int bloom_filter[array_size];

    //initilaze the array.
    for (int i = 0; i < array_size; ++i) {
        bloom_filter[i] = 0;
    }

    //endless while loop.
    while (true) {
        getline(cin, user_input);

        //need to check the input
        while (!checkStringFun(user_input)) {

        // we will clear the input buffer
	    cin.clear();
        getline(cin, user_input);
        }

        //split the input into choice and URL.
        split_index = user_input.find(' ');
        choice = stoi(user_input.substr(0, split_index));
        user_URL = user_input.substr(split_index + 1);
        

        if (choice == 1){
            //in case the user want to enter a URL.
            if (first_input_size == 2) {

                //in case only one bit in the bloom filter need to be changed.
                place1 = (DoHash(hash_times,user_URL))%array_size;
                bloom_filter[place1]=1; 
            } else {

                //in case two bits in the bloom filter need to be changed.
                //the first place.
                place1 = (DoHash(hash1,user_URL))%array_size;
                bloom_filter[place1]=1;

                //the second place.
                place2 = (DoHash(hash2,user_URL))%array_size;
                bloom_filter[place2]=1;
                
            }

            // adding url to the vecotr.
            my_vector.push_back(user_URL);

        } else {
            if (choice == 2) {
                //in case the user want to check if the URL exists.

                if (first_input_size == 2 ) {
                    //need to check the url exists in one place.

                    if (bloom_filter[place1] != 1) {
                        cout << "false" << endl;
                    } else {
                        // bloom filter was true;
                        cout << "true" << " ";

                        //checking false positive situation.
                        cout << checkIfUrlExist(my_vector, user_URL) << endl;
                    }
                } else {
                    //need to check the url exists in two places.
                    if (bloom_filter[place1] != 1 || bloom_filter[place2] != 1) {
                        cout << "false" << endl;
                    } else {
                        // bloom filter was true;
                        cout << "true" << " ";

                        //checking false positive situation.
                        cout << checkIfUrlExist(my_vector, user_URL) << endl;
                    }
                }
            }
        }

	    // we will clear the input buffer
	    cin.clear();
        
    }
}
