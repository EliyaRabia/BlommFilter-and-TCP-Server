#include <iostream> // i - input    o - output   stream - data streams for input and output
#include <string>
#include "./functions.cpp"
#include <vector>
#include "./ICommand.cpp"

using namespace std; 


class Option2 : public ICommand {
    private :
     int hash1;
     int hash2;

    public:
    // Constructor.
    Option2(int hash1, int hash2) : hash1(hash1), hash2(hash2) {

    }   

    int getHash1(){
        return hash1;
    }
    int getHash2(){
        return hash2;
    }

    //check in one place in the bloom filter.
    void checking1(int hash, int* bloomFilter, int arraySize , vector<string>  myVector , string userURL) {
    int place;

    //need to check the url exists in one place.
    place = (DoHash(hash,userURL))%arraySize;
    if (bloomFilter[place] != 1) {
        cout << "false" << endl;
        } else {
            // bloom filter was true;
            cout << "true" << " ";

            //checking false positive situation.
            if (checkIfUrlExist(myVector, userURL)) {
                cout << "true" << endl;
                } else {
                    cout << "false" << endl;
                }
    }
    }

    //check in two places in the bloom filter.
    void checking2(int* bloomFilter, int arraySize , vector<string>  myVector , string userURL) {
    //need to check the url exists in two places.
    int place1;
    int place2;

    //the first place.
    place1 = (DoHash(hash1,userURL))%arraySize;

    //the second place.
    place2 = (DoHash(hash2,userURL))%arraySize;

    if (bloomFilter[place1] != 1 || bloomFilter[place2] != 1) {
        cout << "false" << endl;
        } else {
            // bloom filter was true;
            cout << "true" << " ";

            //checking false positive situation.
            if (checkIfUrlExist(myVector, userURL)) {
                cout << "true" << endl;
                } else {
                    cout << "false" << endl;
                    }
                }
} 

void execute(int* bloomFilter, int arraySize, int times, vector <string> myVector, string userURL) {
        //checking in the bloom filter one or two times.
        switch (times) {
        case 1:
            //need to check the url exists in one place.
            if (hash1 != 0) {
                checking1(hash1, bloomFilter, arraySize, myVector, userURL);
            } else {
                checking1(hash2, bloomFilter, arraySize, myVector, userURL);
            }
                
            break;
        case 2:
            //need to check the url exists in two places.
            checking2(bloomFilter, arraySize, myVector, userURL);
            
            break;
        default:
            break;
        }
    }

    
};

int main() {
    int hash1 = 1;
    int hash2 = 2;
    Option2 p = Option2(hash1, hash2);
    int bloomFilter[8];

    //initilaze the array.
    for (int i = 0; i < 8; ++i) {
        bloomFilter[i] = 0;
    }
    int times = 2;
    vector <string> myVector;
    string userURL = "www.example.com0";
    // adding url to the vecotr.

    p.execute(bloomFilter, 8, 2, myVector, userURL);

    return 0;
}

