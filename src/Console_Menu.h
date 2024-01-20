#ifndef Console_Menu_H
#define Console_Menu_H
#include "IMenu.h"
#include <string>

using namespace std;  


class Console_Menu : public IMenu {
    private:
        int array_size; //array size
        int hash_times; //times of 1 function
        int hash1; //times of the first of the 2 functions
        int hash2; //times of the second of the 2 functions
        int first_input_size; //represent if using one function or two
        int firstInputCheck(const string& input);

    public :
        Console_Menu();
        void runMenu();
        int GetArray_size();
        int GetHashTimes();
        int GetHash1();
        int GetHash2();
        int GetFirstInputSize();
};

#endif //Console_Menu_H
