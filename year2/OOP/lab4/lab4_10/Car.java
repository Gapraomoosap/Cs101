package year2.OOP.lab4.lab4_10;

import java.util.Scanner;

public class Car {
    int m, start, t;
    int[][] road;
    int[] way;
    Scanner SC = new Scanner(System.in);

    void Insert() {
        for (int i = 0; i < t; i++) {
            for (int j = 0; j < m; j++) {
                road[i][j] = SC.nextInt();
            }
        }
    }

    void Findway() {
        int s = start;
        int status = 0;
        for (int f = 0; f < road[0].length; f++) {
            if (road[road.length - 1][f] == 0) {
                for (int i = 0; i < road.length; i++) {
                    status = 0;
                    if (f < start) {
                        if (start - 1 >= 0 && road[i][start - 1] == 0) {
                            System.out.println("1");
                            start = start - 1;
                        } else if (road[i][start] == 0) {
                            System.out.println("3");
                        } else if (start + 1 <= road[0].length - 1 && road[i][start + 1] == 0) {
                            System.out.println("2");
                            start = start + 1;
                        } else {
                            System.out.println("No way to finish");
                            break;
                        }
                    } else if (f > start) {
                        if (start + 1 <= road[0].length - 1 && road[i][start + 1] == 0) {
                            System.out.println("2");
                            start = start + 1;
                        } else if (road[i][start] == 0) {
                            System.out.println("3");
                        } else if (start - 1 >= 0 && road[i][start - 1] == 0) {
                            System.out.println("1");
                            start = start - 1;
                        } else {
                            System.out.println("No way to finish");
                            break;
                        }
                    } else if (f == start) {
                        if (road[i][start] == 0) {
                            System.out.println("3");
                        } else if (start - 1 >= 0 && road[i][start - 1] == 0) {
                            System.out.println("1");
                            start = start - 1;
                        } else if (start + 1 <= road[0].length - 1 && road[i][start + 1] == 0) {
                            System.out.println("2");
                            start = start + 1;
                        } else {
                            System.out.println("No way to finish");
                            break;
                        }
                    }
                    status = 1;
                }
                start = s;
                if (status == 1) {
                    break;
                }
            }
        }
    }

    Car(int n, int s, int m) {
        this.m = n;
        this.t = m;
        this.road = new int[this.t][this.m];
        this.way = new int[t];
        this.start = s - 1;
        this.Insert();
        this.Findway();
    }
}
