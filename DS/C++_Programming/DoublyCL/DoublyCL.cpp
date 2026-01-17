#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node *PNODE;

class DoublyCL
{
    private:

        PNODE first;
        PNODE last;
        int iCount;

    public:

        DoublyCL()
        {
            first = NULL;
            last = NULL;
            iCount = 0;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn -> data = no;
            newn -> next = NULL;
            newn -> prev = NULL;

            if((first == NULL) && (last == NULL))
            {
                first = newn;
                last = newn;
            }
            else
            {
                newn -> next = first;
                first -> prev = newn;
                first = newn;
            }

            last -> next = first;
            first -> prev = last;

            iCount++;
        }

        void InsertLast(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn -> data = no;
            newn -> next = NULL;
            newn -> prev = NULL;

            if((first == NULL) && (last == NULL))
            {
                first = newn;
                last = newn;
            }
            else
            {
                last -> next = newn;
                newn -> prev = last;
                last = newn;
            }

            last -> next = first;
            first -> prev = last;

            iCount++;
        }

        void InsertAtPos(int no, int Pos)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;
            int iCnt = 0;

            if((Pos < 1) || (Pos > iCount + 1))
            {
                cout << "Invalid Position\n";
                return;
            }

            if(Pos == 1)
            {
                InsertFirst(no);
            }
            else if(Pos == iCount + 1)
            {
                InsertLast(no);
            }
            else
            {
                newn = new NODE;

                newn->data = no;
                newn->next = NULL;
                newn->prev = NULL;

                temp = first;

                for(iCnt = 1; iCnt < Pos - 1; iCnt++)
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
            if((first == NULL) && (last == NULL))
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
                first = first -> next;
                delete first -> prev;
                last -> next = first;
                first -> prev = last;
            }

            iCount--;
        }

        void DeleteLast()
        {
            if((first == NULL) && (last == NULL))
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
                last = last -> prev;
                delete last -> next;
                last -> next = first;
                first -> prev = last;
            }

            iCount--;
        }

        void DeleteAtPos(int Pos)
        {
            PNODE temp = NULL;
            int iCnt = 0;

            if(Pos < 1 || Pos > iCount)
            {
                cout << "Invalid Position\n";
                return;
            }

            if(Pos == 1)
            {
                DeleteFirst();
            }
            else if(Pos == iCount)
            {
                DeleteLast();
            }
            else
            {
                temp = first;

                for(iCnt = 1; iCnt < Pos - 1; iCnt++)
                {
                    temp = temp -> next;
                }

                temp -> next = temp -> next -> next;
                delete temp -> next -> prev;
                temp -> next -> prev = temp;

                iCount--;
            }
        }
        
        void Display()
        {
            PNODE temp = NULL;

            if((first == NULL) && (last == NULL))
            {
                cout << "Linked List is empty\n";
                return;
            }

            temp = first;

            cout << "\n <=> ";

            do
            {
                cout << "| " << temp -> data << " | <=> ";
                temp = temp -> next;
            }while(temp != first);

            cout << "\n";

        }
        
        int Count()
        {
            return iCount;
        }
};


int main()
{
    DoublyCL dobj;
    int iRet = 0;

    dobj.Display();
    iRet = dobj.Count();
    cout << "Number of nodes are : " << iRet << "\n";

    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);

    dobj.Display();
    iRet = dobj.Count();
    cout << "Number of nodes are : " << iRet << "\n";

    dobj.InsertLast(101);
    dobj.InsertLast(111);
    dobj.InsertLast(121);

    dobj.Display();
    iRet = dobj.Count();
    cout << "Number of nodes are : " << iRet << "\n";

    dobj.InsertAtPos(105, 5);

    dobj.Display();
    iRet = dobj.Count();
    cout << "Number of nodes are : " << iRet << "\n";

    dobj.DeleteAtPos(5);

    dobj.Display();
    iRet = dobj.Count();
    cout << "Number of nodes are : " << iRet << "\n";

    dobj.DeleteFirst();

    dobj.Display();
    iRet = dobj.Count();
    cout << "Number of nodes are : " << iRet << "\n";

    dobj.DeleteLast();

    dobj.Display();
    iRet = dobj.Count();
    cout << "Number of nodes are : " << iRet << "\n";

    return 0;
}