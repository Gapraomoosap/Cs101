package year2.OOP.lab2.lab2_1;
public class Complex {

    private double r, i;

    Complex(double r, double i) {
        this.r = r;
        this.i = i;
    }

    Complex(Complex c) {
        this(c.r, c.i);
    }

    public void setR(double r) {
        this.r = r;
    }

    public void setI(double i) {
        this.i = i;
    }

    public void add(Complex c) {
        r += c.r;
        i += c.i;
    }

    public void sub(Complex c) {
        r -= c.r;
        i -= c.i;
    }

    public void multiply(Complex c) {
        double r2 = r;
        r = (r * c.r) - (i * c.i);
        i = (r2 * c.i) + (i * c.r);
    }

    public void divide(Complex c) {
        double r2 = r;
        r = ((r * c.r) - (i * c.i)) / ((c.r * c.r) + (c.i * c.i));
        i = ((i * c.r) - (r2 * c.i)) / ((c.r * c.r) + (c.i * c.i));
    }

    public void print() {
        System.out.println(String.format("%.2f + i%.2f",r,i));
    }

}
