#include <iostream> // i - input    o - output   stream - data streams for input and output
#include <string>
using namespace std;

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
         // as you saw, if you inputted a line for the first input,
	    // then it took the first word as the first input,
	    // and the rest of the line as the sccond input
	    // to fix this, we will clear the input buffer
	    cin.clear();
        
    }
        
	return 0;
}