package Entity;

import main.GamePanel;
import main.KeyHandler;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;

public class Player extends Entity{
    GamePanel gp;
    KeyHandler keyH;

    public Player(GamePanel gp,KeyHandler keyH){
        this.gp = gp;
        this.keyH = keyH;

        setDefaultValues();
        getPlayerImg();
    }

    public void setDefaultValues(){
        x=50;
        y=50;
        speed = 2;
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

        if(keyH.upPressed == true){
            y -= speed;
        }
        else if (keyH.downPressed == true) {
            y += speed;
        }
        else if(keyH.rightPressed == true)
        {
            x += speed;
        } else if (keyH.leftPressed == true) {
            x -= speed;
        }

    }
    public void draw(Graphics2D g2){
        g2.setColor(Color.white);
        g2.fillRect(x,y,gp.titalSize,gp.titalSize);
        BufferedImage image = null;
        if(color == "red"){
            image = red;
        }
        g2.drawImage(image,x,y,gp.titalSize,gp.titalSize,null);
    }
}
