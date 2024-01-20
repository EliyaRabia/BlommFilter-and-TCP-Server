#ifndef ICOMMAND_H
#define ICOMMAND_H
#include <iostream>
#include <string>
#include <vector>

using namespace std; 

class ICommand {
public:
    // the abstract class
    virtual void execute(int* bloomFilter,string url,vector <string>& myVector) = 0;

    // Virtual destructor (recommended when dealing with polymorphism)
    virtual ~ICommand() = default;
};
#endif // ICOMMAND_H