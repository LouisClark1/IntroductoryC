#include <stdio.h>
int main(){
    unsigned int a = 60; //0011 1100    the spaces are just for visual convenience
    unsigned int b = 13; //0000 1101
    int result;

    result = a & b; // this does the and operation on each bit in turn so should give 0000 1100, which is 12

    result = a | b; //turn on the bit if either are true, should give 0011 1101 which is 61

    result = a ^ b; //this is XOR outputting 1 if bits are opposite, gives 0011 0001 which is 49

    result = b << 2; //this shifts all the binary values to the left by two and gives 0011 0100

    result = result >> 2; //and back again so result becomes the original value of b

    result = ~a;    //this is the bitwise complement, flips every bit 60 -> -61
                    //the signed bit (-2^7 in an 8 bit number) is 1 larger than the possible positive value

    printf("output of the logic is %d\n", result);
    
    return 0;
}
