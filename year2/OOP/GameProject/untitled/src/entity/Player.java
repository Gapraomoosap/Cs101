package entity;

import main.GamePanel;
import main.KeyHandler;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;

public class Player extends Entity{
    GamePanel gp;
    KeyHandler keyH;

    public final int screenX;
    public final int screenY;

    public Player(GamePanel gp,KeyHandler keyH){
        this.gp = gp;
        this.keyH = keyH;

        screenX = gp.screenWidth/2 - (gp.titalSize/2);
        screenY = gp.screenHeight/2 - (gp.titalSize/2);

        solidArea = new Rectangle();
        solidArea.x = 8;
        solidArea.y = 8;
        solidArea.width = 32;
        solidArea.height = 32;
        setDefaultValues();
        getPlayerImg();
    }

    public void setDefaultValues(){
        x=gp.titalSize*25;
        y=gp.titalSize*25;
        speed = 5;
        color = "red";
    }

    public void getPlayerImg() {
        try {
            red = ImageIO.read(getClass().getResourceAsStream("/resources/player/red.png"));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public void update(){
        if(keyH.upPressed == true || keyH.downPressed == true || keyH.leftPressed == true || keyH.rightPressed || true) {
            if (keyH.upPressed) {
                direction = "up";
//            y -= speed;
            } else if (keyH.downPressed) {
                direction = "down";
//            y += speed;
            } else if (keyH.rightPressed) {
                direction = "right";
//            x += speed;
            } else if (keyH.leftPressed) {
                direction = "left";
//            x -= speed;
            }
            else{
                direction = " ";
            }
            collisionOn = false;
            gp.cChecker.checkTile(this);

            if (!collisionOn) {
                if (direction == "up") {
                    y -= speed;

                } else if (direction == "down") {
                    y += speed;
                } else if (direction == "left") {
                    x -= speed;
                } else if (direction == "right") {
                    x += speed;
                }
            }
        }

    }
    public void draw(Graphics2D g2){
        g2.setColor(Color.white);
        g2.fillRect(x,y,gp.titalSize,gp.titalSize);
        BufferedImage image = null;
        if(color == "red"){
            image = red;
        }
        g2.drawImage(image,screenX,screenY,gp.titalSize,gp.titalSize,null);
    }
}
