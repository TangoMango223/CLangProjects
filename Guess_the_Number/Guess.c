//Guess the Number game! WIP 

#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <unistd.h>
#include <stdbool.h>

//Functions used:
bool guess(int *a, int *b);


int main(void)
{
    // Call the random function
    srand(time(0)); 
    int nMax = 100;
    int nMin = 1;

    //Initialize other variables:
    int nGuess = 0;

    // Generate a number first
    int nAnswer = rand() % (nMax - nMin + 1) + nMin;
    printf("Pst! The right number is %i \n", nAnswer);

    //Ask for a guess
    printf("Guess the number: ");
    scanf("%d", &nGuess);

    //Evaluate the Guess
    guess(&nGuess, &nAnswer);
    


    return 0;

}


//Function to GUESS the answer.
bool guess(int *a, int *b)
{
    if (*a == *b)
    {
        printf("Congrats! You got the number right! Let's play again :) \n");
        return 1; //true
    }
    return 0; //false

}


//Function to Answer the question: ODD or EVEN #

//Function to Answer the question: Is this divisible by X?

//Function to Quit This Game

