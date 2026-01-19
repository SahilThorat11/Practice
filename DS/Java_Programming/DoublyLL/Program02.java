
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
    public DoublyLLNode first;
    public int iCount;

    public DoublyLL()
    {
        System.out.println("Object of DoublyLL gets created");
        first = null;
        iCount = 0;
    }

    public void InsertFirst(int no)
    {
        DoublyLLNode newn = null;

        newn = new DoublyLLNode(no);

        if(first == null)
        {
            first = newn;
        }
        else
        {
            newn.next = first;
            first.prev = newn;
            first = newn;
        }

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

class Program02
{
    public static void main(String A[])
    {
        DoublyLL dobj = new DoublyLL();
        int iRet = 0;

        dobj.InsertFirst(51);
        dobj.InsertFirst(21);
        dobj.InsertFirst(11);

    }
}