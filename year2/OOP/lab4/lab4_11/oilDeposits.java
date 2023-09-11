package year2.OOP.lab4.lab4_11;

import java.util.Scanner;

public class oilDeposits {
    char[][] Deposits;
    int m, n, count = 0, status = 0;
    Scanner SC = new Scanner(System.in);

    void Insert() {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                Deposits[i][j] = SC.next().charAt(0);
            }
        }
    }

    void print() {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(Deposits[i][j] + " ");
            }
            System.out.println();
        }
    }

    int check(int m1, int n1) {
        int c = 0;
        for (int i = m1 - 1; i <= m1; i++) {
            for (int j = n1 - 1; j <= n1; j++) {
                if (i >= 0 && i < Deposits.length && j >= 0 && j < Deposits[0].length) {
                    if (i != m1 || j != n1) {
                        if (Deposits[i][j] == '@') {
                            c++;
                        }
                    }
                    if (i >= 0 && i < Deposits.length && j + 1 >= 0 && j + 1 < Deposits[0].length) {
                        if (i == m1 - 1 && j == n1) {
                            if (Deposits[i][j + 1] == '@') {
                                c++;
                            }
                        }
                    }
                }
            }
        }
        return c;
    }

    void count() {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (Deposits[i][j] == '@') {
                    if (check(i, j) == 0) {
                        count++;
                    }
                }
            }
        }
        System.out.println(count);
    }

    oilDeposits(int m, int n) {
        this.m = m;
        this.n = n;
        this.Deposits = new char[this.m][this.n];
        this.Insert();
        this.count();
    }

}
