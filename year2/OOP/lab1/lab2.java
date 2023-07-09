package Cs101.year2.OOP.lab1;

import java.util.Scanner;

public class lab2 {
    public static void main(String[] args){

        Scanner input = new Scanner(System.in);
        System.out.print("Enter the month saving amount : ");
        double x = input.nextDouble();
        double profit;
        profit = x * (1 + 0.00417);
        for(int i = 0 ; i < 5 ;i++)
        {
            profit = (x + profit) * (1+0.00417);
        }
        System.out.printf("After the sixth month, the account value is $%.2f",profit);
        input.close();
}
}
