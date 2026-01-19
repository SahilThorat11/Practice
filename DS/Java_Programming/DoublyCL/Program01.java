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
        
    }

    public void InsertLast(int no)
    {

    }

    public void InsertAtPos(int no, int Pos)
    {
    
    }

    public void DeleteFirst()
    {
        
    }

    public void DeleteLast()
    {
       
    }

    public void DeleteAtPos(int Pos)
    {
        
    }

    public void Display()
    {
        
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