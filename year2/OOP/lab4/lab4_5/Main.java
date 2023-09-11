package year2.OOP.lab4.lab4_5;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // manual input
        System.out.println("Input A rows : ");
        int n = sc.nextInt();
        System.out.println("Input A colums : ");
        int l = sc.nextInt();
        int[][] A = new int[n][l];
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < A[0].length; j++) {
                A[i][j] = sc.nextInt();
            }
        }
        System.out.println("Input B rows : ");
        int n2 = sc.nextInt();
        System.out.println("Input B colums : ");
        int m = sc.nextInt();
        int[][] B = new int[l][m];
        for (int i = 0; i < B.length; i++) {
            for (int j = 0; j < B[0].length; j++) {
                B[i][j] = sc.nextInt();
            }
        }
        int c[][] = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                c[i][j] = 0;
                for (int k = 0; k < l; k++) {
                    c[i][j] += A[i][k] * B[k][j];
                }
                System.out.print(c[i][j] + " ");
            }
            System.out.println();
        }

    }

}
