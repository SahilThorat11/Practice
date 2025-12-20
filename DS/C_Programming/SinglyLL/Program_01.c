#include<stdio.h>
#include<stdlib.h>

struct node
{
    int Data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> Data = no;
    newn -> next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn -> next = (*first);
        (*first) = newn;
    }
}


int main()
{
    PNODE head = NULL;
    int iRet = 0;
    
    InsertFirst(&head, 75);
    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    return 0;
}