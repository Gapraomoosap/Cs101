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
    public  int hascolor =0;
    public int hascoin = 0;

    public Player(GamePanel gp,KeyHandler keyH){
        this.gp = gp;
        this.keyH = keyH;

        screenX = gp.screenWidth/2 - (gp.titalSize/2);
        screenY = gp.screenHeight/2 - (gp.titalSize/2);

        solidArea = new Rectangle();
        solidArea.x = 8;
        solidArea.y = 8;
        solidAreaDefaultX = solidArea.x;
        solidAreaDefaultY = solidArea.y;
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
            blue = ImageIO.read(getClass().getResourceAsStream("/resources/object/blueBall.png"));
            green = ImageIO.read(getClass().getResourceAsStream("/resources/object/greenBall.png"));
            orange = ImageIO.read(getClass().getResourceAsStream("/resources/object/orangeBall.png"));
            purple = ImageIO.read(getClass().getResourceAsStream("/resources/object/purpleBall.png"));
            sky = ImageIO.read(getClass().getResourceAsStream("/resources/object/skyBall.png"));
            yellow = ImageIO.read(getClass().getResourceAsStream("/resources/object/yellowBall.png"));
            white = ImageIO.read(getClass().getResourceAsStream("/resources/object/whiteBall.png"));
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

            int objIndex = gp.cChecker.checkObject(this,true);
            pickUpObject(objIndex);

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
    public void pickUpObject(int i){
        if(i != 999){
            String objectName = gp.obj[i].name;
            if(objectName == "orange"){
                hascolor++;
                gp.obj[i] = null;
                color = "orange";
            }
            else if (objectName == "blue") {
                hascolor++;
                gp.obj[i] = null;
                color = "blue";
            }
            else if (objectName == "sky") {
                hascolor++;
                gp.obj[i] = null;
                color = "sky";
            }
            else if (objectName == "yellow") {
                hascolor++;
                gp.obj[i] = null;
                color = "yellow";
            }
            else if (objectName == "purple") {
                hascolor++;
                gp.obj[i] = null;
                color = "purple";
            }
            else if (objectName == "green") {
                hascolor++;
                gp.obj[i] = null;
                color = "green";
            }
            else if(objectName == "key"){
                hascoin++;
                gp.obj[i] = null;
            }
            if(hascolor == 6){
                color = "white";
                if(objectName == "Exit"){
                    gp.ui.gameFinish = true;
                }
            }

        }
    }
    public void draw(Graphics2D g2){
        BufferedImage image = null;
        if(color == "red"){
            image = red;
        } else if (color == "orange") {
            image = orange;
        } else if(color == "green"){
            image = green;
        } else if(color == "yellow"){
            image = yellow;
        } else if(color == "purple"){
            image = purple;
        } else if(color == "sky"){
            image = sky;
        } else if(color == "blue"){
            image = blue;
        } else if(color == "white"){
            image = white;
        }
        if(color != "white"){

        }
        g2.drawImage(image,screenX,screenY,gp.titalSize,gp.titalSize,null);
    }
}
