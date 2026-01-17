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
    DoublyCL obj;
    int ichoice = 1, ivalue = 0, ipos = 0;

    while(ichoice != 0)
    {
        cout << "\n---------------- MENU ----------------\n";
        cout << "1 : Insert First\n";
        cout << "2 : Insert Last\n";
        cout << "3 : Insert At Position\n";
        cout << "4 : Delete First\n";
        cout << "5 : Delete Last\n";
        cout << "6 : Delete At Position\n";
        cout << "7 : Display\n";
        cout << "8 : Count\n";
        cout << "0 : Exit\n";
        cout << "-------------------------------------\n";
        cout << "Enter your ichoice : ";
        cin >> ichoice;

        switch(ichoice)
        {
        case 1:
            cout << "Enter ivalue : ";
            cin >> ivalue;
            obj.InsertFirst(ivalue);
            break;

        case 2:
            cout << "Enter ivalue : ";
            cin >> ivalue;
            obj.InsertLast(ivalue);
            break;

        case 3:
            cout << "Enter ivalue and position : ";
            cin >> ivalue >> ipos;
            obj.InsertAtPos(ivalue, ipos);
            break;

        case 4:
            obj.DeleteFirst();
            break;

        case 5:
            obj.DeleteLast();
            break;

        case 6:
            cout << "Enter position : ";
            cin >> ipos;
            obj.DeleteAtPos(ipos);
            break;

        case 7:
            obj.Display();
            break;

        case 8:
            cout << "Number of nodes : " << obj.Count() << "\n";
            break;

        case 0:
            cout << "Thank you for using Doubly Circular Linked List!\n";
            break;

        default:
            cout << "Invalid ichoice\n";
        }
    }

    return 0;
}
