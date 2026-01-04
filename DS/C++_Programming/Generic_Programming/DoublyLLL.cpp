#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

class DoublyLLL
{
    public:
        struct node * first;
        int iCount;

        DoublyLLL();
        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no , int ipos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);
        void Display();
        int Count();
};

DoublyLLL::DoublyLLL()
{
    first = NULL;
    iCount = 0;
}

void DoublyLLL::InsertFirst(int no)
{
    struct node * newn = NULL;

    newn = new node;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    iCount++;
}

void DoublyLLL::InsertLast(int no)
{
    struct node * newn = NULL;
    struct node * temp = NULL;

    newn = new node;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

void DoublyLLL::InsertAtPos(int no , int ipos)
{
    int iCnt = 0;
    struct node * newn = NULL;
    struct node * temp = NULL;

    if((ipos < 1) || (ipos > iCount + 1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new node;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = first;

        for(iCnt = 1; iCnt < ipos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;

        iCount++;
    }
}

void DoublyLLL::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        first = first->next;
        delete first->prev;
        first->prev = NULL;
    }
    iCount--;
}

void DoublyLLL::DeleteLast()
{
    struct node * temp = NULL;

    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->prev->next = NULL;
        delete temp;
    }
    iCount--;
}

void DoublyLLL::DeleteAtPos(int ipos)
{
    int iCnt = 0;
    struct node * temp = NULL;

    if((ipos < 1) || (ipos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(iCnt = 1; iCnt < ipos; iCnt++)
        {
            temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;

        iCount--;
    }
}

void DoublyLLL::Display()
{
    struct node * temp = first;

    cout<<"\n";

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }

    cout<<"NULL\n";
}

int DoublyLLL::Count()
{
    return iCount;
}

int main()
{
    DoublyLLL dobj;
    int iRet = 0;

    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);

    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    dobj.InsertLast(101);
    dobj.InsertLast(111);
    dobj.InsertLast(121);

    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    dobj.InsertAtPos(75,4);

    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    dobj.DeleteAtPos(4);

    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    dobj.DeleteFirst();

    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    dobj.DeleteLast();

    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    return 0;
}
