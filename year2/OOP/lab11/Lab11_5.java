package year2.OOP.lab11;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.LinkedList;

public class  Lab11_5 extends JFrame {

    Lab11_5() {
        JPanel panel = new JPanel(new GridLayout(1, 1));
        panel.add(new BalloonPanel());
        
        add(panel);

    }

    public static void main(String[] args) {
        Lab11_5 frame = new Lab11_5();
        frame.setTitle("Lab11_5");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(1200, 800);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
}
class BalloonPanel extends JPanel {

    final static int BALLOON_RADIUS = 30;
    final static int BALL_RADIUS = 5;
    final static int GUN_LENGTH = 25;
    final static int PANEL_WIDTH = 200;
    final static int PANEL_HEIGHT = 100;
    
    boolean timestart = false;

    private int x_Balloon = (int) (Math.random() * PANEL_WIDTH);
    private int y_Balloon = (int) (Math.random() * PANEL_HEIGHT);

    private int angle = 90;

    private LinkedList<SmallBall> list = new LinkedList<SmallBall>();

    class SmallBall {

        int length;
        int angle;

        SmallBall(int length, int angle) {
            this.length = length;
            this.angle = angle;
        }
    }
    
    Thread timer = new Thread(new Runnable(){
        public void run(){
            
            while(true){
                try{
                    if(timestart == false){
                        repaint();
                    }
                    Thread.sleep(10);
                    
                }catch(Exception e){
                 
                }
                
            }
        }
    });

    /*private Timer timer = new Timer(10, new ActionListener() {
        public void actionPerformed(ActionEvent e) {
            repaint();
        }
    });*/

    public BalloonPanel() {
        setFocusable(true);

        this.addKeyListener(new KeyAdapter() {
            public void keyPressed(KeyEvent e) {
                if (e.getKeyCode() == KeyEvent.VK_LEFT) {
                    if (angle < 180) {
                        angle += 3;
                    }
                } else if (e.getKeyCode() == KeyEvent.VK_RIGHT) {
                    if (angle > 0) {
                        angle -= 3;
                    }
                } else if (e.getKeyCode() == KeyEvent.VK_UP) {
                    // Launch a small ball
                    list.add(new SmallBall(GUN_LENGTH, angle));
                }

                repaint();
            }
        });
        timer.start();
    }

    boolean hit = false;

    /**
     * Paint message
     */
    public void paint(Graphics g) {
        super.paintComponent(g);

        // Display the gun
        int x = (int) (GUN_LENGTH * Math.cos(Math.toRadians(angle))
                + getWidth() / 2);
        int y = (int) (getHeight()
                - GUN_LENGTH * Math.sin(Math.toRadians(angle)));
        g.drawLine(getWidth() / 2, getHeight(), x, y);
        g.drawLine(getWidth() / 2 - 1, getHeight(), x - 1, y);
        g.drawLine(getWidth() / 2 - 2, getHeight(), x - 2, y);
        g.drawLine(getWidth() / 2 + 1, getHeight(), x + 1, y);
        g.drawLine(getWidth() / 2 + 2, getHeight(), x + 2, y);

        if (hit) {
            // Display three small pieces
            g.drawOval(x_Balloon - BALLOON_RADIUS / 2 - 5,
                    y_Balloon - BALLOON_RADIUS / 2, BALLOON_RADIUS,
                    BALLOON_RADIUS);
            g.drawOval(x_Balloon + 2 * BALLOON_RADIUS + 5 - BALLOON_RADIUS / 2,
                    y_Balloon - BALLOON_RADIUS / 2, BALLOON_RADIUS,
                    BALLOON_RADIUS);
            g.drawOval(x_Balloon - BALLOON_RADIUS / 2,
                    y_Balloon + 2 * BALLOON_RADIUS + 5 - BALLOON_RADIUS / 2, BALLOON_RADIUS,
                    BALLOON_RADIUS);
            g.drawOval(x_Balloon - BALLOON_RADIUS / 2,
                    y_Balloon - 2 * BALLOON_RADIUS - 5 - BALLOON_RADIUS / 2, BALLOON_RADIUS,
                    BALLOON_RADIUS);

            hit = false;

            // New random location
            x_Balloon = (int) (Math.random() * PANEL_WIDTH);
            y_Balloon = (int) (Math.random() * PANEL_HEIGHT);

            return;
        }

        g.drawOval(x_Balloon - BALLOON_RADIUS,
                y_Balloon - BALLOON_RADIUS, 2 * BALLOON_RADIUS,
                2 * BALLOON_RADIUS);//love ajansatid;

        // Draw small hitting balls
        for (int i = 0; i < list.size(); i++) {
            SmallBall ball = list.get(i);//eiei
            ball.length += 5;//yeye

            x = (int) (ball.length * Math.cos(Math.toRadians(ball.angle))
                    + getWidth() / 2);
            y = (int) (getHeight()
                    - ball.length * Math.sin(Math.toRadians(ball.angle)));

            g.fillOval(x - BALL_RADIUS, y - BALL_RADIUS, 2 * BALL_RADIUS,
                    2 * BALL_RADIUS);

            if (overlaps(x, y, BALL_RADIUS,
                    x_Balloon, y_Balloon, BALLOON_RADIUS)) {
                list.remove(i);
                hit = true;
            }

            if (x > getWidth() || x < 0 || y < 0) {
                list.remove(i);
            }
        }
    }
    public static boolean overlaps(double x1, double y1, double radius1,
            double x2, double y2, double radius2) {
        return Math.sqrt((x1 - x2) * (x1 - x2)
                + (y1 - y2) * (y1 - y2)) <= radius1 + radius2;
    }
}