// Quick Sort 
#include<stdio.h>
#include<string.h>

struct student { 
	char name[10]; // String
	int rank;      // Integer values
};

typedef struct student STUDENT;

void display(STUDENT array[], int count);
int partition(STUDENT array[], int start, int end); // .....
void Quicksort (STUDENT array[], int start, int end);
void swap(int* a, int* b, char c[], char d[]);


void main(){
	
	STUDENT array[] = {
		{"Tim", 5},
		{"John", 3},
		{"Bob", 8},
		{"Terry",7},
		{"Chad",2}		
	};
	
 printf("\n*****Unsorted List of Array****\n");
 display(array, 5); // display the array
 Quicksort(array,0, 5); // SORT the array
 
 printf("\n\n\n+++Sorted List of Array+++\n");
 display(array, 5); // display the array	
	
}

void Quicksort (STUDENT array[], int start, int end)
{
	if (start<end){ 
	int pIndex=partition(array, start, end); 
	Quicksort(array, start, pIndex-1); 
	Quicksort(array, pIndex+1, end);
 }
}

int partition(STUDENT array[], int start, int end){ 
	int pivot = array[end].rank; 
	int pIndex=start; 
	for(int i=start; i < end; i++){ 
	if(array[i].rank <= pivot){
		swap(&array[i].rank,&array[pIndex].rank, array[i].name, array[pIndex].name); 
		pIndex++;
	} 
   }
	swap(&array[pIndex].rank, &array[end].rank, array[pIndex].name, array[end].name); 
	return pIndex;
}

void swap(int* a, int* b, char c[], char d[]){ 
int tempRank; 
char tempName[10]; 
	tempRank = *a; 
	*a = *b;
	*b = tempRank; 
	strcpy(tempName, c);
	strcpy(c, d);
	strcpy(d, tempName); 
 }

void display(STUDENT array[], int count){
	int i;
	for(i=0;i<count;i++){
		printf("|%s %d",array[i].name, array[i].rank);
	}	
}


