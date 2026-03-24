import java.util.Scanner;

class Check
{
    public void CheckEvenOdd(int iNo)
    {
        if(iNo % 2 == 0)
        {
            System.out.println(iNo + " is Even number");
        }
        else
        {
            System.out.println(iNo + " is Odd number");
        }
    }
}

public class Program01 
{
    public static void main(String A[])
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the number : ");
        int iValue = sobj.nextInt();

        Check cobj = new Check();

        cobj.CheckEvenOdd(iValue);

        sobj.close();
    }
}
