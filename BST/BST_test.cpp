#include<iostream>
using namespace std;
#include "BST.c"

int main()
{
    int A[] = {456,756,6,343,545,6,43,56686,35,5,6786,5,356,5,87,9,6,53};
    int n=sizeof(A)/sizeof(int);
    struct node* root = NULL;
    for(int i=0;i<n;i++) insert_node(&root,A[i]);
    struct node* maxi = maximum(root);
    struct node* second_max = predecessor(maxi);
    cout<<second_max->key<<endl;

    return 0;
}
