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
bool evaluate(int *a, int *b); //evaluate your answer as right or wrong function
void oddeven(int *a); //Odd-even function
void guess(int *a); //guessing function
bool quit(); //quitting function
bool hint(); //hint function


int main(void)
{
    // Call the random function
    srand(time(0)); 
    int nMax = 100;
    int nMin = 1;

    //Initialize other variables:
    int nGuess = 0;
    int nAnswer = 0;

    // Generate a number first:
    nAnswer = rand() % (nMax - nMin + 1) + nMin;
    printf("Pst! The right number is %i \n", nAnswer); //REMOVE LATER CHRISTINE!

    //Begin loop - User can begin to guess the prompt, and be told if they're wrong/right!
    while (true)
    {
        //Ask for Guess and then evaluate it: 
        guess(&nGuess);
        //This will end the game if the user gets it right. Otherwise, it'll keep going.
        if (evaluate(&nGuess, &nAnswer))
        {
            break;
        }

        if (quit())
        {
            break;
        }
    }

}

//Function to GET A HINT - 1 per turn/round
bool hint()
{
    //user can only get 1 hint per turn
    printf("Would you like a hint? 1 per turn (y = yes, n =no): ");
    char *hintInput; //store the hint
    scanf("%s", hintInput);

    int result = 1; //default to 1

    //Compare strings
    result = strcmp("y",hintInput);
    if (result == 0)
    {
        return 1;
    }
    printf("No hint? Ok no worries, let's keep going in the game. \n");
    return 0;

}

//Function to ask for a NEW guess (assuming they didn't get it the first time)
void guess(int *a)
{
    printf("Guess the Number: ");
    scanf("%d", a);
    printf("Your guess is %i! \n", *a);
    return;
}

//Function to GUESS the answer - true/false
bool evaluate(int *a, int *b)
{
    if (*a == *b)
    {
        printf("Congrats! You got the number right! Let's play again! :) \n");
        return 1; //true
    }
    printf("Sorry - your number is wrong. Keep guessing! \n");
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

//Function to RAGE - Quit This Game 
bool quit()
{
    printf("Would you like to quit? (y = Yes, n = No ): " );
    char *d;
    scanf("%s", d);

    int result = 1;
    //Compare strings
    result = strcmp("y",d);

    if (result == 0) //if the user types "yes"
    {
        printf("Thanks for playing - let's play again! \n");
        return true;
    }
    return false;
}