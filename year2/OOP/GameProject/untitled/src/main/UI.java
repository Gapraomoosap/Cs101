package main;

import java.awt.*;
import java.awt.image.BufferedImage;
import java.text.DecimalFormat;

import Object.*;

public class UI {
    GamePanel gp;
    Font arial_40,arial_100;
    BufferedImage keyImage,ballImage;
    public boolean gameFinish = false;
    double playTimeSec,playTimeMin ;
    DecimalFormat dFormat = new DecimalFormat("#0.00");

    public UI(GamePanel gp){
        this.gp = gp;
        arial_100 = new Font("Arial",Font.BOLD,100);
        arial_40 = new Font("Arial",Font.PLAIN,40);
        Objcoin coin = new Objcoin();
        keyImage = coin.image;
        WhiteBall ball = new WhiteBall();
        ballImage = ball.image;
    }
    public void draw(Graphics2D g2){
        int minutes = (int) playTimeSec / 60;
        int seconds = (int) playTimeSec % 60;
        String formattedTime = String.format("%02d:%02d", minutes, seconds);
        if(gameFinish){
            String txt;
            int txtlength;
            int x,y;
            txt = "You win!!!";
            txtlength = (int)g2.getFontMetrics().getStringBounds(txt,g2).getWidth();
            x = gp.screenWidth/2 - txtlength;
            y = gp.screenHeight - (gp.titalSize*4);
            g2.setFont(arial_100);
            g2.setColor(Color.red);
            g2.drawString(txt,x,y);
            gp.gameThread = null;
        }

        playTimeSec += (double) 1/60;
        g2.setFont(arial_40);
        g2.setColor(Color.white);
        g2.drawImage(keyImage,gp.titalSize/2,gp.titalSize/2, gp.titalSize, gp.titalSize ,null);
        g2.drawString("x "+gp.player.hascoin+"/6",gp.titalSize/2+74,gp.titalSize/2+40);
        g2.drawImage(ballImage,gp.titalSize/2,gp.titalSize+70,gp.titalSize,gp.titalSize,null);
        g2.drawString("x "+gp.player.hascolor+"/6",gp.titalSize/2+74,gp.titalSize+100);
        g2.drawString("time: " + formattedTime, gp.titalSize * 11, gp.titalSize/2+40);
    }
}
