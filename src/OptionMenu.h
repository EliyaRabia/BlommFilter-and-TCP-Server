#ifndef OptionMenu_H
#define OptionMenu_H
#include "IMenu.h"
#include <string>

using namespace std;  


class OptionMenu : public IMenu {

    private:
        string userURL;
        int choice;
        bool checkStringFun(string s);

    public :
        OptionMenu();
        void runMenu();
        int getChoice();
        string getUserUrl();
};

#endif //OptionMenu_H
