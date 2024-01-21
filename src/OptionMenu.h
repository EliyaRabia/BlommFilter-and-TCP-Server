#ifndef OptionMenu_H
#define OptionMenu_H
#include "IMenu.h"
#include <string>

using namespace std;  


class OptionMenu : public IMenu {

    private:
        string userURL;
        int choice;

    public :
        OptionMenu();
        void runMenu();
        int getChoice();
        string getUserUrl();
        bool checkStringFun(string s);
};

#endif //OptionMenu_H
