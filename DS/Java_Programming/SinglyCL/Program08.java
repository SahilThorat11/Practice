class SinglyCLNode
{
    public int data;
    public SinglyCLNode next;

    public SinglyCLNode(int no)
    {
        data = no;
        next = null;
    }
}

class SinglyCL
{
    private SinglyCLNode first;
    private SinglyCLNode last;
    private int iCount;

    public SinglyCL()
    {
        first = null;
        last = null;
        iCount = 0;
    }

    public void InsertFirst(int no)
    {
        SinglyCLNode newn = null;

        newn = new SinglyCLNode(no);

        if(first == null && last == null)
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn.next = first;
            first = newn;
        }

        last.next = first;
        iCount++;
    }

    public void InsertLast(int no)
    {
        SinglyCLNode newn = null;

        newn = new SinglyCLNode(no);

        if(first == null && last == null)
        {
            first = newn;
            last = newn;
        }
        else
        {
            last.next = newn;
            last = newn;
        }

        last.next = first;
        iCount++;
    }

    public void InsertAtPos(int no, int Pos)
    {
        SinglyCLNode newn = null;
        SinglyCLNode temp = null;
        int iCnt = 0;

        if((Pos == 1) || (Pos == iCount + 1))
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
            newn = new SinglyCLNode(no);

            temp = first;

            for(iCnt = 1; iCnt < Pos - 1; iCnt++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
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
            last.next = first;
        }

        System.gc();
        iCount--;
    }

    public void DeleteLast()
    {
        SinglyCLNode temp = null;

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
            temp = first;

            while(temp.next.next != first)
            {
                temp = temp.next;
            }

            last = temp;
            last.next = first;
        }

        System.gc();
        iCount--;
    }

    public void DeleteAtPos(int Pos)
    {
        SinglyCLNode temp = null;
        int iCnt = 0;

        if((Pos == 1) || (Pos == iCount))
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

            System.gc();
            iCount--;
        }
    }

    public void Display()
    {
        SinglyCLNode temp = null;

        temp = first;

        System.out.println();

        do
        {
            System.out.print("| " + temp.data + " | -> ");
            temp = temp.next;
        }while(temp != last.next);

        System.out.println();
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
        SinglyCL sobj = new SinglyCL();
        int iRet = 0;

        sobj.InsertFirst(51);
        sobj.InsertFirst(21);
        sobj.InsertFirst(11);

        sobj.Display();
        iRet = sobj.Count();
        System.out.println("Number of nodes are : " + iRet);

        sobj.InsertLast(101);
        sobj.InsertLast(111);
        sobj.InsertLast(121);

        sobj.Display();
        iRet = sobj.Count();
        System.out.println("Number of nodes are : " + iRet);

        sobj.InsertAtPos(105, 5);

        sobj.Display();
        iRet = sobj.Count();
        System.out.println("Number of nodes are : " + iRet);

        sobj.DeleteAtPos(5);

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