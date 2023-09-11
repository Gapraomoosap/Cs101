package year2.OOP.lab4.lab4_4;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner SC = new Scanner(System.in);
        AscendSortFreq arr = new AscendSortFreq(SC.nextInt());
        arr.creatArr();
        double[] B;
        B = arr.AscendSort(arr.A);
        for (int i = 0; i < B.length; i++) {
            if (i - 1 >= 0 && B[i] != B[i - 1] || i == 0) {
                System.out.print((int) B[i] + " ");
            }
        }
        System.out.println();
        double[] C = arr.SortCommuFreq(B);
        arr.print(C);
    }
}