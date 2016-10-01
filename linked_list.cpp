#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct node {
    int data;
    struct node *next;
};

void insertNode(struct node **head, int data) {
    struct node *temp = NULL;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    
    if (*head == NULL) {
        *head = temp;
        return;
    }
    temp->next = *head;
    *head = temp;
    return;
}

void print_revlist(struct node *h) {
    if (h == NULL)
        return;
    print_revlist(h->next);
    printf("%d ", h->data);
    return;
}

void printList(struct node *h) {
    while (h != NULL) {
	    cout << h->data << " ";
	    h = h->next;
	}
	cout << endl;
	return;
}

void deleteNode(struct node **h, int data) {
    struct node *prev = NULL;
    struct node *head = *h;
    while (head->data != data) {
	    prev = head;
	    head = head->next;
	}
	if (!prev) { // delete head
	    *h = (*h)->next;
	    free(*h);
	    return;
	}
	// internal node deletion
	prev->next = head->next;
	free(head);
	return;
}

int main() {
	// your code goes here
	struct node *h = NULL;
	insertNode(&h, 10);
	insertNode(&h, 40);
	insertNode(&h, 1);
	insertNode(&h, 20);
	insertNode(&h, 15);
	insertNode(&h, 19);
	insertNode(&h, 30);
	
	printList(h);
	deleteNode(&h, 30);
	print_revlist(h);
	
	return 0;
}
