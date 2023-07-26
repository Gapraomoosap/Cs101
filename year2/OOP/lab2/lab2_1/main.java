package year2.OOP.lab2.lab2_1;
public class main {

    public static void main(String args[]) {
        Complex a = new Complex(1.0, 2.0);
        Complex b = new Complex(3.0, 4.0);
        Complex c = new Complex(a);
        c.add(b);
        c.print();
        c.setR(1);
        c.setI(2);
        
        c.sub(b);
        c.print();
        c.setR(1);
        c.setI(2);
        
        c.multiply(b);
        c.print();
        c.setR(1);
        c.setI(2);
        
        c.divide(b);
        c.print();
        
    }
}
