#include "BST.h"

(struct node *) new_node(int d) {
    struct node *new = NULL;
    new = (struct node *)malloc(sizeof(struct node));
    new->key = d;
    new->parent = NULL;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void insert_node(struct node** t, int val)
{
    struct node* y=NULL;
    struct node* x = *t;
    struct node* new_node;
    new_node = (struct node*)malloc(sizeof(struct node));

    new_node->left = NULL;
    new_node->right = NULL;

    while(x != NULL)
    {
        y=x;
        if(x->key > val){
            if(x->left==NULL){
                x->left = new_node;
                break;
            }
            else x = x->left;
        }
        else{
            if(x->right==NULL){
                x->right = new_node;
                break;
            }
            else x = x->right;
        }
    }
    new_node->parent = y;
    new_node->key = val;

    if(y==NULL) // tree was empty
        *t=new_node; // added first node
}

void delete_node(struct node* d)
{
    struct node* temp;
    struct node* x=d->parent;
    if(d->left == NULL & d->right == NULL){
        if(x->left == d) x->left = NULL;
        else x->right = NULL;
    }
    else if(d->left != NULL & d->right == NULL){
        if(x->left == d) x->left = d->left;
        else x->right = d->left;
        d->left->parent = x;
    }
    else if(d->left == NULL & d->right != NULL){
        if(x->left == d) x->left = d->right;
        else x->right = d->right;
        d->right->parent = x;
    }
    else{
        temp = successor(d);
        d->key = temp->key;
        delete_node(temp);
    }
}

// Following function returns the successor of the given node p
struct node* successor(struct node* p)
{
    struct node* x;
    struct node* y=NULL;
    if(p->right != NULL)
    {
        x = p->right;
        while(x != NULL){
        y=x;
        x=x->left;
        }
        return y;
    }
    else if(p->parent->left == p) return p->parent;
    else{
        x=p->parent;
        y=p;
        while(x->right == y){
            y=x;
            x = x->parent;
        }
        return x;
    }

}
// Following function returns the predecessor of the given node p
struct node* predecessor(struct node* p)
{
    struct node* x;
    struct node* y;
    if(p->left != NULL)
    {
        x = p->left;
        while(x != NULL){
        y=x;
        x=x->right;
        }
        return y;
    }
    else if (p->parent->right == p) return p->parent;
    else return NULL;
}

// Following function returns the maximum node key of given BST t
struct node* maximum(struct node* t)
{
    struct node* x = t;
    struct node* y;
    if(x == NULL) return NULL; // empty tree
    while(x != NULL){
        y=x;
        x=x->right;
    }
    return y;
}

// Following function returns the minimum node key of given BST t
struct node* minimum(struct node* t)
{
    struct node* x = t;
    struct node* y;
    if(x == NULL) return NULL; // empty tree
    while(x != NULL){
        y=x;
        x=x->left;
    }
    return y;
}
