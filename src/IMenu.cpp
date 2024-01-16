#include <iostream>
#include <string>
#include <vector>

using namespace std; 

class IMenu {
public:
    // the abstarct class
    virtual void runMenu() = 0;

    // Virtual destructor (recommended when dealing with polymorphism)
    virtual ~IMenu() = default;
};