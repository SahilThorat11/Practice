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
        {}

        void InsertAtPos(int no)
        {}

        void DeleteFirst()
        {}

        void DeleteLast()
        {}

        void DeleteAtPos(int Pos)
        {}

        void Display()
        {}

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

    return 0;
}