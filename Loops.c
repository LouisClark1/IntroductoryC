// standard input output
#include <stdio.h>
int main(){

    unsigned int a = 1;
    //------------------------------use a while not a for if we dont need to initialise a counter variable (a in this case)
    // for a while, 0 is false and anything else is true
    for (a = 0; a < 20; a = a + 2){
        printf("a = %i\n", a);
        if(a == 9){                //if you change this logic to an odd number then the final is only used after the loop
            goto final;
        } 
    }
        
    final: printf("a after goto = %i\n\n", a);


    //continue
    for (a = 0; a < 15; a++){
        if(a == 3 || a == 6){               // this shows the continue function that doesn't break out of the loop but does does skip the rest of the code for this loop
            continue;
        } 
        printf("%i\n", a);
        if(a == 9){
            break;                          // you can leave early using the break
        }
    }
    return 0;
}