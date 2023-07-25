import java.util.Scanner;
import java.lang.Math;
public class lab7 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int n = sc.nextInt();
        int total = 0;
        for(int i = 0 ; i <= n ; i++){
            total = (int)(total + Math.pow(x,i));
        }
        System.out.println(total);
        sc.close();
    }
}
