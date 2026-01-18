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

class Program02
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
    }
}