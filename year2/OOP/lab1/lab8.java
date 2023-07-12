import java.util.Scanner;
import java.lang.Math;

public class lab8 {
    public static void main(String[] args)
    {
        int[] array = new int[10] ;
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        array[0] = sc.nextInt();
        array[1] = sc.nextInt();
        for(int i = 0 ; i <= n ; i++)
        {
            if(i == 0 ){System.out.print(array[i]+" ");}
            else if(i == 1){System.out.print(array[i]+" ");}
            else{
                array[i] = (int) (Math.pow(i,2) * array[i-1] - array[i-2] + Math.pow(3,i));
                System.out.print(array[i]+ " ");
            }
        }
    }
    
}
