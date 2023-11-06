package entity;

import java.awt.*;
import java.awt.image.BufferedImage;

public class Entity {
    public int x,y,speed;

    public BufferedImage red,blue,green;
    public String color;
    public String direction;

    public Rectangle solidArea;
    public boolean collisionOn = false;
}
