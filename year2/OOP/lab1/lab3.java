package Cs101.year2.OOP.lab1;
import java.lang.Math;
import java.util.Scanner;
public class lab3 {
    public static void main(String[] args) {
        System.out.print("Enter three points for a triangle : ");
        Scanner myobs = new Scanner(System.in);
        double[] array = new double[10];
        for(int i = 0 ; i < 6 ; i++)
        {
            array[i] = myobs.nextDouble();
        }
        double side1 = Math.sqrt(Math.pow((array[0]-array[2]),2)+Math.pow((array[1]-array[3]),2));
        double side2 = Math.sqrt(Math.pow((array[0]-array[4]),2)+Math.pow((array[1]-array[5]),2));
        double side3 = Math.sqrt(Math.pow((array[2]-array[4]),2)+Math.pow((array[3]-array[5]),2));
        double s = (side1 + side2 + side3 ) / 2;
        double area = Math.sqrt(s * (s - side1) * (s - side2 ) * (s - side3));
        System.out.printf("\nThe area of the triangle is %.2f",area);



    }
}
