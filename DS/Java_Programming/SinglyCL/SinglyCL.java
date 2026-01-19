class SinglyCLLNode
{
    public int data;
    public SinglyCLLNode next;

    public SinglyCLLNode(int no)
    {
        this.data = no;
        this.next = null;
    }
}

class SinglyCLL
{
    private SinglyCLLNode first;
    private SinglyCLLNode last;
    private int iCount;

    public SinglyCLL()
    {
        this.first = null;
        this.last = null;
        this.iCount = 0;
    }

    public void InsertFirst(int no)
    {
        SinglyCLLNode newn = null;

        newn = new SinglyCLLNode(no);

        if((this.first == null) && (this.last == null))
        {
            this.first = newn;
            this.last = newn;
        }
        else
        {
            newn.next = this.first;
            this.first = newn;
        }

        this.last.next = this.first;

        this.iCount++;
    }

    public void InsertLast(int no)
    {
        SinglyCLLNode newn = null;

        newn = new SinglyCLLNode(no);

        if((this.first == null) && (this.last == null))
        {
            this.first = newn;
            this.last = newn;
        }
        else
        {
            this.last.next = newn;
            this.last = newn;
        }

        this.last.next = this.first;

        this.iCount++;
    }

    public void InsertAtPos(int no, int Pos)
    {
        SinglyCLLNode newn = null;
        SinglyCLLNode temp = null;
        int iCnt = 0;

        if((Pos < 1) || (Pos > this.iCount + 1))
        {
            System.out.println("Invalid position");
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
            newn = new SinglyCLLNode(no);

            temp = this.first;

            for(iCnt = 1; iCnt < Pos - 1; iCnt++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
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
        }

        this.last.next = this.first;

        System.gc();

        this.iCount--;
    }

    public void DeleteLast()
    {
        SinglyCLLNode temp = null;

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
            temp = this.first;

            while(temp.next.next != this.first)
            {
                temp = temp.next;
            }

            this.last = temp;
        }

        this.last.next = this.first;

        System.gc();

        this.iCount--;
    }

    public void DeleteAtPos(int Pos)
    {
        SinglyCLLNode temp = null;
        int iCnt = 0;

        if( (Pos < 1) || (Pos > this.iCount) )
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
                temp = temp . next;
            }

            temp.next = temp.next.next;

            System.gc();

            this.iCount--;
        }
    }

    public void Display()
    {
        SinglyCLLNode temp = null;

        temp = this.first;

        System.out.print("\n-> ");

        do
        {
            System.out.print("| " + temp.data + " | -> ");
            temp = temp.next;
        }while(temp != this.first);

        System.out.println();
    }

    public int Count()
    {
        return this.iCount;
    }

}
class SinglyCL
{
    public static void main(String A[])
    {
        SinglyCLL sobj = new SinglyCLL();
        int iRet = 0;

        sobj.InsertFirst(3);
        sobj.InsertFirst(2);
        sobj.InsertFirst(1);

        sobj.Display();
        iRet = sobj.Count();
        System.out.println("Number of nodes are : " + iRet);

        sobj.InsertLast(4);
        sobj.InsertLast(5);
        sobj.InsertLast(6);

        sobj.Display();
        iRet = sobj.Count();
        System.out.println("Number of nodes are : " + iRet);

        sobj.InsertAtPos(7, 4);

        sobj.Display();
        iRet = sobj.Count();
        System.out.println("Number of nodes are : " + iRet);

        sobj.DeleteAtPos(4);

        sobj.Display();
        iRet = sobj.Count();
        System.out.println("Number of nodes are : " + iRet);

        sobj.DeleteFirst();

        sobj.Display();
        iRet = sobj.Count();
        System.out.println("Number of nodes are : " + iRet);

        sobj.DeleteLast();

        sobj.Display();
        iRet = sobj.Count();
        System.out.println("Number of nodes are : " + iRet);
    }
}