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

void InsesrtFirst(PPNODE first, PPNODE last, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = iNo;
    newn -> next = NULL;
    newn -> prev = NULL;

    if((*first == NULL) && (*last == NULL))
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        newn -> next = (*first);
        (*first) -> prev = newn;
        *first = newn;
    }

    (*last) -> next = *first;
    (*first) -> prev = *last;
}

void InsesrtLast(PPNODE first, PPNODE last, int iNo)
{}

void DeleteFirst(PPNODE first, PPNODE last)
{}

void DeleteLast(PPNODE first, PPNODE last)
{}

void Display(PNODE first, PNODE last)
{}

int Count(PNODE first, PNODE last)
{
    return 0;
}

void InsesrtAtPos(PPNODE first, PPNODE last, int iNo, int iPos)
{}

void DeleteAtPos(PPNODE first, PPNODE last)
{}

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;

    return 0;
}