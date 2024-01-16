#include <iostream> // i - input    o - output   stream - data streams for input and output
#include <string>
#include "./Console_Menu.cpp"
#include "./Option_Menu.cpp"
#include <vector>
using namespace std;  

class App{
    
    public:   
        void run(){
            IMenu* a = new Console_Menu();
            a->runMenu(); 
            Console_Menu* cm = dynamic_cast<Console_Menu*>(a);
            int bloom_filter[cm->GetArray_size()]; 
            //initilaze the array.
            for (int i = 0; i < cm->GetArray_size(); ++i) {
                bloom_filter[i] = 0;
            }
            IMenu* b = new Option_Menu;
            while (true)
            {
                b->runMenu();
                Option_Menu* op = dynamic_cast<Option_Menu*>(b);
                cout <<op->GetChoice()<<endl;
                cout <<op->GetUserUrl()<<endl;
            }
        }

}; 
int main() {
    App* ap = new App();
    ap->run();

    return 0;
}

