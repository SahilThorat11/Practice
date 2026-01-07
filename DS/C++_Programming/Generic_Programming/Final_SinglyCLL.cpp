///////////////////////////////////////////////////////////////////
// Final code of Singly Circular Linked List using Generic Approach
///////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

#pragma pack(1)

template<class T>
class SinglyCLLnode
{
    public:
        T data;
        SinglyCLLnode<T>* next;

        SinglyCLLnode(T no)
        {
            data = no;
            next = NULL;
        }
};

template<class T>
class SinglyCLL
{
    private:
        SinglyCLLnode<T>* first;
        SinglyCLLnode<T>* last;
        int iCount;

    public:
        SinglyCLL();

        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T, int);
        void DeleteAtPos(int);
};

template<class T>
SinglyCLL<T>::SinglyCLL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

template<class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    SinglyCLLnode<T>* newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if(first == NULL)
    {
        first = newn;
        last = newn;
        last->next = first;
    }
    else
    {
        newn->next = first;
        first = newn;
        last->next = first;
    }

    iCount++;
}

template<class T>
void SinglyCLL<T>::InsertLast(T no)
{
    SinglyCLLnode<T>* newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if(first == NULL)
    {
        first = newn;
        last = newn;
        last->next = first;
    }
    else
    {
        last->next = newn;
        last = newn;
        last->next = first;
    }

    iCount++;
}

template<class T>
void SinglyCLL<T>::DeleteFirst()
{
    SinglyCLLnode<T>* temp = NULL;

    if(first == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        temp = first;

        first = first->next;
        delete temp;
        last->next = first;
    }

    iCount--;
}

template<class T>
void SinglyCLL<T>::DeleteLast()
{
    SinglyCLLnode<T>* temp = NULL;

    if(first == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        temp = first;

        while(temp->next != last)
        {
            temp = temp->next;
        }

        delete last;
        last = temp;
        last->next = first;
    }

    iCount--;
}

template<class T>
void SinglyCLL<T>::Display()
{
    SinglyCLLnode<T>* temp = NULL;

    if(first == NULL)
    {
        return;
    }

    temp = first;


    cout << "\n";

    do
    {
        cout << "| " << temp->data << " | -> ";
        temp = temp->next;
    } while(temp != first);

    cout << "\n";
}

template<class T>
int SinglyCLL<T>::Count()
{
    return iCount;
}

template<class T>
void SinglyCLL<T>::InsertAtPos(T no, int pos)
{
    SinglyCLLnode<T>* newn = NULL;
    SinglyCLLnode<T>* temp = NULL;

    if(pos < 1 || pos > iCount + 1)
    {
        cout << "Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new SinglyCLLnode<T>(no);

        temp = first;

        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template<class T>
void SinglyCLL<T>::DeleteAtPos(int pos)
{
    SinglyCLLnode<T>* temp = NULL;
    SinglyCLLnode<T>* target = NULL;

    if(pos < 1 || pos > iCount)
    {
        cout << "Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        delete target;

        iCount--;
    }
}

int main()
{
    SinglyCLL<int>* obj = new SinglyCLL<int>();
    int iRet = 0;

    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();
    iRet = obj->Count();
    cout << "Number of nodes are : " << iRet << "\n";

    obj->InsertLast(101);
    obj->InsertLast(111);
    obj->InsertLast(121);

    obj->Display();
    iRet = obj->Count();
    cout << "Number of nodes are : " << iRet << "\n";

    obj->InsertAtPos(75, 4);

    obj->Display();
    iRet = obj->Count();
    cout << "Number of nodes are : " << iRet << "\n";

    obj->DeleteAtPos(4);

    obj->Display();
    iRet = obj->Count();
    cout << "Number of nodes are : " << iRet << "\n";

    obj->DeleteFirst();

    obj->Display();
    iRet = obj->Count();
    cout << "Number of nodes are : " << iRet << "\n";

    obj->DeleteLast();

    obj->Display();
    iRet = obj->Count();
    cout << "Number of nodes are : " << iRet << "\n";

    delete obj;
    return 0;
}
