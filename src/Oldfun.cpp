int firstInputCheck(const string& input) {
            int countNumbers = 0;
            bool inNumber = false;
            bool isCorrectdigit=false;

            for (char c : input) {
                if (c == ' ') { //case of space
                    inNumber = false;
                    if(isCorrectdigit==true){
                        isCorrectdigit=false;
                    }
                } 
                else if (isdigit(c)) { // case that the char is a number
                    if (!inNumber) {
                        ++countNumbers;
                        
                        inNumber = true;
                    }
                    if(countNumbers==2||countNumbers==3){  // in case we are in the second or three number of the input
                        if(isCorrectdigit==false && (c=='2'||c=='1')){ // here we make sure that the second and third input has only one digit: 2 or 1.
                            isCorrectdigit=true;
                            
                        }

                        else{
                            return 0;
                        } 
                    }
                } 
                else {
                    return 0;
                }
            }

            if(countNumbers==2){ //we return 2 in case that there were 2 values in the input
                return 2;
            } 
            if(countNumbers==3){//we return 3 in case that there were 3 values in the input
                return 3;
            }
            else {
                return 0;
            }

        } 
