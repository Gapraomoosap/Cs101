package year2.OOP.lab11;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Lab11_3 extends JFrame {
    int xBase = 10;
    public Lab11_3() {
        JPanel p = new JPanel(new GridLayout(4,1));
        p.add(new RaceCar());
        add(p);
    }
    public static void main(String[] args) {
        Lab11_3 frame = new Lab11_3();
        frame.setTitle("Exercise");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 200);
        frame.setLocationRelativeTo(null); // Center the frame
        frame.setVisible(true);
    }
}
class RaceCar extends JPanel {
    private int xBase = 0;
    private Thread timer;
    int sleeptime = 0;
    public RaceCar() {
        timer = new Thread(new Runnable(){
            public void run(){
                
                while(true){
                    try{
                        repaint();
                        Thread.sleep(sleeptime);
                        
                    }catch(Exception e){
                     
                    }
                }
            }
        });
        timer.start();
        this.setFocusable(true);
        this.addKeyListener(new KeyAdapter() {
            public void keyPressed(KeyEvent e) {
                if (e.isControlDown() && e.getKeyCode() == 61) {
                    if (sleeptime > 5)
                        sleeptime -= 5;
                }
            else if (e.isControlDown() && e.getKeyCode() == 45)
                sleeptime++ ;
            }
        });
    }
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        int yBase = getHeight();
        if (xBase > getWidth())
            xBase = -20;
        else
            xBase += 1;
        g.setColor(Color.BLACK);
        g.fillOval(xBase + 10, yBase - 10, 10, 10);
        g.fillOval(xBase + 30, yBase - 10, 10, 10);
        g.setColor(Color.GREEN);
        g.fillRect(xBase, yBase - 20, 50, 10);
        g.setColor(Color.RED);
        Polygon polygon = new Polygon();
        polygon.addPoint(xBase + 10, yBase - 20);
        polygon.addPoint(xBase + 20, yBase - 30);
        polygon.addPoint(xBase + 30, yBase - 30);
        polygon.addPoint(xBase + 40, yBase - 20);
        g.fillPolygon(polygon);
    }
}