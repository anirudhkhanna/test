#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/* Defining methods to handle stack */

Stack * newStack()
{
    Stack *newstack = (Stack *) malloc(sizeof(Stack));

    if (newstack == NULL)
        return NULL;

    newstack -> top = NULL;
    return newstack;
}


void push(Stack *S, void *data)
{
    Node *newnode = (Node *) malloc(sizeof(Node));
    newnode -> data = data;
    newnode -> next = (*S).top;
    (*S).top = newnode;
}


void * pop(Stack *S)
{
    if ((*S).top == NULL)
        return NULL;

    Node *ptr = (*S).top;
    void *data = (*S).top -> data;
    (*S).top = (*S).top -> next;
    
    free(ptr);
    return data;
}


void * peek(Stack *S)
{
    if ((*S).top == NULL)
        return NULL;

    return (*S).top -> data;
}


int isEmpty(Stack *S)
{
    return (*S).top == NULL;
}


int size(Stack *S)
{
    int nodeCount = 0;
    Node *ptr = (*S).top;

    while (ptr != NULL)
    {
        nodeCount++;
        ptr = ptr -> next;
    }

    return nodeCount;
}


void clear(Stack *S)
{
    Node *ptr;
    while ((*S).top != NULL)
    {
        ptr = (*S).top;
        (*S).top = (*S).top -> next;
        free(ptr);
    }
}
