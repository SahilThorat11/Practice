class SinglyLLNode
{
    public int data;
    public SinglyLLNode next;

    public SinglyLLNode(int no)
    {
        this.data = no;
        next = null;
    }
}

class SinglyLL
{
    private SinglyLLNode first;
    private int iCount;

    public SinglyLL()
    {
        System.out.println("Object is created successfully");
        this.first = null;
        iCount = 0;
    }

    public void InsertFirst(int no)
    {
        SinglyLLNode newn = null;

        newn = new SinglyLLNode(no);

        newn.next = this.first;
        this.first = newn;

        this.iCount++;
    }

    public void InsertLast(int no)
    {
        SinglyLLNode newn = null;
        SinglyLLNode temp = null;

        newn = new SinglyLLNode(no);

        if(this.first == null)
        {
            this.first = newn;
        }
        else
        {
            temp = this.first;

            while(temp.next != null)
            {
                temp = temp.next;
            }

            temp.next = newn;
        }

        this.iCount++;
    }

    public void InsertAtPos(int no, int Pos)
    {
        SinglyLLNode newn = null;
        SinglyLLNode temp = null;
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
        else if(Pos == iCount + 1)
        {
            this.InsertLast(no);
        }
        else
        {
            newn = new SinglyLLNode(no);
            
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
        if(this.first == null)
        {
            return;
        }
        else if(this.first.next == null)
        {
            this.first = null;
        }
        else
        {
            this.first = this.first.next;
        }

        System.gc();
        this.iCount--;
    }

    public void DeleteLast()
    {
        SinglyLLNode temp = null;

        if(this.first == null)
        {
            return;
        }
        else if(this.first.next == null)
        {
            this.first = null;
        }
        else
        {
            temp = this.first;

            while(temp.next.next != null)
            {
                temp = temp.next;
            }

            temp.next = null;
        }

        System.gc();
        this.iCount--;
    }

    public void DeleteAtPos(int Pos)
    {
        SinglyLLNode temp = null;
        int iCnt = 0;

        if((Pos < 1) || (Pos > this.iCount))
        {
            System.out.println("Invalid position");
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
            temp = this.first;

            for(iCnt = 1; iCnt < Pos - 1; iCnt++)
            {
                temp = temp.next;
            }

            temp.next = temp.next.next;

            System.gc();

            this.iCount--;
        }
    }

    public void Display()
    {
        SinglyLLNode temp = null;

        temp = this.first;

        System.out.println();

        while(temp != null)
        {
            System.out.print("| " + temp.data + " | -> ");
            temp = temp.next;
        }

        System.out.println("null");
    }

    public int Count()
    {
        return this.iCount;
    }
}

class Program08
{
    public static void main(String A[])
    {
        SinglyLL sobj = new SinglyLL();
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

        sobj = null;
        System.gc();
    }
}