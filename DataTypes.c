// standard input output
#include <stdio.h>
int main(){    
    //type conversions
    float exampleFloat = 12.5568;
    int exampleInt = 0;
    unsigned int a;
    exampleInt = exampleFloat;  //the int becomes 12 because it is truncated
    printf("equating an int type to a float of 12.5568 gives %i\n", exampleInt);

    //casting has almost the highest precedence
    a = (int)21.55 + (int)24.9;
    printf("a = (int)21.55 + (int)24.9 =%i\n", a);
    // when doing arithmetic operations on different data types the less precise values are promoted to match the highest
    float b = exampleFloat * exampleInt;
    printf("(float)12.5568 + (int)12 = %lf\n", b);

    //size of is a keyword to tell us how many bites are used, is an operator not a function
    printf("sizeof(int) = %li, this shows the number of bytes not bits. If  I continue \0 writing\n\n", sizeof(a));
    // the \0 here is how strings are terminated so I will interupt the read and stop it early
}