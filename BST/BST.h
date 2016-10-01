// very good illustration of how to design and provide libraries is available at
// http://www.cs.swarthmore.edu/~newhall/unixhelp/howto_C_libraries.html
// and at
// https://www.cs.bu.edu/teaching/c/stack/array/

#include<stdlib.h>
#include<stdio.h>

struct node{
    int key;
    struct node* parent;
    struct node* left;
    struct node* right;
};

// functions prototypes
// Following function inserts the given val as new node in existing BST t
void insert_node(struct node** t, int val);
// Following function deletes the given node d from existing BST
void delete_node(struct node* d);
// Following function returns the successor of the given node x
struct node* successor(struct node* x);
// Following function returns the predecessor of the given node x
struct node* predecessor(struct node* x);
// Following function returns the maximum node key of given BST t
struct node* maximum(struct node* t);
// Following function returns the minimum node key of given BST t
struct node* minimum(struct node* t);
