#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
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

void InsertLast(PPNODE first, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;

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
        free(temp);
    }
}

void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;

    if (*first == NULL)
    {
        return;
    }
    else if ((*first) -> next == NULL)
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
        temp->next = NULL;
    }
}

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d |->", first -> data);
        first = first -> next;
    }

    printf("NULL\n");
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
    int CountNode = 0, iCnt = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;

    CountNode = Count(*first);

    if ((iPos < 1) || (iPos > CountNode + 1)) // Filter
    {
        printf("Invalid position\n");
        return;
    }

    if (iPos == 1) // Pos == 1
    {
        InsertFirst(first, no);
    }

    else if (iPos == CountNode + 1) // Pos == Last
    {
        InsertLast(first, no);
    }

    else // In between position
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;

        temp = *first;

        for (iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
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

    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n", iRet);

    InsertLast(&head, 101);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n", iRet);

    DeleteFirst(&head);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n", iRet);

    DeleteLast(&head);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n", iRet);

    InsertAtPos(&head, 11, 1);
    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n", iRet);

    InsertAtPos(&head, 101, 5);
    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n", iRet);

    return 0;
}