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
    public :
        PNODE first;
        PNODE last;
        int iCount;

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
            
            if((first == NULL) && (last == NULL))   // LL is empty
            {
                first = newn;
                last = newn;
            }
            else                                    // LL contains more than one node
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
            PNODE temp = NULL;

            newn = new NODE;

            newn -> data = no;
            newn -> next = NULL;
            newn -> prev = NULL;
            
            if((first == NULL) && (last == NULL))   // LL is empty
            {
                first = newn;
                last = newn;
            }
            else                                    // LL contains more than one node
            {
               temp = first;

               while(temp -> next != first)
               {
                temp = temp -> next;
               }

               temp -> next = newn;
               newn -> prev = temp;
               last = newn;
            }

            last -> next = first;
            first -> prev = last;

            iCount++;
        }

        void InsertAtPos(int no,int Pos)
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
                newn = new node;

                newn -> data = no;
                newn -> next = NULL;
                newn -> next = NULL;

                temp = first;

                for(iCnt = 1; iCnt < Pos - 1; iCnt++)
                {
                    temp = temp -> next;
                }

                newn -> next = temp -> next;
                temp -> next -> prev = newn;
                temp -> next = newn;
                newn -> prev = temp;

            }

            iCount++;
        }

        void DeleteFirst()
        {}

        void DeleteLast()
        {}

        void DeleteAtPos(int Pos)
        {}

        void Display()
        {
            PNODE temp = NULL;

            if(first == NULL)
            {
                cout << "Linked list is empty\n";
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

        int Count()
        {
            return iCount;
        }
};

int main()
{
    DoublyCL dobj;
    int iRet = 0;

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

    dobj.InsertAtPos(105,5);

    dobj.Display();
    iRet = dobj.Count();
    cout << "Number of nodes are : " << iRet << "\n";

    return 0;
}