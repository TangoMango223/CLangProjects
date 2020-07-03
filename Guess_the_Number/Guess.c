//Guess the Number game! WIP 

#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <unistd.h>

//int guess(int a, int b)

int main (void)
{
    // Call the random function
    srand(time(0)); 
    int nMax = 100;
    int nMin = 1;

    //Other variables:
    int nGuess = 0;

    // Generate a number first
    int nAnswer = rand() % (nMax - nMin + 1) + nMin;
    printf("%i \n", nAnswer);

    //Ask for a guess
    printf("Guess the number: ");
    scanf("%i", nGuess);
    printf("Your guess was: %i \n", nGuess);


    return 0;

}


//Function to GUESS the answer.
// int guess(int a, int b)
// {
//     if (a == b)
//     {
//         printf("Congrats! You got the number right! Let's play again :) \n");
//     }

//     else
//     {
//         //Game needs to continue
//         return 1;
//     }
//     return 0;
// }


//Function to Answer the question: ODD or EVEN #

//Function to Answer the question: Is this divisible by X?

//Function to Quit This Game

