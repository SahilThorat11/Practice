#include<iostream>
using namespace std;

class DoublyCLNode
{
    public:
        int data;
        DoublyCLNode *next;
        DoublyCLNode *prev;

        DoublyCLNode(int no)
        {
            data = no;
            next = NULL;
            prev = NULL;
        }
};

class DoublyCL
{
    private:

        DoublyCLNode *first;
        DoublyCLNode *last;
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
            DoublyCLNode *newn = NULL;

            newn = new DoublyCLNode(no);

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
            DoublyCLNode *newn = NULL;

            newn = new DoublyCLNode(no);

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
            DoublyCLNode *newn = NULL;
            DoublyCLNode *temp = NULL;
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
                newn = new DoublyCLNode(no);

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
            DoublyCLNode *temp = NULL;
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
            DoublyCLNode *temp = NULL;

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
    DoublyCL obj1;
    DoublyCL obj2;
    int iRet = 0;

    obj1.Display();
    iRet = obj1.Count();
    cout << "Number of nodes are : " << iRet << "\n";

    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);

    obj1.Display();
    iRet = obj1.Count();
    cout << "Number of nodes are : " << iRet << "\n";

    obj1.InsertLast(101);
    obj1.InsertLast(111);
    obj1.InsertLast(121);

    obj1.Display();
    iRet = obj1.Count();
    cout << "Number of nodes are : " << iRet << "\n";

    obj1.InsertAtPos(105, 5);

    obj1.Display();
    iRet = obj1.Count();
    cout << "Number of nodes are : " << iRet << "\n";

    obj1.DeleteAtPos(5);

    obj1.Display();
    iRet = obj1.Count();
    cout << "Number of nodes are : " << iRet << "\n";

    obj1.DeleteFirst();

    obj1.Display();
    iRet = obj1.Count();
    cout << "Number of nodes are : " << iRet << "\n";

    obj1.DeleteLast();

    obj1.Display();
    iRet = obj1.Count();
    cout << "Number of nodes are : " << iRet << "\n";

    return 0;
}