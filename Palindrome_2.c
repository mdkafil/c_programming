#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    char letter; 
    struct stack *next; 
};
typedef struct stack stack;
typedef stack *stackPtr;
char str2[20];
void push_pop(stackPtr startPtr, char *a, int len);

int main()
{
    stackPtr stackPtr = NULL;
    char str1[20];
    int i, len=0;

    printf("Welcome to the Palindrome checker.\n");
    printf("Please enter a word to check:\n");
    gets(str1);
    len = strlen(str1);
    push_pop(stackPtr, str1,  len);
    printf("The word is %s\n", str1);
	printf("The word in reverse order %s\n", str2);
    if (strcmp(str1, str2) == 0)
        printf("This is a Palindrome.\n\n");
    else
        printf("It is not a Palindrome.\n\n");
}
void push_pop(stackPtr startPtr, char *a, int len)
{
    stackPtr newPtr;
    stackPtr tempPtr;
    int i = 0;
    char popvalue;

    while (len > 0)
    {
        newPtr = malloc(sizeof(stack));
        newPtr->letter = *a;
        newPtr->next = startPtr;
        startPtr = newPtr;
        a++;
        len--;
    }

    while (startPtr != NULL)
    {
        tempPtr = startPtr;
        popvalue = startPtr->letter;
        str2[i] = popvalue;
        i++;
        startPtr = startPtr->next;
        free(tempPtr);
    }
	//b[i] = '\0';
}
