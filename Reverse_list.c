#include <stdio.h>
#include <stdlib.h>

struct node {
	char a;
	struct node *next;
};
typedef struct node Node;
typedef Node *NodePtr;
//A -> B -> C -> NULL
//startptr = A


//   NULL<-A<-B




NodePtr reverse_list(NodePtr startPtr){
	
	NodePtr curPtr, prePtr, nextPtr;	
	
	curPtr = startPtr;  // A
	prePtr = NULL;
	
	while(curPtr!=NULL){
		
		nextPtr = curPtr->next;  // B
		curPtr->next = prePtr;   // NULL
		prePtr = curPtr;          // A    
		curPtr = nextPtr;
	}
	startPtr=prePtr;	
	
	return startPtr;
} 









void print_list(NodePtr curPtr){
	while(curPtr!=NULL){
		printf("%c -> ",curPtr->a);
		curPtr=curPtr->next;
	}
}

int main(){
	
	//Create a list here ... First function
	// Print the list
	//we will reverse it
	// we will print it again
	
	//First Step
	NodePtr startPtr = NULL, curPtr, newPtr, revPtr;	
	int i;
	char x='A';

	for(i=0; i<5; i++){
		
		// CODE for one Single node // Memory Allocation
		newPtr = (NodePtr)malloc(sizeof(Node));
		newPtr->a = x; // you can use scanf
		newPtr-> next = NULL;
		
		//My list is still empty
		if(startPtr==NULL){
			startPtr = newPtr;    // Link for my first Node
			curPtr=startPtr;			
		}
		else{
			
			curPtr -> next = newPtr;
			curPtr = newPtr;		
			
		}
	
		x++;  /// You DO NOT need this line if you use Scanf for char input
		
	}
	
	printf("The original order of the linked list \n");
	print_list(startPtr);
	
	printf("\n\n Print in Reverse \n\n");
	startPtr=reverse_list(startPtr); // reverse
	print_list(startPtr);
	
	
}
