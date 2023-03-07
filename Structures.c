#include <stddef.h>
#include <stdio.h>

struct time{
        int sec;
        int min;
        int hour;
    };

struct intPtrs{
    int * ptr1;
    int * ptr2;
};



void getInfo(struct namect * pst){
    //I can't be bothered writing the code here but the point is that you need to allocate memory when making these variables because we only pass in the pointer so there is no memory for the variable yet
};

int main(){
    struct date // cna also do a structure inside a structure, self explanatory
    {
        int day;    //structure members, can be different types
        int month;
        int year;
    }tomorrow = {.month = 03, 2021};

    struct date today;  //memory is now allocated
    today.day = 01;
    today.month = 02;
    today.year = 2021;

    today = (struct date){01,02,2020};

    struct date dateArray[5];

    // dateArray[0] = (struct date) {01,02,2020};   //this works fine
    // dateArray[1] = (struct date) {02,02,2020};
    // dateArray[2] = (struct date) {03,02,2020};
    // dateArray[3] = (struct date) {04,02,2020};
    // dateArray[4] = (struct date) {05,02,2020};

    // dateArray = (struct date) { {01,02,2020}, {02,02,2020}, {03,02,2020}, {04,02,2020}, {05,02,2020} };

    struct date dateArrayOther[5] = { {01,02,2020}, {02,02,2020}, {03,02,2020}, {04,02,2020}, {05,02,2020} };


    struct dateAndTime{
        struct date strucDate;    //struct date alone is not enough as it is only a variable type, we need to initialise a variable
        struct time strucTime;
    };

    struct dateAndTime event = {{01,02,2054}, {01,05,21}};
    event.strucDate.day = 01;


    // we can make a pointer to a structure, they are easier to manipulate that structures themselves
    struct date * pToday = NULL;    //memory to store the pointer
    pToday = &today;          //memory to store object
    (*pToday).day = 5;          //does not work without these brackets
    pToday -> day = 5;          //this is the same as above

    struct intPtrs structureOfPointers;
    int int1 = 55, int2;
    structureOfPointers.ptr1 = &int1;
    structureOfPointers.ptr2 = &int2;

    *structureOfPointers.ptr2 = 24;

    printf("int1 = %i, *structureOfPointers.ptr1 = %i\n\n\n",int1,*structureOfPointers.ptr1);

    return 0;
}