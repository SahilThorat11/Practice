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

        dobj.InsertFirst(51);
        dobj.InsertFirst(21);
        dobj.InsertFirst(11);
    }
}