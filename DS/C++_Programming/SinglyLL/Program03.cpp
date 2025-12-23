#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

class SinglyLL
{
    public:
        PNODE head;
        int iCount;

        SinglyLL()
        {
            head = NULL;
            iCount = 0;
        }

        void InsertFirst(int iNo)
        {
            PNODE newn = NULL;

            newn = new NODE;
            newn->data = iNo;
            newn->next = NULL;

            if (head == NULL)
            {
                head = newn;
            }
            else
            {
                newn->next = head;
                head = newn;
            }
            iCount++;
        }

        void InsertLast(int iNo)
        {}

        void InsertAtPos(int iNo, int ipos)
        {}

        void DeleteFirst()
        {}

        void DeleteLast()
        {}

        void DeleteAtPos(int ipos)
        {}

        void Display()
        {
            PNODE temp = head;

            cout << "\n";

            while (temp != NULL)
            {
                cout << "| " << temp->data << " | -> ";
                temp = temp->next;
            }

            cout << "NULL\n\n";
        }

        int Count()
        {
            return iCount;
        }
};

int main()
{
    SinglyLL sobj;
    int iRet = 0;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.Display();
    iRet = sobj.Count();
    cout << "Number of nodes are : " << iRet << "\n";

    return 0;
}