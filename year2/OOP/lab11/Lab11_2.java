package year2.OOP.lab11;
import javax.swing.*;
import java.awt.*;
import java.util.*;

public class Lab11_2 extends JFrame {
    private StillClock clock1 = new StillClock();
    private StillClock clock2 = new StillClock();
    public Lab11_2() {
        JPanel p1 = new JPanel(new GridLayout(1, 3));
        p1.add(clock1);
        p1.add(clock2);
        add(p1);
        Thread timer = new Thread(new Runnable(){
            public void run(){
                
                while(true){
                    try{
                        clock1.setCurrentTime(7);
                        clock1.repaint();
                        clock2.setCurrentTime(5);
                        clock2.repaint();
                        Thread.sleep(1000);
                        
                    }catch(Exception e){
                     
                    }
                    
                }
            }
        });
        timer.start();
    }

    public static void main(String[] args) {
        JFrame frame = new Lab11_2();
        frame.setTitle("CLOCK");
        frame.setSize(200, 200);
        frame.setLocationRelativeTo(null); // Center the frame
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}

class StillClock extends JPanel {

    private int hour;
    private int minute;
    private int second;

    public StillClock() {
        setCurrentTime(hour);
    }

    public StillClock(int hour, int minute, int second) {
        this.hour = hour;
        this.minute = minute;
        this.second = second;
    }

    public int getHour() {
        return hour;
    }

    public void setHour(int hour) {
        this.hour = hour;
        repaint();
    }

     
    public int getMinute() {
        return minute;
    }

    public void setMinute(int minute) {
        this.minute = minute;
        repaint();
    }
     
    public int getSecond() {
        return second;
    }

    public void setSecond(int second) {
        this.second = second;
        repaint();
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        int clockRadius
                = (int) (Math.min(getWidth(), getHeight()) * 0.8 * 0.5);
        int xCenter = getWidth() / 2;
        int yCenter = getHeight() / 2;
        g.setColor(Color.black);
        g.drawOval(xCenter - clockRadius, yCenter - clockRadius,
                2 * clockRadius, 2 * clockRadius);
        g.drawString("12", xCenter - 5, yCenter - clockRadius + 12);
        g.drawString("9", xCenter - clockRadius + 3, yCenter + 5);
        g.drawString("3", xCenter + clockRadius - 10, yCenter + 3);
        g.drawString("6", xCenter - 3, yCenter + clockRadius - 3);
        int sLength = (int) (clockRadius * 0.8);
        int xSecond = (int) (xCenter + sLength
                * Math.sin(second * (2 * Math.PI / 60)));
        int ySecond = (int) (yCenter - sLength
                * Math.cos(second * (2 * Math.PI / 60)));
        g.setColor(Color.red);
        g.drawLine(xCenter, yCenter, xSecond, ySecond);
        int mLength = (int) (clockRadius * 0.65);
        int xMinute = (int) (xCenter + mLength
                * Math.sin(minute * (2 * Math.PI / 60)));
        int yMinute = (int) (yCenter - mLength
                * Math.cos(minute * (2 * Math.PI / 60)));
        g.setColor(Color.blue);
        g.drawLine(xCenter, yCenter, xMinute, yMinute);
        int hLength = (int) (clockRadius * 0.5);
        int xHour = (int) (xCenter + hLength
                * Math.sin((hour % 12 + minute / 60.0) * (2 * Math.PI / 12)));
        int yHour = (int) (yCenter - hLength
                * Math.cos((hour % 12 + minute / 60.0) * (2 * Math.PI / 12)));
        g.setColor(Color.green);
        g.drawLine(xCenter, yCenter, xHour, yHour);
    }

    public void setCurrentTime(int hour) {
        Calendar calendar = new GregorianCalendar();
        this.hour = calendar.get(Calendar.HOUR_OF_DAY)+hour;
        this.minute = calendar.get(Calendar.MINUTE);
        this.second = calendar.get(Calendar.SECOND);
    }

    @Override
    public Dimension getPreferredSize() {
        return new Dimension(200, 200);
    }
}