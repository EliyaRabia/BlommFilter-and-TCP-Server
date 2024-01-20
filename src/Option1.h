#ifndef OPTION1_H
#define OPTION1_H
#include <iostream>
#include <string>
#include <vector>
#include "ICommand.h"
#include "IOptions.h"

using namespace std; 

class Option1 : public IOptions ,ICommand{
    private :
        int first_input_size;
        int hash_times;
        int hash1;
        int hash2; 
        int array_size; 
        long int DoHash (int digit, string s);

    public : 
        Option1(int first_input_size,int hash_times,int hash1,int hash2,int array_size);
        void execute(int* bloom_filter,string url,vector <string>& my_vector);

};
#endif // OPTION1_H