#include "square_root.h"
#include <stdio.h>
#include <assert.h>

//Function only works for perfect squares up to x^2 <= 4,294,967,296
//Tryed to stay away from this solution because it is well published.
unsigned long squareRoot(unsigned long num){

    assert(num > 0);

    unsigned long x = 0; //Return value
    unsigned long b = 1 << 30; //Highest power of 4 for unsigned long (32 bit type) ** must be an even number
    
    while(b > num){
        b >>= 2; //while b is greater than number continue to divide by 4
    }

    //Test to ensure b is not equal to 0
    while(b != 0){
        if(num >= (x + b)){
            num -= x + b;   //subtract result plus b from number
            x = (x >> 1) + b; // divide result by 2 and add b
        }
        else{
            x >>= 1; // divide result by 2
        }
        b >>= 2; // divide b by 4
    }
    
    return x;
            
}


/*
#include "square_root.h"
#include <math.h>

int squareRoot(const int a){

    //using built in functions this is the most accurate to get to perfect square root
    double euler = 2.71828182;
    return ceil(pow(euler, (log(a)/2)));

    //Using built in functions errors on two test due to truncated decimals
    //double ten = 10;
    //return pow(ten, (log10(a)/2));
    
    //using built in function erros on three test due to truncated decimals test of 25, 196 and 65025
    //return exp(log(a)/2);
}
*/
