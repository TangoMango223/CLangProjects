// Code is practicing implementing a hash table in C
// Link for reference: https://www.youtube.com/watch?v=2Ti5yvumFTU

#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <unistd.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

//Define data structure to hold the person's info
typedef struct{
    char name[MAX_NAME];
    int age;
    // ...other stuff later
} person; //call this data structure PERSON

//MAKE THE HASH TABLE. Make a hash table using pointers for easy space.
//above is initialized as pointer.
person *hash_table[TABLE_SIZE];


//Hashfunction - look up people by name:
//HASH FUNCTION VERSION #1 - add the sum of the ascii values together.
//Better than returning a constant, but NOT random enough.
unsigned int hash1(char *name)
{
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for (int i =0; i < length ; i++)
    {
        hash_value = hash_value + name[i];
    }
        return hash_value;
}

//HASH FUNCTION VERSION #2 - add the ascii values each time, but each time, also multiply the value
unsigned int hash2(char *name)
{
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for (int i =0; i < length ; i++)
    {
        hash_value = hash_value + name[i]; //addition
        hash_value = hash_value * name[i]; //multiply
    }
// PROBLEM WITH THIS HASH FUNCTION - HASH VALUES are way too big.
// Go to Hash Function Version #3
        return hash_value;
}

//HASH FUNCTION VERSION #3 - add the ascii values each time, but each time, also multiply the value
unsigned int hash3(char *name)
{
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for (int i =0; i < length ; i++)
    {
        hash_value = hash_value + name[i]; //addition
        hash_value = (hash_value * name[i]) % TABLE_SIZE; //after multiplying, divide by TABLE_SIZE but only return 
        // return the remainder, since remainder will always be 1 < x < Table Size - 1.
    }
    return hash_value;
}

// Hash Value needs to have consistent hash_values and needs to fix in the table.
//Need to resolve collission too. 

//Initialize hash table
void init_hash_table ()
{
    for (int i = 0 ; i< TABLE_SIZE; i++)
    {
        hash_table[i] = NULL;
    }
    return;
    //table is empty for now.

}

//Print what's stored in the hash table
void print_table()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hash_table[i] == NULL)
        {
            printf("\t%i\t---\n", i);
        }
        else
        {
            printf("\t%i\t%s\n", i,hash_table[i]->name);
            //Refresher: -> or arrow notation is used in C.
            // means (*hash_table[i]).name; used if the variable is initialized as pointer
        }
    }
    return;
}

//Main function

int main (void)
{
    init_hash_table ();
    print_table();
    //Example different names
    // printf("Jacob => %u \n", hash3("Jacob"));
    // printf("Natalie => %u \n", hash3("Natalie"));
    // printf("Sara => %u \n", hash3("Sara"));
    // printf("Mpho => %u \n", hash3("Mpho"));
    // printf("Tebogo => %u \n", hash3("Tebogo"));
    // printf("Ron => %u \n", hash3("Ron"));
    // printf("Jane => %u \n", hash3("Jane"));
    // return 0;

}

