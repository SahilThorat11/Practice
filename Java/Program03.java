
// Input  : 6
// Output : 1   *   2   *   3   *
//          1   2   3   4   5   6


import java.util.Scanner;

class Solution
{
    public void Display(int iNo)
    {
        int i = 0;

        for(i = 1; i <= iNo/2; i++)
        {
            System.out.print(i + "\t*\t");
        }
    }
}

class Program03
{
    public static void main(String A[])
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the number : ");
        int iValue = sobj.nextInt();

        Solution obj = new Solution();

        obj.Display(iValue);

        sobj.close();
    }
}