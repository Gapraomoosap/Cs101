package year2.OOP.lab8.lab8_6;

public class Lab8_6 {
    public static void main(String[] args) {
        
    }
}

interface Movable{
    public void moveUp();
    public void moveDown();
    public void MoveLeft();
    public void MoveRight();
}

class MovableCircle implements Movable{
    private int radius;
    private MovablePoint center;
    public MovableCircle(int x, int y, int xSpeed, int ySpeed, int radius){
        this.center = new MovablePoint(x, y, xSpeed, ySpeed);
        this.radius = radius;
    }
    @Override
    public String toString(){
        return "";
    }
    @Override
    public void moveUp(){

    }
    @Override
    public void moveDown(){

    }
    @Override
    public void MoveLeft(){

    }
    @Override
    public void MoveRight(){

    }
}

class MovablePoint implements Movable{
    int x;
    int y;
    int xSpeed;
    int ySpeed;
    public MovablePoint(int x, int y, int xSpeed, int ySpeed){
        this.x = x;
        this.y = y;
        this.xSpeed = xSpeed;
        this.ySpeed = ySpeed;
    }
    @Override
    public String toString(){
        return "";
    }
    @Override
    public void moveUp(){

    }
    @Override
    public void moveDown(){

    }
    @Override
    public void MoveLeft(){

    }
    @Override
    public void MoveRight(){

    }

}