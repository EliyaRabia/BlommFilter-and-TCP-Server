#include <iostream>
#include <string>
#include <vector>
#include "./Menu.cpp"
class App{
    private:
        Menu* menu;
    public:
        App(Menu* menu) : menu(menu) {}
    void run(){
        while(true){
            int task = menu -> nextCommand();
        }
    }
};