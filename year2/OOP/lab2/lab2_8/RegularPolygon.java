package year2.OOP.lab2.lab2_8;
public class RegularPolygon {
    private int n;
    private  double side;
    private  double x,y;
    public RegularPolygon(){
        this.n = 3;
        this.side = 1;
        this.x = 0;
        this.y = 0;
    }
    public RegularPolygon(int number,double length){
        this.n = number;
        this.side = length;
        this.x = 0;
        this.y = 0;
    }
    public RegularPolygon(int number,double length,double x,double y)
    {
        this.n = number;
        this.side = length;
        this.x = x;
        this.y = y;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public double getSide() {
        return side;
    }
    public double getN(){
        return n;
    }

    public void setN(int n){
        this.n = n;
    }

    public void setSide(double side) {
        this.side = side;
    }

    public void setX(double x) {
        this.x = x;
    }

    public void setY(double y) {
        this.y = y;
    }
    public double getPerimeter(){
        return n * side;
    }
    public double getArea() {
        double pi = Math.PI;
        return (n * side * side) / (4 * Math.tan(pi / n));

    }

}

