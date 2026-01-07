/////////////////////////////////////////////////////////////////////
// Final code of Doubly Circular Linked List using Generic Approach
/////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

#pragma pack(1)

template<class T>
class DoublyCLLnode
{
    public:
        T data;
        DoublyCLLnode<T>* next;
        DoublyCLLnode<T>* prev;

        DoublyCLLnode(T no)
        {
            data = no;
            next = NULL;
            prev = NULL;
        }
};

template<class T>
class DoublyCLL
{
    private:
        DoublyCLLnode<T>* first;
        DoublyCLLnode<T>* last;
        int iCount;

    public:
        DoublyCLL();

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
DoublyCLL<T>::DoublyCLL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

template<class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    DoublyCLLnode<T>* newn = NULL; 
    
    newn = new DoublyCLLnode<T>(no);

    if(first == NULL)
    {
        first = newn;
        last = newn;
        first->prev = last;
        last->next = first;
    }
    else
    {
        newn->next = first;
        newn->prev = last;
        first->prev = newn;
        last->next = newn;
        first = newn;
    }

    iCount++;
}

template<class T>
void DoublyCLL<T>::InsertLast(T no)
{
    DoublyCLLnode<T>* newn = NULL; 
    
    newn = new DoublyCLLnode<T>(no);

    if(first == NULL)
    {
        first = newn;
        last = newn;
        first->prev = last;
        last->next = first;
    }
    else
    {
        last->next = newn;
        newn->prev = last;
        newn->next = first;
        first->prev = newn;
        last = newn;
    }

    iCount++;
}

template<class T>
void DoublyCLL<T>::DeleteFirst()
{
    DoublyCLLnode<T>* temp = NULL;

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
        first->prev = last;
        last->next = first;
    }

    iCount--;
}

template<class T>
void DoublyCLL<T>::DeleteLast()
{
    DoublyCLLnode<T>* temp = NULL;

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
        temp = last;

        last = last->prev;
        delete temp;
        last->next = first;
        first->prev = last;
    }

    iCount--;
}

template<class T>
void DoublyCLL<T>::Display()
{
    DoublyCLLnode<T>* temp = NULL;

    if(first == NULL)
    {
        return;
    }

    temp = first;

    cout << "\n<=> ";

    do
    {
        cout << "| " << temp->data << " | <=> ";
        temp = temp->next;
    } while(temp != first);

    cout << "\n";
}

template<class T>
int DoublyCLL<T>::Count()
{
    return iCount;
}

template<class T>
void DoublyCLL<T>::InsertAtPos(T no, int pos)
{
    DoublyCLLnode<T>* newn = NULL; 
    DoublyCLLnode<T>* temp = NULL;

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
        newn = new DoublyCLLnode<T>(no);
        
        temp = first;

        for(int i = 1; i < pos - 1; i++)
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
void DoublyCLL<T>::DeleteAtPos(int pos)
{
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
        DoublyCLLnode<T>* temp = first;

        for(int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;

        iCount--;
    }
}

int main()
{
    DoublyCLL<int>* obj = new DoublyCLL<int>();
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
