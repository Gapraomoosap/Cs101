import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        method Method = new method();
        Scanner SC = new Scanner(System.in);
        int n = SC.nextInt();
        int m = SC.nextInt();
        int[][] arr = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = SC.nextInt();
            }
        }
        if (Method.isConsecutiveFour(arr)) {
            System.out.println("1");
        } else {
            System.out.println("0");
        }
    }
}