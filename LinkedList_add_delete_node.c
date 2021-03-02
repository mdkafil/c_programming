#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct{
	char name[20];
	int id;
	struct student *next;
	
}student;

int get_random(){
	
	return rand()%100+1;
}

student* create_list(){
	student *start=NULL, *newnode, *prePtr=NULL, *curPtr=NULL;
	int count=0;
	while(count<5){
	newnode=(student*)malloc(sizeof(student));
	printf("Enter name of the student...\n");
	gets(newnode->name);
	newnode->id=get_random();
	newnode->next=NULL;
	if(start == NULL)
		start=newnode;
	else{
		curPtr=start;
		while(curPtr!=NULL && newnode->id > curPtr->id){
			prePtr = curPtr;
			curPtr = curPtr->next;
		}
		if(prePtr==NULL){
			newnode->next = start;
			start = newnode;
		}
		else{
			prePtr->next = newnode;
			newnode->next=curPtr;
		}
	}
	count++;
	}
	
	return start;
}

// Console printing
void display_list(student *curPtr){
	while(curPtr!=NULL){
		printf("%s -> %d \n",curPtr->name, curPtr->id);
		curPtr=curPtr->next;
	}
}
/*
void print_reverse(student *curPtr){
	if(curPtr==NULL)
		return;
	print_reverse(curPtr->next);
	printf("%s -> %d \n", curPtr->name, curPtr->id);
}
*/
// IO printing or file printing
/*
void print_to_file(student *curPtr){
	
	FILE *fp = fopen("student.txt","w+"); // appending mode
	while(curPtr!=NULL){
		fprintf(fp,"%s -> %d \n",curPtr->name, curPtr->id);
		curPtr=curPtr->next;
	}
	...// Close the file
}
*/

student * delete(student *start, char *name){
	
	student  *prePtr, *curPtr;
	
	// LOGIC Starts here
	if(strcmp(name, start->name)==0){
		start = start->next; // start =NULL De-threading
	}
	else{
		prePtr = start;
		curPtr = start->next;
		while(curPtr!=NULL && strcmp(name, curPtr->name)!=0){  // walk through...until a match is found or we reach the end of the list 
			prePtr = curPtr;
			curPtr = curPtr->next;
		}
		if(curPtr!=NULL) // if we are not in the end of the list means that we got a match
		{
		 prePtr ->next = curPtr->next;	// Deletion or De-threading the node
		}
	}
	
	
	
return start;
}




int main(){
	srand(time(NULL));
	student *start=NULL, *newnode, *prePtr=NULL, *curPtr=NULL;
	
	start=create_list();
	printf("I am going to print in sorted order... \n");
	display_list(start);
	
	
	//print_to_file(start);
	
	//printf("I am going to print in REVERSE order... \n");
    //print_reverse(start);
	
	char name[100];
	printf("Enter a name to DELETE order... \n");
	gets(name);
	
	start=delete(start, name);
	display_list(start);
	
	return 0;
}