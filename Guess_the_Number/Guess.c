//Guess the Number game! WIP 

#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <unistd.h>
#include <stdbool.h>

//Global Variables


//Functions used:
bool evaluate(int *a, int *b); //evaluate your answer as right or wrong function
void oddeven(int *a); //Odd-even function
void guess(int *a); //guessing function
bool quit(int *l); //quitting function

int main(void)
{
    // Call the random function
    srand(time(0)); 
    int nMax = 100;
    int nMin = 1;

    //Initialize other variables:
    int nGuess = 0;
    int nAnswer = 0;
    int door = 0; //quitting function

    // Generate a number first
    nAnswer = rand() % (nMax - nMin + 1) + nMin;
    printf("Pst! The right number is %i \n", nAnswer);

    //Begin loop - ask and guess
    while (true)
    {
        guess(&nGuess);
        printf("Your guess is: %i \n", nGuess);
        bool TF = evaluate(&nGuess, &nAnswer);  //evaluation time!

        //Will finish the game if user gets the right answer.
        if (TF)
        {
            break;
        }

        quit(&door);
        // bool leave = door;
        // if (door)
        // {
        //     break;
        // }

    }

}

//Function to ask for a NEW guess (assuming they didn't get it the first time)
void guess(int *a)
{
    printf("Guess the Number: ");
    scanf("%d", a);
    return;
}

//Function to GUESS the answer.
bool evaluate(int *a, int *b)
{
    if (*a == *b)
    {
        printf("Congrats! You got the number right! Let's play again! :) \n");
        return 1; //true
    }
    return 0; // false
}

//Function to Answer the question: ODD or EVEN #
void oddeven(int *a)
{
    if ((*a % 2) == 0)
    {
        //The number is even!
        printf("Yes, the number is even. \n There's your hint! \n");
    }
    if ((*a % 2) != 0)
    {
        printf("Your number is odd. \n There's your hint! \n");
    }
    
    return;
}

//Function to Answer the question: Is this divisible by X?

void divisible(int *a, int *b)
{

}

//Function to Quit This Game
bool quit(int *l)
{
    char *a;
    printf("Would you like to quit? y = Yes, n = No:  ");
    scanf("%c", a);

    char *b = "y";
    int result = 0;
    result = strcmp(a,b);

    if (result == 0)
    {
        return 1;
    }
    return 0;
}