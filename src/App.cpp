#include <iostream> 
#include <string>
#include "IMenu.h"
#include "Console_Menu.h"
#include "./Option_Menu.cpp"
#include "./Option1.cpp"
#include "./Option2.cpp"
#include <vector>
#include "App.h"

using namespace std; 

/*
This class runs the program. and uses all the proper classes
*/
        void App::run(){
            // create a menu that get the first input
            IMenu* a = new Console_Menu();
            a->runMenu(); 
            Console_Menu* cm = dynamic_cast<Console_Menu*>(a);
            int bloom_filter[cm->GetArray_size()]; 
            //initialize the array.
            for (int i = 0; i < cm->GetArray_size(); ++i) {
                bloom_filter[i] = 0;
            }
            IMenu* b = new Option_Menu;
            vector <string> my_vector;
            Option1* op1 = new Option1(cm->GetFirstInputSize(),cm->GetHashTimes(),cm->GetHash1(),cm->GetHash2(),cm->GetArray_size()); 
            Option2* op2 = new Option2(cm->GetFirstInputSize(),cm->GetHashTimes(),cm->GetHash1(),cm->GetHash2(),cm->GetArray_size()); 
            // this while loop runs for infinity, get the next commands from the user.
            while (true)
            {
                b->runMenu();
                Option_Menu* pm = dynamic_cast<Option_Menu*>(b);
                // check which option the user chose to run.
                if(pm->GetChoice()==1){
                    op1->execute(bloom_filter,pm->GetUserUrl(),my_vector); 
                } else {
                    op2->execute(bloom_filter,pm->GetUserUrl(),my_vector);
                }
                
            }
        // delete all the meomory.
        delete op2;
        delete op1;
        delete b;
        delete a;
        }

