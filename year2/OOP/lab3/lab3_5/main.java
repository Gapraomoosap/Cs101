package year2.OOP.lab3.lab3_5;
import java.util.Scanner;
public class main {
    public static void main(String[] args) {
        Scanner obj = new Scanner(System.in);
        int number = obj.nextInt();
        int round = obj.nextInt();
        RoachPopulation roach1 = new RoachPopulation(number);
        for(int i = 0;i < round ; i++){
            roach1.Wait();
            roach1.spray();
        }
        System.out.println(roach1.getRoaches());

    }
}