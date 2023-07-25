package year2.OOP.lab2.lab2_1;

public class main {
    class ComplexTest {
        public static void main(String args[]) {
            Complex a = new Complex(1.0, 2.0);
            Complex b = new Complex(3.0, 4.0);
            Complex c = new Complex(a);
            // c.add(b);
            c.minus(c);
            c.print();
        }
    }
}
