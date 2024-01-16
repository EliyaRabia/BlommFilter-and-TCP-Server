#ifndef ICOMMAND_H
#define ICOMMAND_H
#include <iostream>
#include <string>
#include <vector>
#include "./functions.cpp"
using namespace std; 

class ICommand {
public:
    // the abstarct class
    virtual void execute(int* bloom_filter,string url,vector <string>& my_vector) = 0;

    // Virtual destructor (recommended when dealing with polymorphism)
    virtual ~ICommand() = default;
};
#endif 