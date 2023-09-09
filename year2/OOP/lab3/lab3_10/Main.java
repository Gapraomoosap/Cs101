package year2.OOP.lab3.lab3_10;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        int count =0;
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] Point = new int[n*2];
        int[] light =new int[m];
        for(int i =0 ;i < n*2;i++)
        {
            Point[i] = sc.nextInt();
        }
        for(int j =0 ;j < m;j++)
        {
            light[j] = sc.nextInt();
        }

        for(int i =0 ;i<m;i++) {
            for (int j = 0; j < n; j++)
            {

               if(Point[j*2] < light[i] && Point[j*2+1] > light[i])
               {
                   count++;
               }
            }
        }
        System.out.println(count);


    }
}