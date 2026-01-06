#include<iostream>
using namespace std;

template <class T>
struct SinglyLLnode
{
    T data;
    struct SinglyLLnode<T> *next;
};

template <class T>
class SinglyLLL
{
    private:
        struct SinglyLLnode<T> * first;
        int iCount;

    public:
        SinglyLLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no , int ipos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);
        void Display();
        int Count();
};

template <class T>
SinglyLLL<T> :: SinglyLLL()
{
    first = NULL;
    iCount = 0;
}

template <class T>
void SinglyLLL<T> :: InsertFirst(T no)
{
    struct SinglyLLnode<T> * newn = NULL;

    newn = new struct SinglyLLnode<T>;
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    iCount++;
}

template <class T>
void SinglyLLL<T> :: InsertLast(T no)
{
    struct SinglyLLnode<T> * newn = NULL;
    struct SinglyLLnode<T> * temp = NULL;

    newn = new struct SinglyLLnode<T>; 
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLLL<T> :: InsertAtPos(T no , int ipos)
{
    int iCnt = 0;
    struct SinglyLLnode<T> * newn = NULL;
    struct SinglyLLnode<T> * temp = NULL;

    if((ipos < 1) || (ipos > iCount+1))
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
        newn = new struct SinglyLLnode<T>;
        newn->data = no;
        newn->next = NULL;

        temp = first;

        for(iCnt =1; iCnt< ipos -1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyLLL<T> :: DeleteFirst()
{
    struct SinglyLLnode<T> * temp = NULL;

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

        first = first -> next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLLL<T> :: DeleteLast()
{
    struct SinglyLLnode<T> * temp = NULL;

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

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLLL<T> :: DeleteAtPos(int ipos)
{
    int iCnt = 0;
    struct SinglyLLnode<T> * temp = NULL;
    struct SinglyLLnode<T> * target = NULL;

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

        for(iCnt = 1; iCnt < ipos -1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp -> next = target->next;
        delete target;

        iCount--;
    }
}

template <class T>
void SinglyLLL<T> :: Display()
{
    struct SinglyLLnode<T> * temp = NULL;

    temp = first;

    cout<<"\n";

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp -> next;
    }

    cout<<"NULL\n";
}

template <class T>
int SinglyLLL<T> :: Count()
{
    return iCount;
}

int main()
{
    SinglyLLL<int> sobj;
    int iRet = 0;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";
    
    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    sobj.InsertAtPos(75,4);

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    sobj.DeleteAtPos(4);

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    sobj.DeleteFirst();

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    sobj.DeleteLast();

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    return 0;
}