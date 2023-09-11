package year2.OOP.lab4.lab4_8;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner SC = new Scanner(System.in);
        int n = SC.nextInt(), m = SC.nextInt();
        FindPokemon FP = new FindPokemon(n, m);
        FP.creat();
        FP.Find();
    }
}
