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

    public void DeleteAtPos()
    {
        
    }

    public void Display()
    {
        SinglyCLNode temp = null;

        temp = first;

        System.out.print("-> ");

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

class Program03
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
    }
}