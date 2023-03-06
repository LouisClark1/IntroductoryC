// standard input output
#include <stdio.h>
#define globVar 0.001 //this is an old method, now people mostly use const for the control of variable type and scope 

double adder(double A, double B){   //c does pass by value but mimics pass by reference. 
                                    //This is why you need to say the variable types in the function header
                                    //it also means that the result of editing values in a function is not global
                                    //if you pass in a reference it will make a local copy of the reference but 
                                    //will still be able to edit the global variable the adress is pointing to
    double C = A + B;
    B = 100000;

    return C;
}



int main(){
    const int locConst = 22;
    double result;
    printf("locConst = %i before running the function\n", locConst);
    result = adder(globVar,locConst);
    printf("The sum of the numbers is %lf\n", result);
    printf("locConst = %i after running the function showing we can not change it from inside the function\n", locConst);
    return 0;
}