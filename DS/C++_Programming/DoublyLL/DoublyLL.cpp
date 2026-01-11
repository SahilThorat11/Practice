#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node * next;
    struct node * prev;
};

typedef struct node NODE;
typedef struct node * PNODE;

class DoublyLL
{
    private:
        PNODE first;
        int iCount;

    public:

        DoublyLL()
        {
            first = NULL;
            iCount = 0;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn -> data = no;
            newn -> next = NULL;
            newn -> prev = NULL;

            if(first == NULL)
            {
                first = newn;
            }
            else
            {
                newn -> next = first;
                first = newn;
            }

            iCount++;
        }

        void InsertLast(int no)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;

            newn = new NODE;

            newn -> data = no;
            newn -> next = NULL;
            newn -> prev = NULL;

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

                temp -> next = newn;
                newn -> prev = temp;
            }

            iCount++;
        }

        void InsertAtPos(int no, int iPos)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;
            int iCnt = 0;

            if((iPos < 1) || (iPos > iCount + 1))
            {
                cout<<"Invalid Position\n";
                return;
            }

            if(iPos == 1)
            {
                InsertFirst(no);
            }
            else if(iPos == iCount + 1)
            {
                InsertLast(no);
            }
            else
            {
                newn = new NODE;

                newn -> data = no;
                newn -> next = NULL;
                newn -> prev = NULL;

                temp = first;

                for(iCnt = 1; iCnt < iPos - 1; iCnt++)
                {
                    temp = temp -> next;
                }

                newn -> next = temp -> next;
                temp -> next -> prev = newn;
                temp -> next = newn;
                newn -> prev = temp;

                iCount++;
            }
        }

        void DeleteFirst()
        {
            if(first == NULL)
            {
                return;
            }
            else if(first -> next == NULL)
            {
                delete first;
                first = NULL;
            }
            else
            {
                first = first -> next;
                delete first -> next -> prev;
                first -> prev = NULL; 
            }

            iCount--;
        }

        void DeleteLast()
        {
            PNODE temp = NULL;

            if(first == NULL)
            {
                return;
            }
            else if(first -> next == NULL)
            {
                delete first;
                first = NULL;
            }
            else
            {
                temp = first;

                while(temp -> next -> next != NULL)
                {
                    temp = temp -> next;
                }

                delete temp -> next;
                temp -> next = NULL;
            }

            iCount--;
        }

        void DeleteAtPos(int iPos)
        {
            PNODE temp = NULL;
            int iCnt = 0;

            if((iPos < 1) || (iPos > iCount))
            {
                cout<<"Invalid position";
                return;
            }

            if(iPos == 1)
            {
                DeleteFirst();
            }
            else if(iPos == iCount)
            {
                DeleteLast();
            }
            else
            {
                temp = first;

                for(iCnt = 1; iCnt < iPos - 1; iCnt++)
                {
                    temp = temp -> next;
                }

                temp -> next = temp -> next -> next;
                delete temp -> next -> prev;
                temp -> next -> prev = temp;

                iCount --;
            }
        }

        void Display()
        {
            PNODE temp = NULL;

            if(first == NULL)
            {
                cout<<"LinkedList is empty\n";
                return;
            }

            temp = first;

            cout<<"\nNULL <=> ";

            while(temp != NULL)
            {
                cout<<"| "<<temp -> data<<" | <=> ";
                temp = temp -> next;
            }

            cout<<"NULL\n";
        }

        int Count()
        {
            return iCount;
        }
};

int main()
{
    DoublyLL dobj;
    int iRet = 0;

    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);

    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    dobj.InsertLast(101);
    dobj.InsertLast(111);
    dobj.InsertLast(121);

    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    dobj.InsertAtPos(105, 5);

    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    dobj.DeleteAtPos(5);

    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    dobj.DeleteFirst();

    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    dobj.DeleteLast();

    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    return 0;
}