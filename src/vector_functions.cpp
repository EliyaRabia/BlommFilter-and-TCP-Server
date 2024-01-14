#include <iostream>
using namespace std;
#include <string>
#include <vector>

bool checkIfUrlExist(vector<string> urls, string new_url){
    for (string i : urls) {
        if(i.compare(new_url)==0){
            return true;
        }
    }
    return false;
}

int main ()   
{   
    vector<string> check;
    check.push_back("10");
    check.push_back("20");
    check.push_back("30");
    check.push_back("30");
    check.push_back("30");
    for (string i : check) {
        cout << i << " " << endl;
    }
    cout << checkIfUrlExist(check,"10") << endl;
    cout << checkIfUrlExist(check,"100") << endl;
    return 0;  
}  
