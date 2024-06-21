#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next; // next is a pointer of type struct node.
};

typedef struct node* nodeptr;

void linkedlistTraversal(nodeptr);
nodeptr create_node(int);

int main (void)
{
    // Creating Head node.
    nodeptr head = create_node(4);

    // Traversing the list.
    linkedlistTraversal(head);

    return 0;

}

void linkedlistTraversal(nodeptr ptr)
{
    while(ptr!= NULL)
    {
        printf("Element:%d\n",ptr -> data);
        ptr = ptr -> next;
    }
}

nodeptr create_node(int item)
{
    nodeptr newnode = (nodeptr)malloc(sizeof(struct node));
    newnode -> data = item;
    newnode -> next = NULL;
}