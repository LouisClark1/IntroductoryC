# include <stdio.h>
# include <stdlib.h>

int arraySum (int *array, const int n);
int *returnPointer(int *somePointer);

int main(){
    int exampleInt = 5;
    int *pExampleInt = &exampleInt;     //this & is the adress of operator. 


    //to operate on the value being pointed to
    *pExampleInt += 6;
    printf("The pointer adress is %p\n", &pExampleInt); //you don't actually need the & here. It displays a different thing. pointer or adress of pointer
    printf("The new value is %i\n", *pExampleInt);

    int newNumber = 11;
    int *pNewNumber = NULL; //0 works here instead of NULL
    //it is important to use this null adress when making uninitialised pointers, if we just do int *pNewNumber then the 
    //pointer points to nothing/no memory allocated to it, because it only allocates memory for the adress to be stored in the 
    //pointer, not memory to store the value it is pointing to. if we then do *pNewNumber = newNumber; it will store the value 
    //newNumber in some random place

    pNewNumber = &newNumber;    //since the pointer was null, here we are storing the adress of new number in the pointer

    printf("Here we are going to change the value, type an int:\n");
    // scanf("%i", pExampleInt);           //the second argument of scanf is the pointer
    printf("The value has now changed to, %i\n", exampleInt);

    //making a constant
    long exampleLong = 10053L;
    printf("Creating long value: %ld\n",exampleLong);
    const long *pExampleLong = &exampleLong;            //can not use this pointer to modify exampleLong
    printf("Setting a const pointer \"%p\" to the long\n",pExampleLong);
    exampleLong++;
    printf("We can still change the value being pointed to;\nNew long value is: %ld\n",exampleLong);
    long newLong = 153L;
    pExampleLong = &newLong;
    printf("We can point the pointer to an new long %ld\n",newLong );
    // *pExampleLong += 5;
    printf("We can not alter the value being pointed to through the pointer, e.g;   *pExampleLong += 5;\n");
    //to ensure the adress can not change
    long *const pConst = &exampleLong;
    // pConst = &newLong;       //you cant do this

    //using a void pointer does not specify the variable type that the pointer is pointing to. Good for functions
    exampleInt = 55;
    float exampleFloat = 5.236;
    char exampleChar = 'l';
    void * pVoidPointer;

    pVoidPointer = &exampleInt;
    printf("Using the void pointer for an int %i\n", exampleInt);
    pVoidPointer = &exampleFloat;
    printf("Using the void pointer for a float %.2f\n", exampleFloat);
    pVoidPointer = &exampleChar;
    printf("Using the void pointer for a char %c\n", exampleChar);


    //arrays are basically a pointer themselves, when we point to an array element, we just point to the whole array
    int intArray[100] = {[1] = 55, [2] = 50, [8] = 13};
    int * pArray = NULL;
    pArray = intArray;      //see here there is no & pArray points to the first element
    pArray = &intArray[0];  //this is the same thing as the line above

    //intArray[i] and *(intArray + 1) are the same thing
    // pArray++;           //is valid
    // intArray++;      // is not valid, We can not add to intArray because, while it is a pointer, it will always point to the first element of the array
    printf("This was called from the array using a pointer: %i\n",*(pArray + 2));
    printf("This is what happens when we print the array name: %p   It will always point to the first element in the array and can not be changed\n", intArray);

    printf("The sum of the array is: %i\n", arraySum(intArray,100));  //intArray is just a pointer to the array, we can edit the array from within a function

    printf("This is to make sure I have a function returning pointers working\n     This is a pointer adress: %p    This is the value: %i\n",pExampleInt,*pExampleInt);
    printf("The pointer was passed to a function that adds 1 to the value inside the function\n     The pointer adress becomes: %p",returnPointer(pExampleInt));
    printf("    This is the value: %i\n",*pExampleInt); //this needs to be on a new line of code for the print to show the new result

//----------------------------------------------------------dynamic memory allocation-------------------------------------------------------------------------
    int array[1000];    //fixed array size, trying to read in more data will break the programme
    //dynamic memory allocation dictates memory on execution not on compiling I think...
    //this will exist on the heap, things like function local variables are created on the stack and are deleted on leaving the function
    //malloc, you give it bytes and it returns the adress location for you to store in a pointer

    //if we want to store 25 ints,
    // int * pMemAlloc = (int*)malloc(100);    //100 bytes cast to an int pointer, this may not work on a different system
    int * pMemAlloc = (int*)malloc(25 * sizeof(int));   //this is better 
    //it is good practice to catch if the allocation failed and just returns null, should also do this dereferencing pointers too
    if(!pMemAlloc){
        printf("FAIL");
    }
    *pMemAlloc = 5; 
    printf("This is acessing the memory before it was freed: %i\n",*pMemAlloc);
    //releasing memory. Will automatically delete when the programme ends
    free(pMemAlloc);
    printf("This is the adress for the user allocated memory: %p\n",pMemAlloc);
    printf("This is trying to access the memory after it was freed: %i\n",*pMemAlloc);  //the freed memory goes back to 0s
    pMemAlloc = NULL;   //this is best practice because the pointer is now pointing to freed memory that can be used by other things

    //when we allocate memory there may be some eronious data stored there, calloc sets it to 0
    pMemAlloc = (int*)calloc(25,sizeof(int));
    if(!pMemAlloc){
        printf("FAIL");
    }
    //if our memory is too small we can use realloc to make a new memory pointer that points somewhere else (may be fragmented) and contains the new size, 
    //it also preserves the memory contents that was stored in the old location
    pMemAlloc = (int*)realloc(pMemAlloc,25*sizeof(int));
    free(pMemAlloc);
    pMemAlloc = NULL;
    //!!!!!!!!!!!!!!!!!Try not to allocate lots of small bits of memeory, there is some overhead associated with storing things in the heap









    printf("\n\n\n");
    return 0;
}
//-----------------------------------------we can only put functions below main if we have the same prototype function at the top--------------------------------

// int arraySum (int array[], const int n){        //this does work. Input the array and its length
//     int sum = 0, *pntr;                         //initialise a sum variable and null pointer
//     int * const arrayEnd = array + n;           // points to the final element
//     for ( pntr = array; pntr < arrayEnd; ++pntr){   //point to the first element, pointer is less than length, point up one
//         sum +=*pntr;                            //step up the sum by the value pointed to 
//     }
//     return sum;
// }

int arraySum (int *array, const int n){         //the same function can also be written like this. Here we are asking for an array pointer to be inputted
                                                //this is more succinct but makes it less clear that the function is using an array
    int sum = 0;
    int * const arrayEnd = array + n;
    for (; array < arrayEnd; ++array){          //we don't use *array becuase this logic is for the indicies. array is the pointer and is counted up
                                                //i think we can only alter array here because it is local to the function and not intArray its-self
        sum += *array;                            
    }
    return sum;
}

int *returnPointer(int *somePointer){   //the * in the function name is to show that it returns a pointer
    *somePointer += 1;
    return somePointer;
}