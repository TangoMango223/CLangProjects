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

//Hashfunction - look up people by name:
unsigned int hash(char *name)
{
    return 5;
}


int main (void)
{
    //Example different names
    printf("Jacob => %u \n", hash("Jacob"));
    printf("Natalie => %u \n", hash("Natalie"));
    printf("Sara => %u \n", hash("Sara"));
    printf("Mpho => %u \n", hash("Mpho"));
    printf("Tebogo => %u \n", hash("Tebogo"));
    return 0;

}

