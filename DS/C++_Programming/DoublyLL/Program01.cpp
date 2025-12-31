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
                first->prev = newn;
                first = newn;
            }

            iCount++;
        }

        void InsertLast(int no)
        {}

        void InsertAtPos(int no, int iPos)
        {}

        void DeleteFirst()
        {}

        void DeleteLast()
        {}

        void DeleteAtPos(int iPos)
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
    int iRet = 0;
    DoublyLL obj;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    return 0;
}