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

        void InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;
            newn->data = no;
            newn->next = NULL;

            if (head == NULL)        // LL is empty
            {
                head = newn;
            }
            else                     // LL contains one or more node
            {
                newn->next = head;
                head = newn;
            }
            iCount++;
        }

        void InsertLast(int no)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;

            newn = new NODE;
            newn->data = no;
            newn->next = NULL;

            if (head == NULL)           // LL is empty
            {
                head = newn;
            }
            else                        // LL contains one or more node
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

        void InsertAtPos(int no, int ipos)
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
                InsertFirst(no);
            }
            else if (ipos == iCount + 1)
            {
                InsertLast(no);
            }
            else
            {
                newn = new NODE;
                newn->data = no;
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


        void DeleteFirst()
        {
            PNODE temp = NULL;

            if (head == NULL)                 // LL is empty
            {
                return;
            }
            else if (head->next == NULL)      // LL contains one node
            {
                delete head;
                head = NULL;
            }
            else                              // LL contains more than one node
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

            if (head == NULL)                       // LL is empty
            {
                return;
            }
            else if (head->next == NULL)            // LL contains one node
            {
                delete head;
                head = NULL;
            }
            else                                    // LL contains more than one node
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

        void DeleteAtPos(int ipos)
        {
            int iCnt = 0;
            PNODE temp = head;
            PNODE target = NULL;

            if (ipos < 1 || ipos > iCount)
            {
                cout << "Invalid position\n";
                return;
            }

            if (ipos == 1)
            {
                DeleteFirst();
            }
            else if (ipos == iCount)
            {
                DeleteLast();
            }
            else
            {
                for (iCnt = 1; iCnt < ipos - 1; iCnt++)
                {
                    temp = temp->next;
                }

                target = temp->next;
                temp->next = target->next;
                delete target;
                iCount--;   
            }
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
    cout << "Number of elements are : " << iRet << "\n";

    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);

    sobj.Display();
    iRet = sobj.Count();
    cout << "Number of elements are : " << iRet << "\n";

    sobj.InsertAtPos(75, 4);

    sobj.Display();
    iRet = sobj.Count();
    cout << "Number of elements are : " << iRet << "\n";

    sobj.DeleteAtPos(4);

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

    return 0;
}