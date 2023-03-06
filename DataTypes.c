// standard input output
#include <stdio.h>
//include the bool datatype so you can type bool instead of _Bool
#include <stdbool.h>
//library of string functions
#include <string.h>
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



   int i = 0;
   exampleFloat= 100.2f;  // the f on the end explicitly states that it is a float
   exampleFloat = exampleFloat * 5.0f; // the f here stops example float from being propoted to a double
   exampleFloat *= 5.0f; // the above line can be written as 
   //enum will give compiler error if you assign a value to it the I did not allow, good for things like months
   enum mySizeVarType {big, medium, small=8};  //state allowable values (they are stored as intigers from position in the list), can overwrite the value in the list
   enum mySizeVarType object1, object2;      //create the variables
   object1 = big;                            //assign values

    char exampleString[] = {"Hello mate"};
   bool exampleBoolean = 1; 

   printf("the value of the enum was; %d\n", object1);

//    printf("Enter a number and a word: ");
//    char str[100];
//    scanf("%d %s", &i, str);

//    printf("\nYou entered: %d and %s\n", i, str); //the %d ans %s are called format specifiers
   printf("Look who it is, %s\n",exampleString);


    float sampleFloatArray[20] = {sampleFloatArray[2] = 50.2, sampleFloatArray[8] = 13.13};
    // sampleFloatArray = sampleFloatArray + 10;
    printf("floatArray, %f",sampleFloatArray[20]);

    return 0;
}