import java.util.Scanner;

public class lab4{
    public static void main(String[] args)
    {
        
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter balance and interest rate :");
        double balance , annbalance , interest;
        balance = sc.nextDouble();
        annbalance = sc.nextDouble();
        interest = balance * (annbalance / 1200);
        System.out.printf("The interest is %.5f",interest);
        sc.close();
    }
}