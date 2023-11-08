package entity;

import java.awt.*;
import java.awt.image.BufferedImage;

public class Entity {
    public int x,y,speed;

    public BufferedImage red,blue,green,orange,purple,sky,yellow,white;
    public String color;
    public String direction;
    public Rectangle solidArea;
    public int solidAreaDefaultX,solidAreaDefaultY;
    public boolean collisionOn = false;
}
