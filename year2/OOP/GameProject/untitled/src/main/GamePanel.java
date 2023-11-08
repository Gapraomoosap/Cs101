package main;

import entity.Player;
import Tiles.Tilemanager;
import Object.SuperObject;
import javax.swing.*;
import java.awt.*;

public class GamePanel extends JPanel implements Runnable{

    //Screen setting
    final int originalTitleSize = 16;
    final int scale = 3;
    public final int titalSize = originalTitleSize * scale;
    public final int maxScreenCol = 16;
    public final int maxScreenRow = 12;
    public final int screenWidth = titalSize * maxScreenCol;
    public final int screenHeight = titalSize * maxScreenRow;

    public final int maxWorldCol = 50;
    public final int maxWorldRow = 50;
    public final int worldWidth = titalSize * maxWorldCol;
    public final int worldHeight = titalSize * maxScreenRow;
    int fps = 60;

    Tilemanager tileM = new Tilemanager(this);
    KeyHandler keyH = new KeyHandler();
    Thread gameThread;

    public CollisionChecker cChecker = new CollisionChecker(this);
    public UI ui = new UI(this);
    public AssetSetter aSetter = new AssetSetter(this);
    public Player player = new Player(this,keyH);
    public SuperObject obj[] = new SuperObject[50];

    public GamePanel()
    {
        this.setPreferredSize(new Dimension(screenWidth,screenHeight));
        this.setBackground(Color.black);
        this.setDoubleBuffered(true);
        this.addKeyListener(keyH);
        this.setFocusable(true);
    }
    public void setupGame(){
        aSetter.setObject();
    }

    public void startGameThread(){
        gameThread = new Thread(this);
        gameThread.start();
    }
    @Override
    public void run() {

        double drawInterval = 1000000000/fps;
        double nextDrawTime = System.nanoTime() + drawInterval ;
        while (gameThread != null){

            update();
            repaint();

            try {
            double remainingTime = nextDrawTime - System.nanoTime();
            remainingTime = remainingTime/1000000;
            if(remainingTime < 0)
            {
                remainingTime = 0;
            }
                Thread.sleep((long)remainingTime);
            nextDrawTime += drawInterval;
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }

    public void update()
    {
        player.update();
    }
    public void paintComponent(Graphics g){
        super.paintComponent(g);
        Graphics2D g2 = (Graphics2D) g;

        tileM.draw(g2);

        for(int i = 0 ;i<obj.length;i++){
            if(obj[i] != null){
                obj[i].draw(g2,this);
            }
        }

        player.draw(g2);
        ui.draw(g2);
        g2.dispose();
    }
}
