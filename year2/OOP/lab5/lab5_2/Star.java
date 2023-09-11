package year2.OOP.lab5.lab5_2;

import java.util.ArrayList;

public class Star {
    public static ArrayList<String> addStar(ArrayList<String> C) {
        ArrayList<String> addStarArray = new ArrayList<String>();
        for (int i = 0; i < C.size(); i++) {
            String str = C.get(i);
            addStarArray.add(str);
            if (!C.get(i).equals("*")) {
                addStarArray.add("*");
            }
        }
        return addStarArray;
    }

    public static void removeStar(ArrayList<String> C) {
        for (int i = 0; i < C.size(); i++) {
            if (C.get(i).equals("*")) {
                C.remove(i--);
            }
        }
    }

    public static void print(ArrayList<String> c) {
        System.out.print("[");
        for (int i = 0; i < c.size(); i++) {
            System.out.print(c.get(i));
            if (i != c.size() - 1) {
                System.out.print(",");
            }
        }
        System.out.print("]");
        System.out.println();
    }
}
