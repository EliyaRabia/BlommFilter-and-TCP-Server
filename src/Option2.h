#ifndef OPTION2_H
#define OPTION2_H
#include <iostream>
#include <string>
#include <vector>
#include "ICommand.h"
#include "IOptions.h"

using namespace std; 

class Option2 : public ICommand, IOptions{
    private :
        int first_input_size;
        int hash_times;
        int hash1;
        int hash2; 
        int array_size; 
        long int DoHash (int digit, string s);
        bool checkIfUrlExist(vector<string> urls, string new_url);

    public:
        // Constructor.
        Option2(int first_input_size,int hash_times,int hash1,int hash2,int array_size);
        int getHash1();
        int getHash2();
        void checking1(int* bloom_filter,string url,vector <string>& my_vector);
        void checking2(int* bloom_filter,string url,vector <string>& my_vector);
        void execute(int* bloom_filter,string url,vector <string>& my_vector);

};
#endif // OPTION2_H