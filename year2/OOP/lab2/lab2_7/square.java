package year2.OOP.lab2.lab2_7;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class square {
    private double x,y,w,h;
    public square(){
        System.out.println("Create obj complete!!");
    }
    public square(double x,double y,double w,double h) {
        this.x = x;
        this.y = y;
        this.w = w;
        this.h = h;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public double top(){
        return y + h/2;
    }
    public double left(){
        return x - w/2;
    }

    public double right(){
        return x + w/2;
    }

    public double bottom(){
        return y - h/2;
    }


}
