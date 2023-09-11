package year2.OOP.lab4.lab4_6;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int n;
        double x1, y1, sum = 0;
        double min = 100;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        double[] x = new double[n];
        double[] y = new double[n];

        for (int i = 0; i < n; i++) {
            x1 = sc.nextDouble();
            x[i] = x1;
            y1 = sc.nextDouble();
            y[i] = y1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    sum = Math.sqrt(Math.pow((x[i] - x[j]), 2) + Math.pow((y[i] - y[j]), 2));
                    if (min > sum) {
                        min = sum;
                    }
                }
            }
        }
        System.out.printf("Ans : %.2f", min);
    }
}
