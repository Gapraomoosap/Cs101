package year2.OOP.lab3.lab3_7;
import java.util.Scanner;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Mytriangle obj = new Mytriangle();
        int side1,side2,side3;
        side1 = sc.nextInt();
        side2 = sc.nextInt();
        side3 = sc.nextInt();
        if(obj.isValid(side1,side2,side3)) {
            System.out.printf("%.2f", (obj.area(side1, side2, side3)));
        } else
        {
            System.out.println();
        }
    }
}