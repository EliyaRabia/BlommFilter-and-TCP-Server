#include <iostream>
#include <string>
using namespace std;
bool firstInputCheck(const string& input) {
    int countNumbers = 0;
    bool inNumber = false;

    for (char c : input) {
        if (c == ' ') {
            inNumber = false;
        } else if (isdigit(c)) {
            if (!inNumber) {
                ++countNumbers;
                inNumber = true;
            }
        } else {
            return false;
        }
    }

    return countNumbers == 2 || countNumbers == 3;
}
bool isCustomURL(string input) {
    // Check if the input starts with "www." and ends with ".com"
    return (input.compare(0, 4, "www.") == 0 && input.length() > 8 &&
            input.compare(input.length() - 4, 4, ".com") == 0);
}
