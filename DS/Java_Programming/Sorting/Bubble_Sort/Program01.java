import java.util.Scanner;

class ArrayX
{
    public int Arr[];
    public int iSize;
    public boolean Sorted;

    // Constructor
    public ArrayX(int no)
    {
        System.out.println("Inside constructor");
        iSize = no;
        Arr = new int[iSize];
        Sorted = true;
    }

    // Accept elements (checks sorted while accepting)
    public void Accept()
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the elements : ");

        Arr[0] = sobj.nextInt();   // First element

        for(int iCnt = 1; iCnt < iSize; iCnt++)
        {
            Arr[iCnt] = sobj.nextInt();

            if(Arr[iCnt - 1] > Arr[iCnt])
            {
                Sorted = false;
            }
        }
    }

    // Display elements
    public void Display()
    {
        System.out.println("Elements of the array are : ");

        for(int iCnt = 0; iCnt < iSize; iCnt++)
        {
            System.out.print(Arr[iCnt] + "\t");
        }

        System.out.println();
    }

    // Check if array is sorted
    public boolean CheckSorted()
    {
        boolean bFlag = true;

        for(int i = 0; i < iSize - 1; i++)
        {
            if(Arr[i] > Arr[i + 1])
            {
                bFlag = false;
                break;
            }
        }

        return bFlag;
    }

    // Bubble Sort
    public void BubbleSort()
    {
        int temp = 0;

        for(int i = 0; i < iSize - 1; i++)
        {
            for(int j = 0; j < iSize - 1 - i; j++)
            {
                if(Arr[j] > Arr[j + 1])
                {
                    temp = Arr[j];
                    Arr[j] = Arr[j + 1];
                    Arr[j + 1] = temp;
                }
            }
        }

        Sorted = true;
    }
}

public class Program01
{
    public static void main(String[] args)
    {
        Scanner sobj = new Scanner(System.in);

        int iValue = 0;

        System.out.println("Enter the number of elements : ");
        iValue = sobj.nextInt();

        ArrayX aobj = new ArrayX(iValue);

        aobj.Accept();

        System.out.println("\nData Before Sorting :-");
        aobj.Display();

        if(aobj.Sorted == true)
        {
            System.out.println("\nData is sorted.");
        }
        else
        {
            System.out.println("\nData is not sorted.");
        }

        aobj.BubbleSort();

        System.out.println("\nData After Sorting :-");
        aobj.Display();
    }
}