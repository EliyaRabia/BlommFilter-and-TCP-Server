#include <iostream>
using namespace std;  
#include "./App.cpp"
int main() {
    App* ap = new App();
    ap->run();
    delete ap;
    return 0;
}