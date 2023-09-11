package year2.OOP.lab5.lab5_3;

import java.util.ArrayList;
import java.util.Scanner;

public class SortMergeList {
    public static void Insert(ArrayList<Integer> intarr) {
        Scanner SC = new Scanner(System.in);
        int x;
        do {
            x = SC.nextInt();
            if (x != 0) {
                intarr.add(x);
            }
        } while (x != 0);
    }

    public static ArrayList<Integer> Intersec(ArrayList<Integer> intArray1, ArrayList<Integer> intArray2) {
        ArrayList<Integer> containArr = new ArrayList<Integer>();
        for (int Int : intArray1) {
            if (intArray2.contains(Int)) {
                containArr.add(Int);
            }
        }
        return containArr;
    }

    public static void print(ArrayList<Integer> c) {
        for (int i = 0; i < c.size(); i++) {
            System.out.print(c.get(i));
            if (i != c.size() - 1) {
                System.out.print(" ");
            }
        }
        System.out.println();
    }
}
