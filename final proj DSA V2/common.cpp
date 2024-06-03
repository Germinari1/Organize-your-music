/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= 
//* Author: Lucas Germinari Carreira
//* Date last updated: 04/28/2024
//* Description (utility file): Implements the common functions used in the project, such as input validation.
//* Tested: yes, passed 
//* Notes:
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

#include "common.h"



bool check_string_input(std::string)
{
    ///// Checks a stirng input for failure of input stream
    if(std::cin.fail()){
        std::cerr<<"The input should be a string of text\n";
        reset_input_stream();
        return false;
    }
    return true;
}

void reset_input_stream()
{
    ///// Cleans the input stream and ignores the remaining characters 
    std::cin.clear(); 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
}

bool check_numeric_input(int min, int max,int input, std::string msg_1, std::string msg_2, bool only_upperLim=false, bool only_lowerLim=false)
{
    //////function to valid basic int and double input. In order to use the default messages, "" should be entered as parameters
    
    input = static_cast<double>(input);

    if(!std::cin){
        if(msg_1 != ""){
            std::cout<<msg_1<<std::endl;
        }
        else{
            std::cout<<"The input must be a numeric value."<<std::endl;
        }
        reset_input_stream();
        return false;
    }
    else if (only_lowerLim == true){
        if (min>input){
        if(msg_2 !="")
        {
            std::cout<<msg_2<<std::endl;

        }
        else{
            std::cout<<"Choose a number greater or equal than "<<min<<std::endl;
        }
        return false;
        }
    }
    else if (only_upperLim == true){
        if (max<input){
            if(msg_2 !="")
            {
                std::cout<<msg_2<<std::endl;

            }
            else{
                std::cout<<"Choose a number smaller or equal than "<<max<<std::endl;
            }
            return false;
        }
    }
    else if(input<min || input>max){
        if(msg_2 !="")
        {
            std::cout<<msg_2<<std::endl;

        }
        else{
            std::cout<<"Invalid number"<<std::endl;
        }
        return false;
    }
    return true;
}

