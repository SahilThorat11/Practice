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

void InsertFirst(PPNODE first, PPNODE last, int iNo)
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

void InsertLast(PPNODE first, PPNODE last, int iNo)
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
        (*last) -> next = newn;
        newn -> prev = *last;
        *last = newn;
    }

    (*last) -> next = *first;
    (*first) -> prev = *last;
}

void DeleteFirst(PPNODE first, PPNODE last)
{
    if((*first == NULL) && (*last == NULL))   // LL is empty
    {
        return;
    }
    else if(*first == *last)                  // LL contains one node
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else                                      // LL contains one or more nodes
    {
        *first = (*first) -> next;
        free((*first) -> prev);

        (*last) -> next = *first;
        (*first) -> prev = *last;
    }
}

void DeleteLast(PPNODE first, PPNODE last)
{
    if((*first == NULL) && (*last == NULL))   // LL is empty
    {
        return;
    }
    else if(*first == *last)                  // LL contains one node
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else                                      // LL contains one or more nodes
    {
        *last = (*last) -> prev;
        free((*last) -> next);

        (*last) -> next = *first;
        (*first) -> prev = *last;
    }
}

void Display(PNODE first, PNODE last)
{
    if((first == NULL) && (last == NULL))
    {
        printf("Linked List is empty");
        return;
    }

    printf("\n <=> ");

    do 
    {
        printf("| %d | <=> ", first -> data);
        first = first -> next;
    }while(first != last -> next);

    printf("\n\n");
}

int Count(PNODE first, PNODE last)
{
    int iCount = 0;

    if((first == NULL) && (last == NULL))
    {
        printf("Linked List is empty");
        return 0;
    }

    do 
    {
        iCount++;
        first = first -> next;
    }while(first != last -> next);

    return iCount;
}

void InsesrtAtPos(PPNODE first, PPNODE last, int iNo, int iPos)
{}

void DeleteAtPos(PPNODE first, PPNODE last)
{}

int main()
{
    int iRet = 0;
    PNODE head = NULL;
    PNODE tail = NULL;

    InsertFirst(&head, &tail, 51);
    InsertFirst(&head, &tail, 21);
    InsertFirst(&head, &tail, 11);

    Display(head, tail);
    iRet = Count(head, tail);
    printf("Number of nodes are : %d\n", iRet);

    InsertLast(&head, &tail, 101);
    InsertLast(&head, &tail, 111);
    InsertLast(&head, &tail, 121);

    Display(head, tail);
    iRet = Count(head, tail);
    printf("Number of nodes are : %d\n", iRet);

    DeleteFirst(&head, &tail);

    Display(head, tail);
    iRet = Count(head, tail);
    printf("Number of nodes are : %d\n", iRet);

    DeleteLast(&head, &tail);

    Display(head, tail);
    iRet = Count(head, tail);
    printf("Number of nodes are : %d\n", iRet);

    return 0;
}