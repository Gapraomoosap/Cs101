import java.util.Scanner;

public class lab9 {
    public static void main(String[] args){
        int[] array = new int[100];
        int i =0,max=0,count=0;
        Scanner sc = new Scanner(System.in);
        while(true){
            array[i] = sc.nextInt();
            if(array[i] == 0)
            {
                break;
            }
            if(array[i] > max){
                max = array[i];
            }
            else if(array[i] == max){
                count++;
            }
            i++;
        }
        System.out.println(max+ " "+ count);
        
    }
    
}
