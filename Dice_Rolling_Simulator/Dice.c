#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <unistd.h>

//Initialize the main function

int main(void)
{
    //Using the random formula from the following link: https://www.tutorialspoint.com/c_standard_library/c_function_rand.htm#:~:text=The%20C%20library%20function%20int,to%20be%20at%20least%2032767.
    //Formula: https://www.programmingsimplified.com/c-program-generate-random-numbers
    srand(time(0)); 

    //Define Mix and Max for a 6-sided dice
    int nMax = 6;
    int nMin = 1;

    //Ask User how many times they want to roll...
    printf("How many times do you want to roll?: ");
    int count = 0;
    scanf("%d", &count);

    //Implementing sleep: https://www.poftut.com/what-is-sleep-function-and-how-to-use-it-in-c-program/#:~:text=C%20programming%20language%20provides%20sleep,will%20run%20without%20a%20problem.

    //For loop
    for (int i =0; i< count; i++)
    {
        int nRandomNumber = rand() % (nMax + 1);
        printf(" The diced rolled... %d \n", nRandomNumber); //taken from Stack Overflow site
        sleep(1);
    }
    return 0;

}