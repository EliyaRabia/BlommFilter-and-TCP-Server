#include <iostream> // i - input    o - output   stream - data streams for input and output
#include <string>
#include "./Console_Menu.cpp"
#include <vector>
using namespace std;  

class App{
    
    public:   
        void run(){
            Console_Menu* a = new Console_Menu();
            a->runFirstInput(); 
            cout<<a->GetArray_size()<<endl;
            cout<<a->GetHashTimes()<<endl; 
            cout<<a->GetHash1()<<endl;  
            cout<<a->GetHash2()<<endl; 

            int bloom_filter[a->GetArray_size()]; 

        }

}; 
int main() {
    App* ap = new App(); 
    ap->run();

    return 0;
}

