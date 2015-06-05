// very good illustration of how to design and provide libraries is available at
// http://www.cs.swarthmore.edu/~newhall/unixhelp/howto_C_libraries.html
// http://www.umich.edu/~eecs381/handouts/CHeaderFileGuidelines.pdf
// and at
// https://www.cs.bu.edu/teaching/c/stack/array/

typedef int stackdataType; //stack containing integers

typedef struct{
	stackdataType *content;
	int top;
	int maxSize;
} stackT;

// functions prototypes
// This function initializes the stack with definte size of memory allocation
void stackInit(stackT *stackP, int maxSize);
// This function destroys stack after the use, freeing all the momory allocated
void stackDestroy(stackT *stackP);
// Checks if stack is full. Returns 1 if positive else 0
int stackIsFull(stackT *stackP);
// Checks if stack is empty. Returns 1 if positive else 0
int stackIsEmpty(stackT *stackP);
// Pushes new element of stackdataType on the stack
void stackPush(stackT *stackP, stackdataType x);
// pops the topmost element of stackdataType from stack
stackdataType stackPop(stackT *stackP);
