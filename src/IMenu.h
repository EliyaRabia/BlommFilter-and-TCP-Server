#ifndef IMENU_H
#define IMENU_H

class IMenu {
public:
    // the abstarct class
    virtual void runMenu() = 0;

    // Virtual destructor (recommended when dealing with polymorphism)
    virtual ~IMenu() = default;
}; 
#endif // IMENU_H