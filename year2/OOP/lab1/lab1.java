import java.util.Scanner;

public class lab1 {
    public static void main(String[] args){
        Scanner myObj = new Scanner(System.in);
        System.out.print("Enter fahrenheit : ");
        double Fahrenheit = myObj.nextDouble();
        double Celsius = (5.0/9.0)*(Fahrenheit-32);
        System.out.printf("Temperature in Celsius : %.2f" ,Celsius );
        myObj.close();
    }
    
}
