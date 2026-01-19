
class DoublyLLNode
{
    public int data;
    public DoublyLLNode next;
    public DoublyLLNode prev;

    public DoublyLLNode(int no)
    {
        data = no;
        next = null;
        prev = null;
    }
}

class DoublyLL
{
    public DoublyLLNode first;
    public int iCount;

    public DoublyLL()
    {
        System.out.println("Object of DoublyLL gets created");
        first = null;
        iCount = 0;
    }

    public void InsertFirst(int no)
    {
        DoublyLLNode newn = null;

        newn = new DoublyLLNode(no);

        if(first == null)
        {
            first = newn;
        }
        else
        {
            newn.next = first;
            first.prev = newn;
            first = newn;
        }

        iCount++;
    }

    public void InsertLast(int no)
    {
        DoublyLLNode newn = null;
        DoublyLLNode temp = null;

        newn = new DoublyLLNode(no);

        if(first == null)
        {
            first = newn;
        }
        else
        {
            temp = first;

            while(temp.next != null)
            {
                temp = temp.next;
            }

            temp.next = newn;
            newn.prev = temp;
        }

        iCount++;
    }

    public void InsertAtPos(int no, int Pos)
    {
        DoublyLLNode newn = null;
        DoublyLLNode temp = null;
        int iCnt = 0;

        if( (Pos < 1) || (Pos > iCount + 1) )
        {
            System.out.println("Invalid Position");
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
            newn = new DoublyLLNode(no);

            temp = first;

            for(iCnt = 1; iCnt < Pos - 1; iCnt++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next.prev = newn;
            temp.next = newn;
            newn.prev = temp;

            iCount++;
        }
    }

    public void DeleteFirst()
    {
        if(first == null)
        {
            return;
        }
        else if(first.next == null)
        {
            first = null;
        }
        else
        {
            first = first.next;
            first.prev = null;
        }

        System.gc();
        iCount--;
    }

    public void DeleteLast()
    {
        DoublyLLNode temp = null;

        if(first == null)
        {
            return;
        }
        else if(first.next == null)
        {
            first = null;
        }
        else
        {
            temp = first;
            
            while(temp.next.next != null)
            {
                temp = temp.next;
            }

            temp.next = null;
        }

        System.gc();
        iCount--;
    }

    public void DeleteAtPos(int Pos)
    {
        DoublyLLNode temp = null;
        int iCnt = 0;

        if((Pos < 1) || (Pos > iCount) )
        {
            System.out.println("Invalid Position");
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
                temp = temp.next;
            }

            temp.next = temp.next.next;
            temp.next.prev = temp;

            System.gc();
            iCount--;
        }
    }

    public void Display()
    {
        DoublyLLNode temp = null;

        temp = first;

        System.out.print("\nnull <=> ");

        while(temp != null)
        {
            System.out.print("| " + temp.data + " | <=> ");
            temp = temp.next;
        }

        System.out.println("null");
    }

    public int Count()
    {
        return iCount;
    }
}

class Program08
{
    public static void main(String A[])
    {
        DoublyLL dobj = new DoublyLL();
        int iRet = 0;

        dobj.InsertFirst(51);
        dobj.InsertFirst(21);
        dobj.InsertFirst(11);

        dobj.Display();
        iRet = dobj.Count();
        System.out.println("Number of nodes are : " + iRet);

        dobj.InsertLast(101);
        dobj.InsertLast(111);
        dobj.InsertLast(121);

        dobj.Display();
        iRet = dobj.Count();
        System.out.println("Number of nodes are : " + iRet);

        dobj.InsertAtPos(105, 5);

        dobj.Display();
        iRet = dobj.Count();
        System.out.println("Number of nodes are : " + iRet);

        dobj.DeleteAtPos(5);

        dobj.Display();
        iRet = dobj.Count();
        System.out.println("Number of nodes are : " + iRet);

        dobj.DeleteFirst();

        dobj.Display();
        iRet = dobj.Count();
        System.out.println("Number of nodes are : " + iRet);

        dobj.DeleteLast();

        dobj.Display();
        iRet = dobj.Count();
        System.out.println("Number of nodes are : " + iRet);

    }
}