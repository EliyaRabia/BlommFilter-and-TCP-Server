#ifndef IOPTIONS_H
#define IOPTIONS_H
#include <iostream>
#include <string>

using namespace std; 

class IOptions {
public:
    // the abstract class
    virtual long int DoHash (int digit, string s) = 0;

    // Virtual destructor (recommended when dealing with polymorphism)
    virtual ~IOptions() = default;
};
#endif // IOPTIONS_H