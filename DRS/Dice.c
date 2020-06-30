#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdio.h> 
#include <stdlib.h> 
#include<time.h> 


//Initialize the main function

int main(void)
{
    //Using the random formula from the following link: https://www.tutorialspoint.com/c_standard_library/c_function_rand.htm#:~:text=The%20C%20library%20function%20int,to%20be%20at%20least%2032767.
    //Formula: https://stackoverflow.com/questions/17846212/generate-a-random-number-between-1-and-10-in-c
    srand(time(0)); 

    //Define Mix and Max for a 6-sided dice
    int nMax = 6;
    int nMin = 1;

    for(int i = 0; i<1; i++) 
    {
        printf(" %d \n", rand() %(nMax-nMin) + nMin); //taken from Stack Overflow site
    }
    return 0; 

}