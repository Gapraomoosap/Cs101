import java.util.Scanner;

public class lab6 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int y = sc.nextInt();
        for(int i = 1 ; i <= x ; i++){
            for(int j = 1 ; j <= y ; j++){
                if(i*j == 1)
                {System.out.print(" ");}
                else{
                    System.out.print((i*j)+" ");
                }
            }
            System.out.println("");
        }
    }
}
