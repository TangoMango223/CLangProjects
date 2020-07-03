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

    //Define Mix and Max for a 6-sided dice
    int nMax = 6;
    int nMin = 1;

    //Ask User how many times they want to roll...
    printf("How many times do you want to roll?: ");
    int count = 0;
    scanf("%d", &count);

    //Implementing sleep: https://www.poftut.com/what-is-sleep-function-and-how-to-use-it-in-c-program/#:~:text=C%20programming%20language%20provides%20sleep,will%20run%20without%20a%20problem.


    //Counter variables: will note down how many times it shows up
    int count_1 = 0;
    int count_2 = 0;
    int count_3 = 0;
    int count_4 = 0;
    int count_5 = 0;
    int count_6 = 0;

    //For loop
    for (int i =0; i< count; i++)
    {
        int nR = rand() % (nMax - nMin + 1) + nMin;
        printf(" The diced rolled... %d \n", nR); //taken from Stack Overflow site
        sleep(1);

        //Tally the number of times each number was rolled, for testing purposes
        if (nR == 1) //count the 1's
        {
            count_1 = count_1+ 1;
        }

        if (nR == 2) //count the 2's
        {
            count_2 = count_2+ 1;
        }

        if (nR == 3) // count the 3's
        {
            count_3 = count_3+ 1;
        }

        if (nR == 4) // count the 3's
        {
            count_4 = count_4+ 1;
        }

        if (nR == 5) // count the 3's
        {
            count_5 = count_5+ 1;
        }

        if (nR == 6) // count the 3's
        {
            count_6 = count_6+ 1;
        }

    }
    
    printf("\n Printing the results: \n");
    printf("------------------------\n");
    printf("Dice Roll 1 : %i time(s) \n", count_1);
    printf("Dice Roll 2 : %i time(s) \n", count_2);
    printf("Dice Roll 3 : %i time(s) \n", count_3);
    printf("Dice Roll 4 : %i time(s) \n", count_4);
    printf("Dice Roll 5 : %i time(s) \n", count_5);
    printf("Dice Roll 6 : %i time(s) \n", count_6);

}