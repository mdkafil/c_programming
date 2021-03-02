#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bankEmployee   // NODE
{
	char name[20];  // Values
	int salary;     // values
	struct bankEmployee *next; // Reference to other NODE
};			

typedef struct bankEmployee BANKEmployee;  // Just to reduce redundancy in code
typedef BANKEmployee *BANKEmployeePtr;

int main(){
	
	BANKEmployeePtr startptr = NULL; // Q1 - Part A
	//----Creating a Linked List
	BANKEmployeePtr newptr;			// Point to a new node
	BANKEmployeePtr preptr;		// Point to the previous node
	BANKEmployeePtr curptr;		// Point to the Current Node; this will also help us to print the node
	//----Deleting the Linked list-----//
	BANKEmployeePtr temp;		// Point to the Current Node
	
	newptr = malloc (sizeof (BANKEmployee)); // Actual size of the node is 24B; must be a real address
	strcpy(newptr->name, "Justin");
	newptr->salary = 1000;
	newptr->next = NULL;
	// We are done with part B
	
	startptr =  newptr;
	curptr = newptr;
	preptr = newptr;
	
	newptr = malloc (sizeof (BANKEmployee)); 
	strcpy(newptr->name, "Sam");
	newptr->salary = 2000;
	newptr->next = NULL;
	
	curptr->next = newptr;
	curptr = curptr->next;

	newptr = malloc (sizeof (BANKEmployee)); 
	strcpy(newptr->name, "Antony");
	newptr->salary = 200;
	newptr->next = NULL;
	
	startptr = newptr;
	startptr->next = preptr;
	

	newptr = malloc (sizeof (BANKEmployee)); 
	strcpy(newptr->name, "Tony");
	newptr->salary = 300;
	newptr->next = NULL;
	
	curptr->next = newptr;
	preptr=curptr;
	curptr = curptr->next;
	
	newptr = malloc (sizeof (BANKEmployee)); 
	strcpy(newptr->name, "Peter");
	newptr->salary = 400;
	newptr->next = NULL;
	
	startptr->next->next = newptr;
	newptr->next = preptr;
	
	//curptr = newptr;
	//curptr->next = preptr;
	//preptr=startptr->next;
	//preptr->next = curptr;
	
	
	
    curptr = startptr;
	
	while(curptr!=NULL){
		printf("\n Last name: %s  Grade: %d ", curptr->name, curptr->salary);
		curptr = curptr->next;
	}

}