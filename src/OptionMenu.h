#ifndef OptionMenu_H
#define OptionMenu_H
#include "IMenu.h"
#include <string>

using namespace std;  


class OptionMenu : public IMenu {

    private:
        string user_URL;
        int choice;
        bool checkStringFun(string s);

    public :
        OptionMenu();
        void runMenu();
        int GetChoice();
        string GetUserUrl();
};

#endif //OptionMenu_H
