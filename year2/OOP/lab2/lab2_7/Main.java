package year2.OOP.lab2.lab2_7;

import java.util.Scanner;


import static java.lang.Math.pow;
import static java.lang.Math.sqrt;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double X1,Y1,W1,H1,X2,Y2,W2,H2;
        System.out.print("Enter r1's center x-, y-coordinates, width, and height : ");
        X1 = sc.nextDouble();
        Y1 = sc.nextDouble();
        W1 = sc.nextDouble();
        H1 = sc.nextDouble();
        System.out.print("Enter r1's center x-, y-coordinates, width, and height : ");
        X2 = sc.nextDouble();
        Y2 = sc.nextDouble();
        W2 = sc.nextDouble();
        H2 = sc.nextDouble();
        square s1 = new square(X1,Y1,W1,H1);
        square s2 = new square(X2,Y2,W2,H2);

        // Check if r2 is inside r1
        if (s1.top() >= s2.top() && s1.left() <= s2.left() && s1.right() >= s2.right() && s1.bottom() <= s2.bottom()) {
            System.out.println("r2 is inside r1");
        }
// Check if r2 overlaps with r1
        else if (s1.top() >= s2.bottom() && s1.bottom() <= s2.top() && s1.left() <= s2.right() && s1.right() >= s2.left()) {
            System.out.println("r2 is overlapping r1");
        }
// If not inside or overlapping, r2 is outside r1
        else {
            System.out.println("r2 is outside r1");
        }

    }

}