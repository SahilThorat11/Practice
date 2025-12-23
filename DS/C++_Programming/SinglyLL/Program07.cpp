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
        {
            PNODE newn = NULL;
            PNODE temp = NULL;

            newn = new NODE;
            newn->data = iNo;
            newn->next = NULL;

            if (head == NULL)
            {
                head = newn;
            }
            else
            {
                temp = head;

                while (temp->next != NULL)
                {
                    temp = temp->next;
                }

                temp->next = newn;
            }
            iCount++;
        }

        void DeleteFirst()
        {
            PNODE temp = NULL;

            if (head == NULL)
            {
                return;
            }
            else if (head->next == NULL)
            {
                delete head;
                head = NULL;
            }
            else
            {
                temp = head;

                head = head->next;
                delete temp;
            }
            iCount--;
        }

        void DeleteLast()
        {
            PNODE temp = NULL;

            if (head == NULL)
            {
                return;
            }
            else if (head->next == NULL)
            {
                delete head;
                head = NULL;
            }
            else
            {
                temp = head;

                while (temp->next->next != NULL)
                {
                    temp = temp->next;
                }

                delete temp->next;
                temp->next = NULL;
            }
            iCount--;
        }

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

        void InsertAtPos(int iNo, int ipos)
        {
            int iCnt = 0;
            PNODE newn = NULL;
            PNODE temp = head;

            if (ipos < 1 || ipos > iCount + 1)
            {
                cout << "Invalid position\n";
                return;
            }

            if (ipos == 1)
            {
                InsertFirst(iNo);
            }
            else if (ipos == iCount + 1)
            {
                InsertLast(iNo);
            }
            else
            {
                newn = new NODE;
                newn->data = iNo;
                newn->next = NULL;

                for (iCnt = 1; iCnt < ipos - 1; iCnt++)
                {
                    temp = temp->next;
                }

                newn->next = temp->next;
                temp->next = newn;
                iCount++;   
            }
        }

        void DeleteAtPos(int ipos)
        {}
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

    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);

    sobj.Display();
    iRet = sobj.Count();
    cout << "Number of elements are : " << iRet << "\n";

    sobj.DeleteFirst();

    sobj.Display();
    iRet = sobj.Count();
    cout << "Number of elements are : " << iRet << "\n";

    sobj.DeleteLast();

    sobj.Display();
    iRet = sobj.Count();
    cout << "Number of elements are : " << iRet << "\n";

    sobj.InsertAtPos(105, 4);

    sobj.Display();
    iRet = sobj.Count();
    cout << "Number of elements are : " << iRet << "\n";

    return 0;
}