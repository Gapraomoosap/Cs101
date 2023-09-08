package year2.OOP.lab3.lab3_7;
import static java.lang.Math.sqrt;

public class Mytriangle {


    public boolean isValid(double side1,double side2,double side3){
        return (side1 + side2) > side3;
    }
    public double area(double side1,double side2,double side3)
    {
        double s = (side1 + side2 + side3)/2;
        double area = sqrt(s*(s - side1)*(s - side2)*(s - side3));
        return area;
    }
}
