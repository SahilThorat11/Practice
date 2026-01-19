
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
        DoublyLLNode temp = null;

        temp = first;

        System.out.print("\nnull <=> ");

        while(temp != null)
        {
            System.out.print("| " + temp.data + " | <=> ");
            temp = temp.next;
        }

        System.out.println("null");
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
        DoublyLL dobj = new DoublyLL();
        int iRet = 0;

        dobj.InsertFirst(51);
        dobj.InsertFirst(21);
        dobj.InsertFirst(11);

        dobj.Display();
        iRet = dobj.Count();
        System.out.println("Number of nodes are : " + iRet);

    }
}