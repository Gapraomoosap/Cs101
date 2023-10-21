package year2.OOP.lab6.lab6_7;

public class MyRectangle2D {
    double x,y;
    double width,height;
    public MyRectangle2D(){
        this.x = 0;
        this.y = 0;
        this.width = 1;
        this.height = 1;
    }
    public MyRectangle2D(double x,double y,double w,double h){
        this.x = x;
        this.y = y;
        this.width = w;
        this.height = h;
    }
    void setX(double x)
    {
        this.x = x;
    }
    void setY(double y)
    {
        this.y = y;
    }
    void setWidth(double w)
    {
        this.width = w;
    }
    void setHeight(double h)
    {
        this.height = h;
    }
    double getX()
    {
        return this.x;
    }
    double getY()
    {
        return this.y;
    }
    double getWidth()
    {
        return this.width;
    }
    double getHeight()
    {
        return this.height;
    }
    double getArea(){
        return this.height * this.width;
    }
    double getPerimeter(){
        return (2*this.width) + (2*this.height);
    }
    boolean contains(double x,double y){
        double max_x,max_y,min_x,min_y;
        max_x = this.x+(this.width/2);
        max_y = this.y+(this.height/2);
        min_y = this.y-(this.height/2);
        min_x = this.x-(this.width/2);
        return ((x >= min_x) && (x <= max_x)) && ((y >= min_y) && (y <= min_y));
    }
    boolean contains(MyRectangle2D r){
        double max_x,max_y,min_x,min_y;
        double Rmax_x,Rmax_y,Rmin_x,Rmin_y;
        max_x = this.x+(this.width/2);
        max_y = this.y+(this.height/2);
        min_y = this.y-(this.height/2);
        min_x = this.x-(this.width/2);
        Rmax_x = r.x+(r.width/2);
        Rmax_y = r.y+(r.height/2);
        Rmin_y = r.y-(r.height/2);
        Rmin_x = r.x-(r.width/2);

        return (max_x >= Rmax_x) && (min_x <= Rmin_x) && (max_y >= Rmax_y) && (min_y <= Rmin_y);
    }
    boolean overlaps(MyRectangle2D r) {
        double max_x = this.x + (this.width / 2);
        double max_y = this.y + (this.height / 2);
        double min_y = this.y - (this.height / 2);
        double min_x = this.x - (this.width / 2);

        double Rmax_x = r.x + (r.width / 2);
        double Rmax_y = r.y + (r.height / 2);
        double Rmin_y = r.y - (r.height / 2);
        double Rmin_x = r.x - (r.width / 2);

        // Check for partial overlap condition
        return (max_x > Rmin_x && min_x < Rmax_x && max_y > Rmin_y && min_y < Rmax_y) &&
                !(max_x == Rmax_x && min_x == Rmin_x && max_y == Rmax_y && min_y == Rmin_y);
    }
    public static void main(String[] args)
    {
        
    }

}
