class DoublyLLLNode
{
    public int data;
    public DoublyLLLNode next;
    public DoublyLLLNode prev;

    public DoublyLLLNode(int no)
    {
        this.data = no;
        this.next = null;
        this.prev = null;
    }
}

class DoublyLLL
{
    public DoublyLLLNode first;
    public int iCount;

    public DoublyLLL()
    {
        this.first = null;
        this.iCount = 0;
    }

    public void InsertFirst(int no)                
    {
        DoublyLLLNode newn = null;

        newn = new DoublyLLLNode(no);

        if(this.first == null)               
        {
            this.first = newn;
        }
        else                            
        {
            newn.next = this.first;
            this.first.prev = newn;
            this.first = newn;
        }

        this.iCount++;
    }

    public void InsertLast(int no)                 
    {
        DoublyLLLNode newn = null;
        DoublyLLLNode temp = null;

        newn = new DoublyLLLNode(no);

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
            newn.prev = temp;
        }

        this.iCount++;
    }

    public void InsertAtPos(int no, int Pos)         
    {
        DoublyLLLNode newn = null;
        DoublyLLLNode temp = null;
        int iCnt = 0;

        if((Pos < 1) || (Pos > this.iCount + 1))
        {
            System.out.println("Invalid Position");
            return;
        }

        if(Pos == 1)
        {
            InsertFirst(no);
        }
        else if(Pos == this.iCount + 1)
        {
            InsertLast(no);
        }
        else
        {
            newn = new DoublyLLLNode(no);

            temp = this.first;

            for(iCnt = 1; iCnt < Pos - 1; iCnt++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next.prev = newn;
            temp.next = newn;
            newn.prev = temp;

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
            this.first.prev = null;
        }

        System.gc();
        this.iCount--;
    }

    public void DeleteLast()
    {
        DoublyLLLNode temp = null;

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
        DoublyLLLNode temp = null;
        int iCnt = 0;

        if((Pos < 1) || (Pos > this.iCount) )
        {
            System.out.println("Invalid Position");
            return;
        }

        if(Pos == 1)
        {
            DeleteFirst();
        }
        else if(Pos == this.iCount)
        {
            DeleteLast();
        }
        else 
        {
            temp = this.first;

            for(iCnt = 1; iCnt < Pos - 1; iCnt++)
            {
                temp = temp.next;
            }

            temp.next = temp.next.next;
            temp.next.prev = temp;

            System.gc();
            this.iCount--;
        }
    }

    public void Display()
    {
        DoublyLLLNode temp = null;

        temp = this.first;

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
        return this.iCount;
    }
    
}

class DoublyLL
{
    public static void main(String A[])
    {
        DoublyLLL dobj = new DoublyLLL();
        int iRet = 0;

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