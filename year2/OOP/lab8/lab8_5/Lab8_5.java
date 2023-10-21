package year2.OOP.lab8.lab8_5;

public class Lab8_5 {
    public static void main(String[] args) {
        Octagon octagon = new Octagon(5);
        Octagon octagon2 = (Octagon) octagon.clone();
        System.out.println(octagon.equals(octagon2));
        ComparableCircle c1 = new ComparableCircle(5);
        ComparableCircle c2 = new ComparableCircle(10);
        System.out.println(c1.compareTo(c2));
    }
}
abstract class GeometricObject{
    private String color = "white";
    private boolean filled;
    protected GeometricObject(){

    }
    protected GeometricObject(String color, boolean filled) {
        this.color = color;
        this.filled = filled;
    }
    public String getColor() {
        return color;
    }
    public void setColor(String color) {
        this.color = color;
    }
    public boolean isFilled() {
        return filled;
    }
    public void setFilled(boolean filled) {
        this.filled = filled;
    }
    public abstract double getArea();
    public abstract double getPerimeter();

}
interface Comparable{
    abstract public boolean equals(Object o);
    abstract public int compareTo(Object o);
}

interface Cloneable{
    abstract public Object clone();
}

class Circle extends GeometricObject implements Comparable,Cloneable{
    private double r;
    public Circle(double r){
        this.r = r;
    }
    public int compareTo(Object o){
        if (equals(o)){
            return 1;
        }
        return 0;
    }
    public boolean equals(Object o){
        if(o instanceof Circle){
            return this.r == (((Circle)o).r);
        }
        return false;
    }
    public double getArea(){
        return Math.pow(r, 2)*Math.PI;
    }
    public double getPerimeter(){
        return 2*Math.PI*r;
    }
    public Object clone(){
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            return null;
        }
    }
}
class Rectangle extends GeometricObject implements Comparable,Cloneable{
    private double width,height;
    public Rectangle(double width, double height){
        this.width = width;
        this.height = height;
    }
    public int compareTo(Object o){
        if (equals(o)){
            return 1;
        }
        return 0;
    }
    public boolean equals(Object o){
        if(o instanceof Rectangle){
            return getArea() == ((Rectangle)o).getArea();
        }
        return false;
    }
    public double getArea(){
        return width*height;
    }
    public double getPerimeter(){
        return 2*width+2*height;
    }
    public Object clone(){
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            return null;
        }
    }
}
class Octagon extends GeometricObject implements Comparable,Cloneable{
    private double side;
    public Octagon(double side){
        this.side = side;
    }
    public int compareTo(Object o){
        if (equals(o)){
            return 1;
        }
        return 0;
    }
    public boolean equals(Object o){
        if(o instanceof Octagon){
            return getArea() == ((Octagon)o).getArea();
        }
        return false;
    }
    public double getArea(){
        return (2+4/Math.sqrt(2))*side*side;
    }
    public double getPerimeter(){
        return side*8;
    } 
    public Object clone(){
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            return null;
        }
    }
}
class ComparableCircle extends Circle{

    public ComparableCircle(double r) {
        super(r);
    }

    @Override
    public int compareTo(Object o) {
        if(((Circle)o).getArea() > this.getArea()){
            return 0;
        }
        return 1;
    }
}