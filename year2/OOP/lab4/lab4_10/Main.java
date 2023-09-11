package year2.OOP.lab4.lab4_10;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner SC = new Scanner(System.in);
        int n = SC.nextInt(), s = SC.nextInt(), m = SC.nextInt();
        Car c = new Car(n, s, m);
    }
}
