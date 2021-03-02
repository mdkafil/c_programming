#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// function placeholders
int instructions();
void create();
void display();
void bubble_sort();
int linear_search();
int binary_search();


int main() {
		
	int option, i, search_key, size=10, result, sort=0;
	int array[size];
	
	srand(time(NULL));
	
	//Create initial array and display it
	create(array, size);
	display(array, size);

	do {
	
	// print options and scans user choice
	option = instructions();
	

		switch(option) {
			case 1: // Linear Search
				printf("Linear Search...\n Enter search key: ");
				scanf("%d", &search_key);
				
				// Call linear search function and store the result in variable 
				// Result will be either the array location of searched element, or -1 if not found
				result = linear_search(array, search_key, size);
				
				// Display search result
				if(result == -1)
					printf("Search key not found...\n");
				else 
					printf("Search key found at position 'array[%d]'.\n", result);
				

				
				break;
				
			case 2: // Binary Search
				printf("Binary Search...\n Enter search key: ");
				scanf("%d", &search_key);
				
				// Sort array (only if it has not already been done so)
				if (sort == 0) {
					printf("Sorting array...\n");
					bubble_sort(array, size);
					printf("Complete.\n");
					display(array, size);
					sort++;
				}
				
				// Call binary search function and store the result in variable 
				// Result will be either the array location of searched element, or -1 if not found
				printf("Searching array...\n");
				result = binary_search(array, search_key, 0, size-1);
				
				// Display search result
				if(result == -1)
					printf("Search key not found...\n");
				else 
					printf("Search key found at position 'array[%d]'.\n", result);
				
				break;
				
			case 3: // Exit
				printf("Exiting...\n");

				return 0;
		}
	} while(1);
	
	return 0;
}

	
int instructions(){
	
	int option;
	
	// print instructions
	printf("\n   1 - Linear Search...\n   2 - Binary Search...\n   3 - Exit Program...\nEnter your choice: ");
	
	// user input
	scanf("%d", &option);
	
	// check for errors
	while (option <1 || option > 3) {
		printf("\nOption not recognised, please enter another choice: ");
		scanf("%d", &option);
	}
	printf("\n");
	return option;

}

void create(int x[], int size) {
	
	int i, lower=0, upper=100;  

	srand(time(NULL));
    
	printf("Creating array...\n");
	
	//Create array with random integers between 0 and 100
	for(i=0; i<size; i++)
		x[i] = (rand()%(upper-lower))+lower;

	printf("Complete.\n\n");
}

void display(int x[], int size) {
	
	int i; 
	
	printf("Array:\n");
	
	//Display array values (without comma once it gets to the last element)
	for(i=0; i<size; i++) {
		
		if(i== size-1)
			printf("%d", x[i]);
		else
			printf("%d, ", x[i]);

	}
	printf("\n\n");
}

void bubble_sort(int x[], int size) {
	
	int i, j, temp;
	
	
	//Sort array (required for binary search)
	for (i=0; i< (size-1); ++i) {
		
		for	(j=0; j < size -1 -i; ++j) {
			
			if(x[j] > x[j+1]) {
				temp = x[j+1];
				x[j+1] = x[j];
				x[j] = temp;
			}	
		}
	}
	
}

int linear_search (int x[], int key, int size) {
	
	int i;
	
	// Loop through array until a match is found
	for (i=0; i<size; i++) {
		if (x[i] == key)
			return i;
	}
	// Return -1 if no match is found
	return -1;
}

int binary_search (int x[], int key , int low, int high) {
	
	int	mid;
	
	printf("Initial search: Searching between array elements %d and %d...\n", low, high);
	
	// Keep narrowing the search area until a match is found. Break loop when search is narrowed to one element
	while (low <= high) {
		
		mid = (low + high)/2;
		
		if (key == x[mid])
			return mid;
		
		else if (key < x[mid])
			high = mid-1;
		
		else
			low = mid + 1;
		
		printf("Search narrowed, searching between array elements %d and %d...\n", low, high);
		
	}
	
	return -1;
}
