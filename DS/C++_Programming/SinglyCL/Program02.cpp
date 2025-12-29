#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;

class SinglyCL
{
    private:
        PNODE first;
        PNODE last;
        int iCount;
    
    public:
        SinglyCL()
        {
            this->first = NULL;
            this->last = NULL;
            this->iCount = 0; 
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn -> data = no;
            newn -> next = NULL;

            if((this->first == NULL) && (this->last == NULL))
            {
                this->first = newn;
                this->last = newn;
            }
            else
            {
                newn -> next = this->first;
                this->first = newn;
            }

            this->last -> next = this->first;
            this->iCount++;
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
        {
            PNODE temp = NULL;

            temp = this->first;

            cout<<"\n -> ";

            do
            {
                cout<<"| "<<temp -> data<<" | ->";
                temp = temp -> next;
            }while(temp != this->last -> next);

            cout<<"\n";
        }

        int Count()
        {
            return iCount;
        }
};

int main()
{
    int iRet = 0;
    SinglyCL obj;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    return 0;
}