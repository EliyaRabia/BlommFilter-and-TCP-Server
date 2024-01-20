#include <iostream>
#include "App.h"

using namespace std;  
int main() {
    App* ap = new App();
    ap->run();
    delete ap;
    return 0;
}