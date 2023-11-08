package Object;

import main.GamePanel;

import java.awt.*;
import java.awt.image.BufferedImage;

public class SuperObject {
    public BufferedImage image;
    public String name;
    public boolean collision = false;
    public int worldX,worldY;
    public Rectangle solidArea = new Rectangle(0,0,48,48);
    public int solidAreaDefaultX = 0;
    public int solidAreaDefaultY = 0;

    public void draw(Graphics2D g2, GamePanel gp){
        int screenX = worldX - gp.player.x + gp.player.screenX;
        int screenY = worldY - gp.player.y + gp.player.screenY;

        if(worldX + gp.titalSize > gp.player.x - gp.player.screenX &&
                worldX - gp.titalSize < gp.player.x + gp.player.screenX &&
                worldY + gp.titalSize > gp.player.y - gp.player.screenY &&
                worldY - gp.titalSize < gp.player.y + gp.player.screenY){
            g2.drawImage(image,screenX,screenY,gp.titalSize,gp.titalSize,null);
        }
    }
}
