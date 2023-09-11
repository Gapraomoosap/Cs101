package year2.OOP.lab4.lab4_7;

import java.util.Scanner;

public class minTwoSet {
    public int[] A;

    public void creatArr() {
        Scanner SC = new Scanner(System.in);
        for (int i = 0; i < A.length; i++) {
            A[i] = SC.nextInt();
        }
    }

    public void AscendSort() {
        for (int i = 0; i < A.length; i++) {
            for (int j = i + 1; j < A.length; j++) {
                if (A[i] > A[j]) {
                    int temp = A[i];
                    A[i] = A[j];
                    A[j] = temp;
                }
            }
        }
    }

    public int mintoset() {
        int min = -1, wi, wj, sum;
        for (int i = 0; i < A.length; i++) {
            wi = A[A.length - 1];
            for (int j = 0; j < i; j++) {
                wi += A[j];
            }
            wj = 0;
            for (int j = i; j < A.length - 1; j++) {
                wj += A[j];
            }
            sum = Math.abs(wi - wj);
            if (sum < min || min == -1) {
                min = sum;
            }
        }
        return min;
    }

    public void print(int[] c) {
        for (int i = 0; i < c.length; i++) {
            System.out.print((int) c[i] + " ");
        }
        System.out.println();
    }

    minTwoSet(int n) {
        this.A = new int[n];
        creatArr();
        AscendSort();
    }
}
