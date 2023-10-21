package year2.OOP.lab9.lab9_9;
import java.util.*;

public class Lab9_9 {
    public static int[] remove(int[] arr, int index) { 
        if (arr == null|| index < 0|| index >= arr.length) { 
            return arr; 
        } 
        int[] anotherArray = new int[arr.length - 1]; 
        for (int i = 0, k = 0; i < arr.length; i++) { 
            if (i == index) { 
                continue; 
            } 
            anotherArray[k++] = arr[i]; 
        } 
        return anotherArray; 
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int[] n = new int[N]; 
        for(int i=0;i<N;i++){
            n[i] = in.nextInt();
        }
        int sum=0;
        int del=0; 
        while(n.length>1){
            int max=0;
            for(int i=1;i<n.length;i++){
                if(Math.sqrt(Math.pow(n[i-1]-n[i], 2))>max){
                    del=i-1;
                    max = (int) Math.sqrt(Math.pow(n[i-1]-n[i], 2));
                }
            }
            n=remove(n,del);
            n=remove(n,del);
            sum+=max;
        } 
        System.out.println(sum);
    } 
}
