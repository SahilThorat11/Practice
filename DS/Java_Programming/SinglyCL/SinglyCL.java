class SinglyCLLNode
{
    public int data;
    public SinglyCLLNode next;

    public SinglyCLLNode(int no)
    {
        data = no;
        next = null;
    }
}

class SinglyCLL
{
    private SinglyCLLNode first;
    private SinglyCLLNode last;
    private int iCount;

    public SinglyCLL()
    {
        first = null;
        last = null;
        iCount = 0;
    }

    public void InsertFirst(int no)
    {
        SinglyCLLNode newn = null;

        newn = new SinglyCLLNode(no);

        if((first == null) && (last == null))
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
        SinglyCLLNode newn = null;

        newn = new SinglyCLLNode(no);

        if((first == null) && (last == null))
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
        SinglyCLLNode newn = null;
        SinglyCLLNode temp = null;
        int iCnt = 0;

        if((Pos < 1) || (Pos > iCount + 1))
        {
            System.out.println("Invalid position");
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
            newn = new SinglyCLLNode(no);

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
        }

        last.next = first;

        System.gc();

        iCount--;
    }

    public void DeleteLast()
    {
        SinglyCLLNode temp = null;

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
        }

        last.next = first;

        System.gc();

        iCount--;
    }

    public void DeleteAtPos(int Pos)
    {
        SinglyCLLNode temp = null;
        int iCnt = 0;

        if( (Pos < 1) || (Pos > iCount) )
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
                temp = temp . next;
            }

            temp.next = temp.next.next;

            System.gc();

            iCount--;
        }
    }

    public void Display()
    {
        SinglyCLLNode temp = null;

        temp = first;

        System.out.print("\n-> ");

        do
        {
            System.out.print("| " + temp.data + " | -> ");
            temp = temp.next;
        }while(temp != first);

        System.out.println();
    }

    public int Count()
    {
        return iCount;
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