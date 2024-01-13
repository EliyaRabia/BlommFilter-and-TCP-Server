#include <iostream>
bool firstInputCheck(const std::string& input) {
    int countNumbers = 0;
    bool inNumber = false;

    for (char c : input) {
        if (c == ' ') {
            inNumber = false;
        } else if (std::isdigit(c)) {
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
