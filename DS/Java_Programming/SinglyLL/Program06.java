class SinglyLLNode
{
    public int data;
    public SinglyLLNode next;

    public SinglyLLNode(int no)
    {
        data = no;
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
        first = null;
        iCount = 0;
    }

    public void InsertFirst(int no)
    {
        SinglyLLNode newn = null;

        newn = new SinglyLLNode(no);

        newn.next = first;
        first = newn;

        iCount++;
    }

    public void InsertLast(int no)
    {
        SinglyLLNode newn = null;
        SinglyLLNode temp = null;

        newn = new SinglyLLNode(no);

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
        }

        iCount++;
    }

    public void InsertAtPos(int no, int Pos)
    {
        SinglyLLNode newn = null;
        SinglyLLNode temp = null;
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
            newn = new SinglyLLNode(no);
            
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
        }

        System.gc();
        iCount--;
    }

    public void DeleteLast()
    {
        
    }

    public void DeleteAtPos(int Pos)
    {
        
    }

    public void Display()
    {
        SinglyLLNode temp = null;

        temp = first;

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
        return iCount;
    }
}

class Program06
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

        sobj.DeleteFirst();

        sobj.Display();
        iRet = sobj.Count();
        System.out.println("Number of nodes are : " + iRet);
    }
}