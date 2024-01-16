#include <iostream>
#include <string>
#include <vector>
#include "ICommand.h"

using namespace std; 


class Option2 : public ICommand {
    private :
        int first_input_size;
        int hash_times;
        int hash1;
        int hash2; 
        int array_size; 

    public:
    // Constructor.
    Option2(int first_input_size,int hash_times,int hash1,int hash2,int array_size): first_input_size(first_input_size),hash_times(hash_times),hash1(hash1),hash2(hash2),array_size(array_size){} 


    int getHash1(){
        return hash1;
    }
    int getHash2(){
        return hash2;
    }

    //check in one place in the bloom filter.
    void checking1(int* bloom_filter,string url,vector <string>& my_vector) {
    int place;

    //need to check the url exists in one place.
    place = (DoHash(hash_times,url))%array_size;
    if (bloom_filter[place] != 1) {
        cout << "false" << endl;
        } else {
            // bloom filter was true;
            cout << "true" << " ";

            //checking false positive situation.
            if (checkIfUrlExist(my_vector, url)) {
                cout << "true" << endl;
                } else {
                    cout << "false" << endl;
                }
    }
    }

    //check in two places in the bloom filter.
    void checking2(int* bloom_filter,string url,vector <string>& my_vector) {
    //need to check the url exists in two places.
    int place1;
    int place2;

    //the first place.
    place1 = (DoHash(hash1,url))%array_size;

    //the second place.
    place2 = (DoHash(hash2,url))%array_size;

    if (bloom_filter[place1] != 1 || bloom_filter[place2] != 1) {
        cout << "false" << endl;
        } else {
            // bloom filter was true;
            cout << "true" << " ";

            //checking false positive situation.
            if (checkIfUrlExist(my_vector, url)) {
                cout << "true" << endl;
                } else {
                    cout << "false" << endl;
                    }
                }
} 

void execute(int* bloom_filter,string url,vector <string>& my_vector) {
        //checking in the bloom filter one or two times.
        switch (first_input_size) {
        case 2:
            //need to check the url exists in one place.
            checking1(bloom_filter, url, my_vector);
                
            break;
        case 3:
            //need to check the url exists in two places.
            checking2(bloom_filter, url, my_vector);
            
            break;
        default:
            break;
        }
    }

    
};

