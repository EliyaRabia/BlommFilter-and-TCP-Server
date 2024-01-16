#include <iostream>
#include <string>
#include <vector>

using namespace std; 

class ICommand {
public:
    // the abstarct class
    virtual void execute(int* bloomFilter, int arraySize, int times, vector <string> myVector, string userURL) = 0;

    // Virtual destructor (recommended when dealing with polymorphism)
    virtual ~ICommand() = default;
};