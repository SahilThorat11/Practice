
class DoublyLLNode
{
    public int data;
    public DoublyLLNode next;
    public DoublyLLNode prev;

    public DoublyLLNode(int no)
    {
        data = no;
        next = null;
        prev = null;
    }
}

class DoublyLL
{
    public DoublyLL first;
    public int iCount;

    public DoublyLL()
    {
        System.out.println("Object of DoublyLL gets created");
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
        DoublyLL dobj = new DoublyLL();
    }
}