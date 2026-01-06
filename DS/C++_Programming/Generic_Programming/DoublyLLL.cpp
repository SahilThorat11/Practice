#include<iostream>
using namespace std;

template<class T>
struct DoublyLLLnode
{
    T data;
    struct DoublyLLLnode<T> *next;
    struct DoublyLLLnode<T> *prev;
};

template<class T>
class DoublyLLL
{
    private:
        struct DoublyLLLnode<T> * first;
        int iCount;

    public:
        DoublyLLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no , int ipos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);
        void Display();
        int Count();
};

template<class T>
DoublyLLL<T> :: DoublyLLL()
{
    first = NULL;
    iCount = 0;
}

template<class T>
void DoublyLLL<T> :: InsertFirst(T no)
{
    struct DoublyLLLnode<T> * newn = NULL;

    newn = new struct DoublyLLLnode<T>;
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

template<class T>
void DoublyLLL<T> :: InsertLast(T no)
{
    struct DoublyLLLnode<T> * newn = NULL;
    struct DoublyLLLnode<T> * temp = NULL;

    newn = new struct DoublyLLLnode<T>;
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

template<class T>
void DoublyLLL<T> :: InsertAtPos(T no , int ipos)
{
    int iCnt = 0;
    struct DoublyLLLnode<T> * newn = NULL;
    struct DoublyLLLnode<T> * temp = NULL;

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
        newn = new struct DoublyLLLnode<T>;
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

template<class T>
void DoublyLLL<T> :: DeleteFirst()
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

template<class T>
void DoublyLLL<T> :: DeleteLast()
{
    struct DoublyLLLnode<T> * temp = NULL;

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

template<class T>
void DoublyLLL<T> :: DeleteAtPos(int ipos)
{
    int iCnt = 0;
    struct DoublyLLLnode<T> * temp = NULL;

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

template<class T>
void DoublyLLL<T> :: Display()
{
    struct DoublyLLLnode<T> * temp = first;

    cout<<"\n";

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }

    cout<<"NULL\n";
}

template<class T>
int DoublyLLL<T> :: Count()
{
    return iCount;
}

int main()
{
    DoublyLLL<int> dobj;
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
