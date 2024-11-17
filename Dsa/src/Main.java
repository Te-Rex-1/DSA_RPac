import java.util.Scanner;

public class Main {
long fact(int n)
{
    int fact=1;
    for (int i = 0; i <n ; i++) {
        fact*=(i+1);
    }
    return fact;
}
public int permutation(int no , int no_Space)
{
    int perm=1;
    if((Integer.toString(no)).length()>=no_Space)
    {
        for (int i = 0; i < no_Space; i++) {
            perm*=fact(no);
        }
    }
    return perm;
}

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        Main ob=new Main();

        System.out.println("Enter no");
        int n=in.nextInt();
        int space=in.nextInt();
        System.out.println("No of combination is "+ob.permutation(n,space));

    }
}

class Solution {
    boolean check_Sum(int lower,int upper,int sum)
    {
        if (lower<=sum&&upper>=sum)
            return true;
        else
            return false;
    }

}

