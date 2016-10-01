#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

void stackInit(stackT *stackP, int maxSize)
{
	// allocate space for the contents
	stackdataType *newContents;
	newContents = (stackdataType* )malloc(sizeof(stackdataType)*maxSize);
	
	if(newContents == NULL) {
		printf("Insufficient memory to initialize stack.\n");
		exit(1);
	}
	stackP->content = newContents;
	stackP->maxSize = maxSize;
	stackP->top = -1; // empty stack at initialization
}

void stackDestroy(stackT *stackP)
{
	// get rid of allocated memory
	free(stackP->content);
	
	// reset stack data
	stackP->content = NULL;
	stackP->maxSize = 0;
	stackP->top = -1; // reset for reuse
}

int stackIsFull(stackT *stackP)
{
	return stackP->top >= stackP->maxSize-1;
}

int stackIsEmpty(stackT *stackP)
{
	return stackP->top == -1;
}

void stackPush(stackT *stackP, stackdataType x)
{
	if(stackIsFull(stackP)){
		printf("Can't push, stack is full.\n");
		exit(1);
	}
	stackP->content[++stackP->top] = x;
}

stackdataType stackPop(stackT *stackP)
{
	if(stackIsEmpty(stackP)){
		printf("Stack empty, nothing to pop.\n");
		exit(1);
	}
	return stackP->content[stackP->top--];
}
