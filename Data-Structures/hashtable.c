// Code is practicing implementing a hash table in C
// Link for reference: https://www.youtube.com/watch?v=2Ti5yvumFTU
//Left off at 10:52 in the video


#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <unistd.h>
#include <stdbool.h>

// https://www.techonthenet.com/c_language/constants/create_define.php
// #define sets global constants!
#define MAX_NAME 256
#define TABLE_SIZE 10

//Define data structure to hold the person's info
typedef struct{
    char name[MAX_NAME];
    int age;
    // ...other stuff later
} 
person; //call this data structure PERSON

//MAKE THE HASH TABLE. Make a hash table using pointers for easy space.
// the Hash table has to take the data struct of "person" above to fill it in.
person *hash_table[TABLE_SIZE];
//REMEMBER - the data structure must be the same for the hash-table and the structure for storing data.


//Hash Function - look up people by name:
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
//Disadvantage - Linear Probing takes longer, since it's looping thru every pointer...
//

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
        if (hash_table[i] == NULL) // the hash table itself, checking
        {
            printf("Slot %i: NULL \n", i);
        }
        else
        {
            printf("%i | name is %s \n", i,hash_table[i]->name);
            //Refresher: -> or arrow notation is used in C.
            // means (*hash_table[i]).name; used if the variable is initialized as pointer
        }
    }
    return;
}

// Make a function to INSERT into each slot
bool hash_table_insert(person *p)
{
    if (p == NULL)  //prevent calling null pointers, inserting with a NULL table.
    {
        return false; //do nothing
    }

    //Store the person via the hash value now:
    int index = hash3(p->name); //p->value refers to the hash table "p"'s name values
    //int index stores and hashes the value from this.
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (index + i);
        if (hash_table[try] == NULL)
        {
            //we store the name here here.
            hash_table[try] = p;
            return true;
        }        
    }
    // if (hash_table[index] != NULL) //Detect collisions, i.e. multiple people with the same name
    // {
    //     return false; 
    // }

    // hash_table[index] = p; //if the spot is available, set the hash-table spot to store p's name.
    return false;
}

//Make a Lookup function - Return a pointer to the person if it's in the table, NULL otherwise
person *hash_table_lookup(char *name) 
// We set type as PERSON to force a return. Void = no return values.
{
    int index = hash3(name); //calculate the hash value or the "SLOT" where the name is stored.
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (i + index);
        if ((hash_table[try]!= NULL) && (strcmp(name, hash_table[try]->name) ==0))
        {
            return hash_table[try]; //found
        }
        
    }
    return false; //end it.
}

//Delete function
person *hash_table_delete(char *name) 
// We set type as PERSON to force a return. Void = no return values.
{
    int index = hash3(name); //calculate the hash value or the "SLOT" where the name is stored.
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (i + index);
        if ((hash_table[try]!= NULL) && (strcmp(name, hash_table[try]->name) ==0))
        {
            hash_table[try] = NULL; //deleted.
        }
    }
    return false;
}

//Problem - Collission, if multiple  names have the same key/slot
//Solution #1 - Linear Probing - if X is not available, use X+n slot, where n = 1 -> Table_Size
// You modify the code for insert, delete and LOOKUP to do (i+ index) % TABLE_SIZE
//OR, you could do index + i, since index is already adjusted for table_size


//Main function
int main (void)
{
    //Start off:
    init_hash_table ();
    //print_table();

    //Create Jacob, Kate and Mpho
    person jacob = {.name = "Jacob", .age = 20};
    person kate = {.name = "Kate", .age = 20};
    person mpho = {.name = "Mpho", .age = 20};
    person maren = {.name = "Maren", .age = 20};
    person sarah = {.name = "Sarah", .age = 20};
    person edna = {.name = "Edna", .age = 20};
    person eliza = {.name = "Eliza", .age = 20};
    person robert = {.name = "Robert", .age = 20};
    person jane = {.name = "Jane", .age = 20};

    //Add to the hashtable.
    //use this format because hash_table_insert only takes person format.
    hash_table_insert(&jacob);
    hash_table_insert(&kate);
    hash_table_insert(&mpho);
    hash_table_insert(&maren);
    hash_table_insert(&sarah);
    hash_table_insert(&edna);
    hash_table_insert(&eliza);
    hash_table_insert(&robert);
    hash_table_insert(&jane);

    //See new table's look:
    print_table();

    //---Using Lookup function ---- 
    //Look for Mpho - she is there.
    person *tmp = hash_table_lookup("Mpho");
    if (tmp == NULL)
    {
        printf("Not found Mpho!\n");
    }
    else
    {
        printf("Found Mpho!\n");
    }

    //Look for George, he's not there.
    tmp = hash_table_lookup("George");
    if (tmp == NULL)
    {
        printf("Not found George!\n");
    }
    else
    {
        printf("Found George!\n");
    }
    
    //Delete Mpho
    person *del = hash_table_delete("Mpho"); 

    //Print Version 2 of Table
    printf("------------\n");
    printf("Version 2: \n");
    print_table();
    printf("------------\n");

}









//How to insert names manually before initializing hashtable:
// printf("Jacob => %u \n", hash3("Jacob"));
