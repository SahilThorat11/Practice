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

class Program01
{
    public static void main(String A[])
    {
        SinglyLL sobj = new SinglyLL();
    }
}