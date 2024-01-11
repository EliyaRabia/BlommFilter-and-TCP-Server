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
    cout << isCustomURL("david") << endl;
    string sort[200];
    hash<string> myhash1;
    hash<string> myhash2;
    string hashing1;


    
        string hashing;
        string choice;
        cin >> choice;
        getline(cin, hashing);
        int place = myhash1(hashing)%200;
        sort[place]=hashing;  
        cout << myhash1(hashing) << endl;
        cout << hashDJB2(hashing) << endl;
        


        // as you saw, if you inputted a line for the first input,
	    // then it took the first word as the first input,
	    // and the rest of the line as the sccond input
	    // to fix this, we will clear the input buffer
	    cin.clear();
    

   


	return 0;
}