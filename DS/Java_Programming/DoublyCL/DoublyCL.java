class DoublyCLLNode
{
    public int data;
    public DoublyCLLNode next;
    public DoublyCLLNode prev;

    public DoublyCLLNode(int no)
    {
        this.data = no;
        this.next = null;
        this.prev = null;
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

        if((this.first == null) && (this.last == null))
        {
            this.first = newn;
            this.last = newn;
        }
        else
        {
            newn.next = this.first;
            this.first.prev = newn;
            this.first = newn;
        }

        this.first.prev = this.last;
        this.last.next = this.first;

        this.iCount++;
    }

    public void InsertLast(int no)
    {
        DoublyCLLNode newn = null;

        newn = new DoublyCLLNode(no);

        if((this.first == null) && (this.last == null))
        {
            this.first = newn;
            this.last = newn;
        }
        else
        {
            this.last.next = newn;
            newn.prev = this.last;
            this.last = newn;
        }

        this.first.prev = this.last;
        this.last.next = this.first;

        this.iCount++;
    }

    public void InsertAtPos(int no, int Pos)
    {
        DoublyCLLNode newn = null;
        DoublyCLLNode temp = null;
        int iCnt = 0;

        if((Pos < 1) || (Pos > this.iCount + 1))
        {
            System.out.println("Invalid Position");
            return;
        }

        if(Pos == 1)
        {
            this.InsertFirst(no);
        }
        else if(Pos == this.iCount + 1)
        {
            this.InsertLast(no);
        }
        else
        {
            newn = new DoublyCLLNode(no);

            temp = this.first;

            for(iCnt = 1; iCnt < Pos - 1; iCnt++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next.prev = newn;
            newn.prev = temp;
            temp.next = newn;

            this.iCount++;
        }
    }

    public void DeleteFirst()
    {
        if((this.first == null) && (this.last == null))
        {
            return;
        }
        else if(this.first == this.last)
        {
            this.first = null;
            this.last = null;
        }
        else
        {
            this.first = this.first.next;
            this.first.prev = this.last;
            this.last.next = this.first;
        }

        System.gc();
        this.iCount--;
    }

    public void DeleteLast()
    {
        if((this.first == null) && (this.last == null))
        {
            return;
        }
        else if(this.first == this.last)
        {
            this.first = null;
            this.last = null;
        }
        else
        {
            this.last = this.last.prev;
            this.last.next = this.first;
            this.first.prev = this.last;
        }

        System.gc();
        this.iCount--;
    }

    public void DeleteAtPos(int Pos)
    {
        DoublyCLLNode temp = null;
        int iCnt = 0;

        if((Pos < 1) || (Pos > this.iCount))
        {
            System.out.println("Invalid Position");
            return;
        }

        if(Pos == 1)
        {
            this.DeleteFirst();
        }
        else if(Pos == this.iCount)
        {
            this.DeleteLast();
        }
        else
        {
            temp = this.first;

            for(iCnt = 1; iCnt < Pos - 1; iCnt++)
            {
                temp = temp.next;
            }

            temp.next = temp.next.next;
            temp.next.prev = temp;

            System.gc();
            this.iCount--;
        }
    }

    public void Display()
    {
        DoublyCLLNode temp = null;

        temp = this.first;

        if((this.first == null) && (this.last == null))
        {
            System.out.println("Linked list is Empty");
            return;
        }

        System.out.print("\n<=> ");

        do
        {
            System.out.print("| " + temp.data + " | <=> ");
            temp = temp.next;
        }while(temp != this.first);

        System.out.println();
    }

    public int Count()
    {
        return this.iCount;
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