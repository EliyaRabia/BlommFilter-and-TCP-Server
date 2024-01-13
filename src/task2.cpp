#include <iostream> // i - input    o - output   stream - data streams for input and output
#include <string>
using namespace std;

bool isCustomURL(string input) {
    // Check if the input starts with "www." and ends with ".com"
    return (input.compare(0, 4, "www.") == 0 && input.length() > 8 &&
            input.compare(input.length() - 4, 4, ".com") == 0);
}

unsigned long hashDJB2(const std::string& str) {
    unsigned long hash = 5381;

    for (char c : str) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }

    return hash;
} 

int main() {
    string sort[200];
    hash<string> myhash;
    string hashing;
    string choice;
    int place;


    while (true) {
        cin >> choice;
        getline(cin, hashing);
        place1 = myhash(hashing)%200;
        place2 = hashDJB2(hashing)%200;
        if (choice == "1"){
            sort[place1]=hashing; 
        } else {
            if (choice == "2") {
                
            }
        }
         
        
    }
        


        // as you saw, if you inputted a line for the first input,
	    // then it took the first word as the first input,
	    // and the rest of the line as the sccond input
	    // to fix this, we will clear the input buffer
	    cin.clear();
    

   


	return 0;
}