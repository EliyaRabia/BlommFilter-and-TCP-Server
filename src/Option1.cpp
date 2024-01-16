#include <iostream>
#include <string>
#include <vector>
#include "ICommand.h"
using namespace std;
class Option1{
    private :
        int first_input_size;
        int hash_times;
        int hash1;
        int hash2; 
        int array_size; 

    public : 
        Option1(int first_input_size,int hash_times,int hash1,int hash2,int array_size): first_input_size(first_input_size),hash_times(hash_times),hash1(hash1),hash2(hash2),array_size(array_size){} 

        void execute(int* bloom_filter,string url,vector <string>& my_vector){
            if (first_input_size == 2) {

                //in case only one bit in the bloom filter need to be changed.
                int place1 = (DoHash(hash_times,url))%array_size;
                bloom_filter[place1]=1; 
            } 
            else {

                //in case two bits in the bloom filter need to be changed.
                //the first place.
                int place1 = (DoHash(hash1,url))%array_size;
                bloom_filter[place1]=1;

                //the second place.
                int place2 = (DoHash(hash2,url))%array_size;
                bloom_filter[place2]=1;
                
            }

            // adding url to the vecotr.
            my_vector.push_back(url);
            
        }   
};