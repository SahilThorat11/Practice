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
{}

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