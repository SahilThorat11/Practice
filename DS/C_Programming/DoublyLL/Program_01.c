#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
    struct node * prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = (PNODE) malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn -> next = *first;
        (*first) -> prev = newn;
        *first = newn;
    }
}

void InsertLast(PPNODE first, int no)
{}

void DeleteFirst(PPNODE first)
{}

void DeleteLast(PPNODE first)
{}

void Display(PNODE first)
{}

int Count(PNODE first)
{
    return 0;
}

void InsertAtPos(PPNODE first, int no, int iPos)
{}

void DeleteAtPos(PPNODE first, int iPos)
{}

int main()
{
    int iRet = 0;
    PNODE head = NULL;

    return 0;
}