class DoublyCLLNode
{
    public int data;
    public DoublyCLLNode next;
    public DoublyCLLNode prev;

    public DoublyCLLNode(int no)
    {
        data = no;
        next = null;
        prev = null;
    }
}

class DoublyCLL
{
    private DoublyCLLNode first;
    private DoublyCLLNode last;
    private int iCount;

    public DoublyCLL()
    {
        this.first = null;
        this.last = null;
        this.iCount = 0;
    }

    public void InsertFirst(int no)
    {
        DoublyCLLNode newn = null;

        newn = new DoublyCLLNode(no);

        if((first == null) && (last == null))
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn.next = first;
            first.prev = newn;
            first = newn;
        }

        first.prev = last;
        last.next = first;

        iCount++;
    }

    public void InsertLast(int no)
    {
        DoublyCLLNode newn = null;

        newn = new DoublyCLLNode(no);

        if((first == null) && (last == null))
        {
            first = newn;
            last = newn;
        }
        else
        {
            last.next = newn;
            newn.prev = last;
            last = newn;
        }

        first.prev = last;
        last.next = first;

        iCount++;
    }

    public void InsertAtPos(int no, int Pos)
    {
        DoublyCLLNode newn = null;
        DoublyCLLNode temp = null;
        int iCnt = 0;

        if((Pos < 1) || (Pos > iCount + 1))
        {
            System.out.println("Invalid Position");
            return;
        }

        if(Pos == 1)
        {
            this.InsertFirst(no);
        }
        else if(Pos == iCount + 1)
        {
            this.InsertLast(no);
        }
        else
        {
            newn = new DoublyCLLNode(no);

            temp = first;

            for(iCnt = 1; iCnt < Pos - 1; iCnt++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next.prev = newn;
            newn.prev = temp;
            temp.next = newn;

            iCount++;
        }
    }

    public void DeleteFirst()
    {
        if((first == null) && (last == null))
        {
            return;
        }
        else if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            first = first.next;
            first.prev = last;
            last.next = first;
        }

        System.gc();
        iCount--;
    }

    public void DeleteLast()
    {
        if((first == null) && (last == null))
        {
            return;
        }
        else if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            last = last.prev;
            last.next = first;
            first.prev = last;
        }

        System.gc();
        iCount--;
    }

    public void DeleteAtPos(int Pos)
    {
        DoublyCLLNode temp = null;
        int iCnt = 0;

        if((Pos < 1) || (Pos > iCount))
        {
            System.out.println("Invalid Position");
            return;
        }

        if(Pos == 1)
        {
            this.DeleteFirst();
        }
        else if(Pos == iCount)
        {
            this.DeleteLast();
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
        DoublyCLLNode temp = null;

        temp = first;

        if((first == null) && (last == null))
        {
            System.out.println("Linked list is Empty");
            return;
        }

        System.out.print("\n<=> ");

        do
        {
            System.out.print("| " + temp.data + " | <=> ");
            temp = temp.next;
        }while(temp != first);

        System.out.println();
    }

    public int Count()
    {
        return iCount;
    }
}

class DoublyCL
{
    public static void main(String A[])
    {
        DoublyCLL dobj = new DoublyCLL();
        int iRet = 0;

        dobj.Display();
        iRet = dobj.Count();
        System.out.println("Number of nodes are : " + iRet);

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