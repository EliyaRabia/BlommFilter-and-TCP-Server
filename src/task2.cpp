#include <iostream> // i - input    o - output   stream - data streams for input and output
#include <string>
#include "./functions.cpp"
using namespace std;

int main() {

    hash<string> myhash;
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
    getline(cin, user_input);

    // // get a valid input.
    while (firstInputCheck(user_input) == 0) {
        getline(cin, user_input);
    }
    cin.clear();

    first_input_size = firstInputCheck(user_input);
    int split_index = user_input.find(' ');

    //The first input from the user, is the array size.
    array_size = stoi(user_input.substr(0, split_index));

    if (first_input_size == 2) {
        //the second input represent how many times to run the hash 1 or 2(double).
        hash_times = stoi(user_input.substr(split_index + 1));

    }   else {
        //in case there are three inputs
        //the second is the 
        split_index2 = user_input.find(' ', split_index + 1);
        hash1 = stoi(user_input.substr(split_index + 1, split_index2 - split_index - 1));
        hash2 = stoi(user_input.substr(split_index2 + 1));
    }
    int bloom_filter[array_size];



    //initilaze the array.
    for (int i = 0; i < array_size; ++i) {
        bloom_filter[i] = 0;
    }



    while (true) {
        cin >> choice;
        getline(cin, user_URL);
        //need to check the input

        if (choice == 1){
            if (first_input_size == 2) {
                //1 or 2 send by hash_times!!
                place1 = myhash(user_URL)%array_size;
                bloom_filter[place1]=1; 
            } else {
                //represent the case the first input consist from three valures.
                //1 or 2 send by hash1 and hash2!!
                place1 = myhash(user_URL)%array_size;
                bloom_filter[place1]=1;

                //1 or 2 send!!
                place2 = myhash(user_URL)%array_size;
                bloom_filter[place2]=1;
                
            }

            // add url to link list.

        } else {
            if (choice == 2) {
                //need to check the url exists.
                if (first_input_size == 2 ) {
                    // we need to check only in one place.
                    if (bloom_filter[place1] != 1) {
                        cout << "false" << endl;
                    } else {
                        // need to check false positive;
                        cout << "true" << " ";
                        // need to check in link list and print true or false.
                    }
                } else {
                    //we need to check in two places.
                    if (bloom_filter[place1] != 1 || bloom_filter[place2] != 1) {
                        cout << "false" << endl;
                    } else {
                        // need to check false positive;
                        cout << "true" << " ";
                        // need to check in link list and print true or false.
                    }
                }
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