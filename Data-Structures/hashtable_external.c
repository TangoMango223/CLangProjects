// Code is practicing implementing a hash table in C
// Link for reference: https://www.youtube.com/watch?v=2Ti5yvumFTU
//SOLUTION #2 - LINKED LIST

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
typedef struct person{
    char name[MAX_NAME];
    int age;
    struct person *next; //refer to itself for next pointer
} 
person; //call this data structure PERSON

//Make the hash table:
person *hash_table[TABLE_SIZE];

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
            //print out each chain
            person *tmp = hash_table[i];
            printf("Slot %i - ", i); 
            while (tmp!= NULL)
            {
                printf("%s - ", tmp->name);
                tmp = tmp->next; //go to the next node
            }
            printf("\n");  //break up the hashtable's
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
    p->next = hash_table[index];
    hash_table[index] = p;
    return true;
}

//Make a Lookup function - Return a pointer to the person if it's in the table, NULL otherwise
person *hash_table_lookup(char *name) 
// We set type as PERSON to force a return. Void = no return values.
{
    int index = hash3(name); //calculate the hash value or the "SLOT" where the name is stored.
    //Make a NODE for the front of the list.
    person *tmp = hash_table[index];

    //Look down the linked list in this SLOT until the name is found
    while (tmp !=NULL && strcmp (tmp -> name, name) != 0)
    {
        tmp = tmp->next;
    }
    return tmp;
}

//Delete function
person *hash_table_delete(char *name) 
{
    int index = hash3(name); //calculate the hash value or the "SLOT" where the name is stored.
    //Find the top of the list for the key/slot:
    person *tmp = hash_table[index];
    //Set previous pointer to NULL for now.
    person *prev = NULL;

    //Look down the linked list in this SLOT until the name is found
    while (tmp !=NULL && strcmp (tmp -> name, name) != 0)
    {
        //Explanation: A-->B-->C. Assume B is being removed.
        //You'll need to connect A-->C, so connect B's next node with previous
        prev = tmp; //set A to equal the old position of B.
        prev = tmp->next; //connect together
    }

    if (tmp == NULL) //name doesn't exist.
    {
        return NULL;
    }

    if (prev == NULL) //this node is the top of the list. Delete the head. There might be stuff 
    {
        hash_table[index] = tmp->next;
    }

    else
    {
        prev->next = tmp->next; //move the current node to be the next node
    }
    return tmp;
}

//Problem - Collission, if multiple  names have the same key/slot

//Solution #1 - Linear Probing - if X is not available, use X+n slot, where n = 1 -> Table_Size
// You modify the code for insert, delete and LOOKUP to do (i+ index) % TABLE_SIZE
//OR, you could do index + i, since index is already adjusted for table_size

//Solution #2 - Linked List
//Each key becomes a linked list. When collision happens, make it a list.


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

    // //See new table's look:
    // print_table();

    // //---Using Lookup function ---- 
    // //Look for Mpho - she is there.
    // person *tmp = hash_table_lookup("Mpho");
    // if (tmp == NULL)
    // {
    //     printf("Not found Mpho!\n");
    // }
    // else
    // {
    //     printf("Found Mpho!\n");
    // }
    
    //Delete Kate
    person *del = hash_table_delete("Robert"); 

    //Print Version 2 of Table
    printf("------------\n");
    printf("Version 2: \n");
    print_table();
    printf("------------\n");

}









//How to insert names manually before initializing hashtable:
// printf("Jacob => %u \n", hash3("Jacob"));
