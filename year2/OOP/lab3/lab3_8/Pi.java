package year2.OOP.lab3.lab3_8;
import java.lang.Math;

public class Pi {
    public double m(int n)
    {
        double sum = 0;
        for(int i = 1;i<=n;i++){
            sum = sum + (Math.pow((-1),i+1)/(2*i-1));
        }
        return sum*4;
    }
}
