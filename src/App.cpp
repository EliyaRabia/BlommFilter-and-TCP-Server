#include <iostream> // i - input    o - output   stream - data streams for input and output
#include <string>
#include "./Console_Menu.cpp"
#include "./Option_Menu.cpp"
#include "./Option1.cpp"
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
            vector <string> my_vector;
            Option1* op1 = new Option1(cm->GetFirstInputSize(),cm->GetHashTimes(),cm->GetHash1(),cm->GetHash2(),cm->GetArray_size()); 
            while (true)
            {
                b->runMenu();
                Option_Menu* pm = dynamic_cast<Option_Menu*>(b);
                cout<<pm->GetChoice()<<endl; 
                cout<<pm->GetUserUrl()<<endl; 
                if(pm->GetChoice()==1){
                    op1->execute(bloom_filter,pm->GetUserUrl(),my_vector); 
                    

                   for (int i = 0; i < my_vector.size(); ++i) {
                       std::cout << my_vector[i] << " ";
                   } 
                   cout<<endl;

                }
                
            }
        }

}; 
int main() {
    App* ap = new App();
    ap->run();

    return 0;
}

