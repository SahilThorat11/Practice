
import java.util.Scanner;

class Solution
{
    public int CountEven(int iNo)
    {
        int iCnt = 0, iFrequency = 0;

        for(iCnt = 1; iCnt <= iNo; iCnt++)
        {
            if(iCnt % 2 == 0)
            {
                iFrequency++;
            }
        }

        return iFrequency;
    }
}

class Program02
{
    public static void main(String A[])
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the number : ");
        int iValue = sobj.nextInt();

        Solution obj = new Solution();

        int iRet = obj.CountEven(iValue);

        System.out.println("Frequency of even number is : " + iRet);

        sobj.close();
    }
}