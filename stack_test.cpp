#include<stdlib.h>
#include<stdio.h>
#include "stack.h"

main()
{
	int maxSize = 20;
	stackT s1; // declaring 1 stack of capacity maxSize
	
	stackInit(&s1,maxSize);
	
	stackPush(&s1, 34);
	stackPush(&s1, 49);
	stackPush(&s1, 456);
	stackPush(&s1, 3244);
	
	printf("%d\n",stackPop(&s1));
	printf("%d\n",stackPop(&s1));
	printf("%d\n",stackPop(&s1));
	printf("%d\n",stackPop(&s1));
	printf("%d\n",stackPop(&s1));
	
	stackDestroy(&s1);
	
	return 0;
}