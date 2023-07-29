package year2.OOP.lab2.lab2_8;

public class main {
    public static void main(String[] args) {
        RegularPolygon polygon = new RegularPolygon();
        RegularPolygon polygon1 = new RegularPolygon(6,4);
        RegularPolygon polygon2 = new RegularPolygon(10,4,5.6,7.8);
        System.out.println(String.format("Polygon1 Perimeter = %.2f Area = %.2f ",polygon.getPerimeter(),polygon.getArea()));
        System.out.println(String.format("Polygon2 Perimeter = %.2f Area = %.2f ",polygon1.getPerimeter(),polygon1.getArea()));
        System.out.println(String.format("Polygon3 Perimeter = %.2f Area = %.2f ",polygon2.getPerimeter(),polygon2.getArea()));

    }
    
}
