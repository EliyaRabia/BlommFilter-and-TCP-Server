#include <iostream> // i - input    o - output   stream - data streams for input and output
#include <string>
#include "./functions.cpp"
#include <vector>
using namespace std; 
//this is the file that represent the loop.

int main() {

    string user_input;
    string user_URL;
    int hash_times = 0;
    int choice;
    int array_size;
    int split_index2;
    int hash1 = 0;
    int hash2 = 0;
    int place1 = 0;
    int place2 = 0;
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
                cout << " hash1 =" << DoHash(hash1,user_URL) << endl;
                bloom_filter[place1]=1;

                //the second place.
                place2 = (DoHash(hash2,user_URL))%array_size;
                cout << " hash2 =" << DoHash(hash2,user_URL) << endl;
                bloom_filter[place2]=1;
                
            }

            // adding url to the vecotr.
            my_vector.push_back(user_URL);

        } else {
            if (choice == 2) {
                //in case the user want to check if the URL exists.

                if (first_input_size == 2 ) {
                    //need to check the url exists in one place.
                    place1 = (DoHash(hash_times,user_URL))%array_size;

                    if (bloom_filter[place1] != 1) {
                        cout << "false" << endl;
                    } else {
                        // bloom filter was true;
                        cout << "true" << " ";

                        //checking false positive situation.
                        if (checkIfUrlExist(my_vector, user_URL)) {
                            cout << "true" << endl;
                        } else {
                            cout << "false" << endl;
                        }
                    }
                } else {
                    //need to check the url exists in two places.
                    //in case two bits in the bloom filter need to be changed.

                    //the first place.
                    place1 = (DoHash(hash1,user_URL))%array_size;
                    cout << " place1 =" << DoHash(hash1,user_URL)% array_size << endl;

                    //the second place.
                    place2 = (DoHash(hash2,user_URL))%array_size;
                    cout << " place2 =" << DoHash(hash2,user_URL)%array_size << endl;
                    cout << "bloomfilter = " << bloom_filter[4] << endl;

                    if (bloom_filter[place1] != 1 || bloom_filter[place2] != 1) {
                        cout << "false" << endl;
                    } else {
                        // bloom filter was true;
                        cout << "true" << " ";

                        //checking false positive situation.
                        if (checkIfUrlExist(my_vector, user_URL)) {
                            cout << "true" << endl;
                        } else {
                            cout << "false" << endl;
                        }
                    }
                }
            }
        }

	    // we will clear the input buffer
	    cin.clear();
        
    }
        
	return 0;
}