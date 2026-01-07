/////////////////////////////////////////////////////////////////////////////////////////////////
//                              Generalised Data Structure Library             
/////////////////////////////////////////////////////////////////////////////////////////////////

/*
--------------------------------------------------------------------------------------------------
   Type                  Name of class for node              Name of class for Functionality
--------------------------------------------------------------------------------------------------
Singly Linear               SinglyLLLnode                          SinglyLLL            Done
Singly Circular             SinglyCLLnode                          SinglyCLL            Done
Doubly Linear               DoublyLLLnode                          DoublyLLL            Done
Doubly Circular             DoublyCLLnode                          DoublyCLL            Done
--------------------------------------------------------------------------------------------------
*/

#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////
//              Singly Linear Linked List using Generic Approch
////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class SinglyLLLnode
{
    public:
        T data;
        SinglyLLLnode<T> * next;

        SinglyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class SinglyLLL
{
    private :                     
        SinglyLLLnode<T> * first;
        int iCount;

    public :
        SinglyLLL();
        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T, int);
        void DeleteAtPos(int);
};

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     SinglyLLL (Constructor)
//  Input         :     None
//  Output        :     None
//  Description   :     Initializes empty singly linear linked list
//  Author        :     Sahil Rajaram Thorat
//  Date          :     06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
SinglyLLL<T> :: SinglyLLL()
{
    this -> first = NULL;
    this -> iCount = 0;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input         :     Data of node
//  Output        :     None
//  Description   :     Inserts new node at first position of linked list
//  Author        :     Sahil Rajaram Thorat
//  Date          :     06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertFirst(T no) 
{
    SinglyLLLnode<T> * newn = NULL;

    newn = new SinglyLLLnode<T>(no);

    newn -> next = this -> first;
    this -> first = newn;

    this -> iCount++;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Input         :     Data of node
//  Output        :     None
//  Description   :     Inserts new node at last position of linked list
//  Author        :     Sahil Rajaram Thorat
//  Date          :     06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertLast(T no)
{
    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;

    newn = new SinglyLLLnode<T>(no);

    if(this -> iCount == 0)              
    {
        this -> first = newn;
    }
    else
    {
        temp = this -> first;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newn;
    }

    this -> iCount++;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Input         :     None
//  Output        :     None
//  Description   :     Deletes first node from linked list
//  Author        :     Sahil Rajaram Thorat
//  Date          :     06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: DeleteFirst()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this -> first == NULL)
    {
        return;
    }
    else if(this -> first -> next == NULL)        
    {
        delete this -> first;
        this -> first = NULL;
    }
    else
    {
        temp = this -> first;

        this -> first = this -> first -> next;
        delete temp;
    }

    this -> iCount--;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Input         :     None
//  Output        :     None
//  Description   :     Deletes last node from linked list
//  Author        :     Sahil Rajaram Thorat
//  Date          :     06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: DeleteLast()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this -> first == NULL)
    {
        return;
    }
    else if(this -> first -> next == NULL)       
    {
        delete this -> first;
        this -> first = NULL;
    }
    else
    {
        temp = this -> first;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }

        delete temp -> next;
        temp -> next = NULL;
    }

    this -> iCount--;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input         :     None
//  Output        :     Displays linked list elements
//  Description   :     Prints all elements of linked list
//  Author        :     Sahil Rajaram Thorat
//  Date          :     06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: Display()                 
{
    SinglyLLLnode<T> * temp = NULL;
    int iCnt = 0;

    temp = this -> first;

    cout << "\n";

    for(iCnt = 1; iCnt <= this -> iCount; iCnt++)
    {
        cout << "| " << temp->data << " | -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input         :     None
//  Output        :     Integer (number of nodes)
//  Description   :     Returns total number of nodes in linked list
//  Author        :     Sahil Rajaram Thorat
//  Date          :     06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyLLL<T> :: Count()
{
    return this -> iCount;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input         :     Data of node, Position
//  Output        :     None
//  Description   :     Inserts node at specified position
//  Author        :     Sahil Rajaram Thorat
//  Date          :     06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertAtPos(T no, int Pos)
{
    int iCnt = 0;
    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;

    if (Pos < 1 || Pos > this -> iCount + 1)
    {
        cout << "Invalid position\n";
        return;
    }

    if(Pos == 1)
    {
        this -> InsertFirst(no);
    }
    else if(Pos == this -> iCount + 1)
    {
        this -> InsertLast(no);
    }
    else
    {
        newn = new SinglyLLLnode<T>(no);

        temp = this -> first;

        for(iCnt = 1; iCnt < Pos - 1; iCnt++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next = newn;

        this -> iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Input         :     Position
//  Output        :     None
//  Description   :     Deletes node from specified position
//  Author        :     Sahil Rajaram Thorat
//  Date          :     06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: DeleteAtPos(int Pos)
{
    int iCnt = 0;
    SinglyLLLnode<T> * target = NULL;
    SinglyLLLnode<T> * temp = NULL;

    if (Pos < 1 || Pos > this -> iCount)
    {
        cout << "Invalid position\n";
        return;
    }

    if(Pos == 1)
    {
        this -> DeleteFirst();
    }
    else if(Pos == this -> iCount)
    {
        this -> DeleteLast();
    }
    else
    {
        temp = this -> first;

        for(iCnt = 1; iCnt < Pos - 1; iCnt++)
        {
            temp = temp -> next;
        }

        target = temp -> next;
        temp -> next = target -> next;
        delete target;

        this -> iCount--;
    }
}


////////////////////////////////////////////////////////////////////////////
//              Doubly Linear Linked List using Generic Approch
////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class DoublyLLLnode
{
    public:
        T data;
        DoublyLLLnode<T> * next;
        DoublyLLLnode<T> * prev;

        DoublyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template <class T>
class DoublyLLL
{
    private:
        DoublyLLLnode<T> * first;
        int iCount;

    public:
        DoublyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DoublyLLL       
//  Input         :     None
//  Output        :     None
//  Description   :     Constructor to initialise Doubly Linear Linked List
//  Author        :     Sahil Rajaram Thorat
//  Date          :     06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
DoublyLLL<T> :: DoublyLLL()
{
    cout<<"Linked List gets created\n";

    this->first = NULL;
    this->iCount = 0;
}
 
////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst       
//  Input         :     Data of node
//  Output        :     Nothing
//  Description   :     Inserts node at beginning of doubly linked list
//  Author        :     Sahil Rajaram Thorat
//  Date          :     06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: InsertFirst(T no)
{
    DoublyLLLnode<T> * newn = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn -> next = this->first;
        this->first -> prev = newn;
        this->first = newn;
    }

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast       
//  Input         :     Data of node
//  Output        :     Nothing
//  Description   :     Inserts node at end of doubly linked list
//  Author        :     Sahil Rajaram Thorat
//  Date          :     06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: InsertLast(T no)
{
    DoublyLLLnode<T> * newn = NULL;
    DoublyLLLnode<T> * temp = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newn;
        newn -> prev = temp;
    }

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos       
//  Input         :     Data of node, Position
//  Output        :     Nothing
//  Description   :     Inserts node at given position in doubly linked list
//  Author        :     Sahil Rajaram Thorat
//  Date          :     06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: InsertAtPos(T no, int pos)
{
    DoublyLLLnode<T> * newn = NULL;
    DoublyLLLnode<T> * temp = NULL;
    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount + 1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount + 1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyLLLnode<T>(no);
        temp = this -> first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next -> prev = newn;
        temp -> next = newn;
        newn -> prev = temp;

        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst       
//  Input         :     None
//  Output        :     Nothing
//  Description   :     Deletes first node of doubly linked list
//  Author        :     Sahil Rajaram Thorat
//  Date          :     06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: DeleteFirst()
{
    if(this->first == NULL)                // LL is Empty
    {
        return;
    }
    else if(this->first -> next == NULL)  // LL contians one DoublyLLLnode
    {
        delete this->first;
        this->first = NULL;
    }
    else                                  // LL contians more than one DoublyLLLnode  
    {
        this->first = this->first -> next;
        delete this->first -> prev;
        this->first -> prev = NULL;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast       
//  Input         :     None
//  Output        :     Nothing
//  Description   :     Deletes last node of doubly linked list
//  Author        :     Sahil Rajaram Thorat
//  Date          :     06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: DeleteLast()
{
    DoublyLLLnode<T> * temp = NULL;

    if(this->first == NULL)                // LL is Empty
    {
        return;
    }
    else if(this->first -> next == NULL)  // LL contians one DoublyLLLnode
    {
        delete this->first;
        this->first = NULL;
    }
    else                                  // LL contians more than one DoublyLLLnode  
    {
        temp = this->first;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }

        delete temp -> next;
        temp -> next = NULL;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos       
//  Input         :     Position
//  Output        :     Nothing
//  Description   :     Deletes node from given position in doubly linked list
//  Author        :     Sahil Rajaram Thorat
//  Date          :     06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: DeleteAtPos(int pos)
{
    DoublyLLLnode<T> * temp = NULL;
    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this -> first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp -> next;
        }

        temp -> next = temp -> next -> next;
        delete temp -> next -> prev;
        temp -> next -> prev = temp;

        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display       
//  Input         :     None
//  Output        :     Displays linked list
//  Description   :     Used to display all elements of linked list
//  Author        :     Sahil Rajaram Thorat
//  Date          :     06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: Display()
{
    DoublyLLLnode<T> * temp = NULL;

    temp = this->first;

    cout<<"\nNULL<=>";

    while(temp != NULL)
    {
        cout<<"| "<<temp -> data<<" | <=> ";
        temp = temp -> next;
    }

    cout<<"NULL\n";
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count       
//  Input         :     None
//  Output        :     Integer
//  Description   :     Returns number of nodes present in linked list
//  Author        :     Sahil Rajaram Thorat
//  Date          :     06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyLLL<T> :: Count()
{
    return this->iCount;
}


///////////////////////////////////////////////////////////////////
// Final code of Singly Circular Linked List using Generic Approach
///////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     SinglyCLL       
//  Input         :     None
//  Output        :     None
//  Description   :     Constructor to initialise Singly Circular Linked List
//  Author        :     Sahil Rajaram Thorat
//  Date          :     07/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
SinglyCLL<T>::SinglyCLL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst       
//  Input         :     Data of node
//  Output        :     Nothing
//  Description   :     Inserts node at beginning of circular linked list
//  Author        :     Sahil Rajaram Thorat
//  Date          :     07/01/2026
//
////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast       
//  Input         :     Data of node
//  Output        :     Nothing
//  Description   :     Inserts node at end of circular linked list
//  Author        :     Sahil Rajaram Thorat
//  Date          :     07/01/2026
//
////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst       
//  Input         :     None
//  Output        :     Nothing
//  Description   :     Deletes first node of circular linked list
//  Author        :     Sahil Rajaram Thorat
//  Date          :     07/01/2026
//
////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast       
//  Input         :     None
//  Output        :     Nothing
//  Description   :     Deletes last node of circular linked list
//  Author        :     Sahil Rajaram Thorat
//  Date          :     07/01/2026
//
////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display       
//  Input         :     None
//  Output        :     Displays linked list
//  Description   :     Used to display all elements of linked list
//  Author        :     Sahil Rajaram Thorat
//  Date          :     07/01/2026
//
////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count       
//  Input         :     None
//  Output        :     Integer
//  Description   :     Returns number of nodes present in linked list
//  Author        :     Sahil Rajaram Thorat
//  Date          :     07/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyCLL<T>::Count()
{
    return iCount;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos       
//  Input         :     Data of node, Position
//  Output        :     Nothing
//  Description   :     Inserts node at given position in circular linked list
//  Author        :     Sahil Rajaram Thorat
//  Date          :     07/01/2026
//
////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos       
//  Input         :     Position
//  Output        :     Nothing
//  Description   :     Deletes node from given position in circular linked list
//  Author        :     Sahil Rajaram Thorat
//  Date          :     07/01/2026
//
////////////////////////////////////////////////////////////////////////////

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


/////////////////////////////////////////////////////////////////////
// Final code of Doubly Circular Linked List using Generic Approach
/////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DoublyCLL       
//  Input         :     None
//  Output        :     None
//  Description   :     Constructor to initialise Doubly Circular Linked List
//  Author        :     Sahil Rajaram Thorat
//  Date          :     07/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
DoublyCLL<T>::DoublyCLL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst       
//  Input         :     Data of node
//  Output        :     Nothing
//  Description   :     Inserts node at beginning of doubly circular linked list
//  Author        :     Sahil Rajaram Thorat
//  Date          :     07/01/2026
//
////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast       
//  Input         :     Data of node
//  Output        :     Nothing
//  Description   :     Inserts node at end of doubly circular linked list
//  Author        :     Sahil Rajaram Thorat
//  Date          :     07/01/2026
//
////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst       
//  Input         :     None
//  Output        :     Nothing
//  Description   :     Deletes first node of doubly circular linked list
//  Author        :     Sahil Rajaram Thorat
//  Date          :     07/01/2026
//
////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast       
//  Input         :     None
//  Output        :     Nothing
//  Description   :     Deletes last node of doubly circular linked list
//  Author        :     Sahil Rajaram Thorat
//  Date          :     07/01/2026
//
////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display       
//  Input         :     None
//  Output        :     Displays linked list
//  Description   :     Used to display all elements of linked list
//  Author        :     Sahil Rajaram Thorat
//  Date          :     07/01/2026
//
////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display       
//  Input         :     None
//  Output        :     Displays linked list
//  Description   :     Used to display all elements of linked list
//  Author        :     Sahil Rajaram Thorat
//  Date          :     07/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyCLL<T>::Count()
{
    return iCount;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos       
//  Input         :     Data of node, Position
//  Output        :     Nothing
//  Description   :     Inserts node at given position in doubly circular linked list
//  Author        :     Sahil Rajaram Thorat
//  Date          :     07/01/2026
//
////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos       
//  Input         :     Position
//  Output        :     Nothing
//  Description   :     Deletes node from given position in doubly circular linked list
//  Author        :     Sahil Rajaram Thorat
//  Date          :     07/01/2026
//
////////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////// End of Library /////////////////////////////////////////////////

int main()
{
    SinglyLLL<int> * obj = new SinglyLLL<int>();
    int iRet = 0;

    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj->InsertLast(101);
    obj->InsertLast(111);
    obj->InsertLast(121);

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj->InsertAtPos(75, 4);

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj->DeleteAtPos(4);

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";


    obj->DeleteFirst();

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj->DeleteLast();

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    delete obj;

    DoublyLLL<char> *dobj = new DoublyLLL<char>();

    dobj->InsertFirst('A');
    dobj->InsertFirst('B');
    dobj->InsertFirst('C');

    dobj->Display();

    cout<<"Number of elements of linked list are : "<<dobj->Count()<<"\n";

    dobj->InsertLast('X');
    dobj->InsertLast('Y');
    dobj->InsertLast('Z');

    dobj->Display();

    cout<<"Number of elements of linked list are : "<<dobj->Count()<<"\n";

    dobj->InsertAtPos('$', 4);

    dobj->Display();

    cout<<"Number of elements of linked list are : "<<dobj->Count()<<"\n";

    dobj->DeleteAtPos(4);

    dobj->Display();

    cout<<"Number of elements of linked list are : "<<dobj->Count()<<"\n";

    dobj->DeleteFirst();

    dobj->Display();

    cout<<"Number of elements of linked list are : "<<dobj->Count()<<"\n";

    dobj->DeleteLast();

    dobj->Display();

    cout<<"Number of elements of linked list are : "<<dobj->Count()<<"\n";

    delete dobj;

    return 0;
}