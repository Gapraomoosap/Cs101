package year2.OOP.lab4.lab4_8;

import java.util.Scanner;

public class FindPokemon {
    int[][] A;
    int n, m;
    Scanner SC = new Scanner(System.in);

    public void creat() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                A[i][j] = SC.nextInt();
            }
        }
    }

    public void Find() {
        int r = 0, c = 0, p = -1, sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j + 1 < m && Math.abs(A[i][j] - A[i][j + 1]) <= 10 && A[i][j] + A[i][j + 1] > sum) {
                    sum = A[i][j] + A[i][j + 1];
                    if (A[i][j + 1] > A[i][j]) {
                        r = i;
                        c = j + 1;
                    } else {
                        r = i;
                        c = j;
                    }
                }
                if (i + 1 < n && Math.abs(A[i][j] - A[i + 1][j]) <= 10 && A[i][j] + A[i + 1][j] > p) {
                    p = A[i][j] + A[i + 1][j];
                    if (A[i + 1][j] > A[i][j]) {
                        r = i + 1;
                        c = j;
                    } else {
                        r = i;
                        c = j;
                    }
                }
            }
        }
        System.out.println((r + 1) + " " + (c + 1));
    }

    FindPokemon(int n, int m) {
        this.n = n;
        this.m = m;
        A = new int[n][m];
    }
}