package year2.OOP.lab3.lab3_8;
import java.util.Scanner;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Pi obj = new Pi();
        double ans = obj.m(sc.nextInt());
        System.out.printf("%.4f",ans);

    }
}