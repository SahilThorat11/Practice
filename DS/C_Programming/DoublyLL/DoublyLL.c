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

    newn = (PNODE)malloc(sizeof(NODE));

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
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newn;
        newn -> prev = temp;
    }
}

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first) -> next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        *first = (*first) -> next;
        (*first) -> prev = NULL;
        free(temp);
    }
}

void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first) -> next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        
        free(temp -> next);
        temp -> next = NULL;
    }
}

void Display(PNODE first)
{
    printf("NULL <=> ");

    while(first != NULL)
    {
        printf("| %d | <=> ", first -> data);
        first = first -> next;
    }

    printf("NULL\n\n");
}

int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first -> next;
    }
    return iCount;
}

void InsertAtPos(PPNODE first, int no, int iPos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    int iCnt = 0;
    int iSize = 0;

    iSize = Count(*first);

    if((iPos < 1) || (iPos > iSize + 1))
    {
        printf("Invalid Position\n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(first, no);
    }
    else if(iPos == iSize + 1)
    {
        InsertLast(first, no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn -> data = no;
        newn -> next = NULL;
        newn -> prev = NULL;

        temp = *first;

        for(iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next -> prev = newn;
        temp -> next = newn;
        newn -> prev = temp;
    }
}

void DeleteAtPos(PPNODE first, int iPos)     // Function With target pointer
{
    PNODE target = NULL;
    PNODE temp = NULL;

    int iCnt = 0;
    int iSize = 0;

    iSize = Count(*first);

    if((iPos < 1) || (iPos > iSize))
    {
        printf("Invalid Position\n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(first);
    }
    else if(iPos == iSize)
    {
        DeleteLast(first);
    }
    else
    {
        temp = *first;

        for(iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp -> next;
        }

        target = temp -> next;

        temp -> next = target -> next;
        target -> next -> prev = temp;
        free(target);
    }
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");

    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n\n", iRet);

    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");

    InsertLast(&head, 101);
    InsertLast(&head, 111);
    InsertLast(&head, 121);

    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");

    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n\n", iRet);

    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");

    InsertAtPos(&head, 75, 4);

    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");

    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n\n", iRet);

    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");

    DeleteAtPos(&head, 4);

    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");

    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n\n", iRet);

    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");

    DeleteFirst(&head);

    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");

    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n\n", iRet);

    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");

    DeleteLast(&head);

    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");

    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n\n", iRet);

    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");

    return 0;
}