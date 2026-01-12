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
   
    if(newn == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
       
    newn -> data = iNo;
    newn -> next = NULL;
    newn -> prev = NULL;

    if((*first == NULL) && (*last == NULL))                 // LL is empty
    {
        *first = newn;
        *last = newn;
    }
    else                                                    // LL contains one or more nodes
    {
        newn -> next = *first;
        (*first) -> prev = newn;
        *first = newn;
    }

    (*last) -> next = *first;
    (*first) -> prev = *last;
}

void InsertLast(PPNODE first, PPNODE last, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));                  // LL is empty

    if(newn == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newn -> data = iNo;
    newn -> next = NULL;
    newn -> prev = NULL;

    if((*first == NULL) && (*last == NULL))
    {
        *first = newn;
        *last = newn;
    }
    else                                                 // LL contains one or more nodes
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
        printf("Linked List is empty\n");
        return;
    }

    printf("\n <=>");

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
        printf("Linked List is empty\n");
        return 0;
    }

    do
    {
        iCount++;
        first = first -> next;
    }while(first != last -> next);

    return iCount;
}

void InsertAtPos(PPNODE first, PPNODE last, int iNo, int iPos)
{
    int iSize = 0;
    int iCnt = 0;

    PNODE newn = NULL;
    PNODE temp = NULL;

    iSize = Count(*first, *last);

    if((iPos < 1) || (iPos > iSize + 1))
    {
        printf("Invalid position\n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(first, last, iNo);
    }
    else if(iPos == iSize + 1)
    {
        InsertLast(first, last, iNo);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        if(newn == NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }

        newn -> data = iNo;
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

void DeleteAtPos(PPNODE first, PPNODE last, int iPos)
{
    int iSize = 0;
    int iCnt = 0;

    PNODE temp = NULL;

    iSize = Count(*first, *last);

    if((iPos < 1) || (iPos > iSize))
    {
        printf("Invalid position\n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(first, last);
    }
    else if(iPos == iSize)
    {
        DeleteLast(first, last);
    }
    else
    {
        temp = *first;

        for(iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp -> next;
        }

        temp -> next = temp -> next -> next;
        free(temp -> next -> prev);
        temp -> next -> prev = temp;
    }
}


int main()
{
    int iRet = 0, iCnt = 0, iSize = 0, iNo = 0, iPos = 0;
    PNODE head = NULL;
    PNODE tail = NULL;

    printf("Enter total number of elements to insert at first position: ");
    scanf("%d", &iSize);

    for(iCnt = 1; iCnt <= iSize; iCnt++)
    {
        printf("Enter element %d : ", iCnt);
        scanf("%d", &iNo);

        InsertFirst(&head, &tail, iNo);
    }

    Display(head, tail);
    iRet = Count(head, tail);
    printf("Number of nodes are : %d\n", iRet);

    printf("Enter total number of elements to insert at Last position: ");
    scanf("%d", &iSize);

    for(iCnt = 1; iCnt <= iSize; iCnt++)
    {
        printf("Enter element %d : ", iCnt);
        scanf("%d", &iNo);

        InsertLast(&head, &tail, iNo);
    }

    Display(head, tail);
    iRet = Count(head, tail);
    printf("Number of nodes are : %d\n", iRet);

    printf("Enter element to insert: ");
    scanf("%d", &iNo);

    printf("Enter position: ");
    scanf("%d", &iPos);

    InsertAtPos(&head, &tail, iNo, iPos);

    Display(head, tail);
    iRet = Count(head, tail);
    printf("Number of nodes are : %d\n", iRet);

    return 0;
}
