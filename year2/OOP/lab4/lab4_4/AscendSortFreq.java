package year2.OOP.lab4.lab4_4;

import java.util.Scanner;

public class AscendSortFreq {
    public double[] A;

    public void creatArr() {
        Scanner SC = new Scanner(System.in);
        for (int i = 0; i < A.length; i++) {
            A[i] = SC.nextDouble();
        }
    }

    public double[] AscendSort(double[] A) {
        double[] B = A.clone();
        for (int i = 0; i < B.length; i++) {
            for (int j = i + 1; j < B.length; j++) {
                if (B[i] > B[j]) {
                    double temp = B[i];
                    B[i] = B[j];
                    B[j] = temp;
                }
            }
        }
        return B;
    }

    public void print(double[] c) {
        for (int i = 0; i < c.length; i++) {
            System.out.print((int) c[i] + " ");
        }
        System.out.println();
    }

    public double[] SortCommuFreq(double[] B) {
        int count = 1, counti = 1;
        for (int i = 0; i < B.length - 1; i++) {
            if (B[i] != B[i + 1]) {
                counti++;
            }
        }
        double[] C = new double[counti];
        int n = 0;
        int i;
        for (i = 0; i < B.length - 1; i++) {
            if (B[i] != B[i + 1]) {
                C[n++] = i + 1;
            }
        }
        if (i + 1 >= B.length) {
            C[n++] = i + 1;
        }
        return C;
    }

    AscendSortFreq(int n) {
        this.A = new double[n];
    }
}