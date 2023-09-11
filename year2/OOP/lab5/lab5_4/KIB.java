package year2.OOP.lab5.lab5_4;

import java.util.Scanner;

public class KIB {
    int m, width, t;
    int[][] area;
    Scanner SC = new Scanner(System.in);
    int max = -1, sum;

    void Insert() {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < t; j++) {
                area[i][j] = SC.nextInt();
            }
        }
    }

    void fineArea() {
        for (int i = 0; i < m - width + 1; i++) {
            for (int j = 0; j < t - width + 1; j++) {
                sum = 0;
                for (int k = i; k < i + width; k++) {
                    for (int l = j; l < j + width; l++) {
                        sum += area[k][l];
                    }
                }
                if (sum > max) {
                    max = sum;
                }
            }
        }
        System.out.println(max);
    }

    KIB(int i, int j, int w) {
        this.m = i;
        this.t = j;
        this.width = w;
        this.area = new int[m][t];
        Insert();
        fineArea();
    }
}
