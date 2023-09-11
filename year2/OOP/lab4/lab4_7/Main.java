package year2.OOP.lab4.lab4_7;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner SC = new Scanner(System.in);
        minTwoSet min = new minTwoSet(SC.nextInt());
        System.out.println(min.mintoset());
    }
}
