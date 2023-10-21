package year2.OOP.lab10.lab10_2;

import java.awt.event.*;
import javax.swing.*;
import java.awt.*;
import java.util.*;
import javax.swing.Timer;

public class Lab10_2 extends JFrame {
    static String country = "";
    JLabel jlbThai = new JLabel("Thai");
    JLabel jlbOther = new JLabel("Japan");
    StillClock thai = new StillClock();
    StillClock other = new StillClock();
    JPanel p1 = new JPanel();
    JPanel p2 = new JPanel(new GridLayout(1,2,5,5));
    JPanel p3 = new JPanel();
    JTextField jtfCountry = new JTextField("Japan");
    JButton jbtButton = new JButton("OK");
    Timer timer = new Timer(1000,new TimerListener());

    public Lab10_2() {
        JPanel p1 = new JPanel(new GridLayout(1, 3));
        timer.start();
        p1.add(jlbThai);
        p1.add(jlbOther);
        add(p1);
        p2.add(thai);
        p2.add(other);
        add(p2);
        p3.add(new JLabel("Input Cpountry"));
        p3.add(jtfCountry);
        p3.add(jbtButton);
        add(p1,BorderLayout.NORTH);
        add(p2,BorderLayout.CENTER);
        add(p3,BorderLayout.SOUTH);

        jbtButton.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                country = jtfCountry.getText();
                jlbOther.setText(country);
            }
            
        });
    }

    class TimerListener implements ActionListener {

        @Override

        public void actionPerformed(ActionEvent e) {
              country = jtfCountry.getText();
              System.out.print(""+country);
              thai.setCurrentTime();
              thai.repaint();
              if(jtfCountry.getText().equals("Japan")){
                  other.setCurrentTime();
                  other.setHour(thai.getHour()+2);
                  other.repaint();
              }
              else if(jtfCountry.getText().equals("Us")){
                  other.setCurrentTime();
                  other.setHour(thai.getHour()-10);
                  other.repaint();
              }
        }
    }

/** Main method */
public static void main(String[] args) {
    
    JFrame frame = new Lab10_2();
    frame.setTitle("CLOCK");
    frame.setSize(200, 200);
    frame.setLocationRelativeTo(null); // Center the frame
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.setVisible(true);
    }
}


class StillClock extends JPanel {

    int hour;
    int minute;
    int second;

    public StillClock() {
        setCurrentTime();
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

  
//      Return minute
     
    public int getMinute() {
        return minute;
    }

    
    // Set a new minute
  
    public void setMinute(int minute) {
        this.minute = minute;
        repaint();
    }

    
    //  Return second
     
    public int getSecond() {
        return second;
    }

   
     // Set a new second
 
    public void setSecond(int second) {
        this.second = second;
        repaint();
    }

    @Override

    // Draw the clock

    protected void paintComponent(Graphics g) {
        super.paintComponent(g);

        // Initialize clock parameters
        int clockRadius
                = (int) (Math.min(getWidth(), getHeight()) * 0.8 * 0.5);
        int xCenter = getWidth() / 2;
        int yCenter = getHeight() / 2;

        // Draw circle
        g.setColor(Color.black);
        g.drawOval(xCenter - clockRadius, yCenter - clockRadius,
                2 * clockRadius, 2 * clockRadius);
        g.drawString("12", xCenter - 5, yCenter - clockRadius + 12);
        g.drawString("9", xCenter - clockRadius + 3, yCenter + 5);
        g.drawString("3", xCenter + clockRadius - 10, yCenter + 3);
        g.drawString("6", xCenter - 3, yCenter + clockRadius - 3);

        // Draw second hand
        int sLength = (int) (clockRadius * 0.8);
        int xSecond = (int) (xCenter + sLength
                * Math.sin(second * (2 * Math.PI / 60)));
        int ySecond = (int) (yCenter - sLength
                * Math.cos(second * (2 * Math.PI / 60)));
        g.setColor(Color.red);
        g.drawLine(xCenter, yCenter, xSecond, ySecond);

        // Draw minute hand
        int mLength = (int) (clockRadius * 0.65);
        int xMinute = (int) (xCenter + mLength
                * Math.sin(minute * (2 * Math.PI / 60)));
        int yMinute = (int) (yCenter - mLength
                * Math.cos(minute * (2 * Math.PI / 60)));
        g.setColor(Color.blue);
        g.drawLine(xCenter, yCenter, xMinute, yMinute);

        // Draw hour hand
        int hLength = (int) (clockRadius * 0.5);
        int xHour = (int) (xCenter + hLength
                * Math.sin((hour % 12 + minute / 60.0) * (2 * Math.PI / 12)));
        int yHour = (int) (yCenter - hLength
                * Math.cos((hour % 12 + minute / 60.0) * (2 * Math.PI / 12)));
        g.setColor(Color.green);
        g.drawLine(xCenter, yCenter, xHour, yHour);
    }

    public void setCurrentTime() {
        // Construct a calendar for the current date and time
        Calendar calendar = new GregorianCalendar();

        this.hour = calendar.get(Calendar.HOUR_OF_DAY);
        this.minute = calendar.get(Calendar.MINUTE);
        this.second = calendar.get(Calendar.SECOND);
    }

    @Override
    public Dimension getPreferredSize() {
        return new Dimension(200, 200);
    }
    
}
