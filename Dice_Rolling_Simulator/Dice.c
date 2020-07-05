//Dice Rolling Simulator! V2

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
    //Formula: https://stackoverflow.com/questions/1202687/how-do-i-get-a-specific-range-of-numbers-from-rand
    srand(time(0)); 

    //Define Mix and Max. 
    int nMax = 6;
    int nMin = 1;

    //Ask User how many times they want to roll...
    printf("How many times do you want to roll? This dice is 6-sided: ");
    int count = 0;
    scanf("%d", &count);

    //Implementing sleep: https://www.poftut.com/what-is-sleep-function-and-how-to-use-it-in-c-program/#:~:text=C%20programming%20language%20provides%20sleep,will%20run%20without%20a%20problem.

    //Counter variables: will note down how many times it shows up
    int side[7]; //make an array

    for (int i = 0; i < 7; i++) //Define 1 to 6
    {
        side[i] = 0;
    }

    //For loop
    for (int i =0; i< count; i++)
    {
        int nR = rand() % (nMax - nMin + 1) + nMin;
        printf(" The diced rolled... %d \n", nR); //taken from Stack Overflow site
        sleep(1);

        //Tally the number of times each number was rolled, for testing purposes
        for (int a = 1; a < 7; a++) //Define 1 to 6. I did 1-7 because I got an Abort Trap error in C. 
        {
            if (nR == a)
            {
                side[a] ++;
            }
        }
    }
    
    printf("\n Printing the results: \n");
    printf("------------------------\n");
    for (int a = 1; a < 7; a++)
        {
            printf("Side %i rolled: %i time(s) \n",a,side[a]);
        }
    printf("------------------------\n");
    return 0;
}