package year2.OOP.lab10.lab10_4;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Lab10_4 extends JFrame {
     public RaceCar car1;
    public RaceCar car2 ;
    public RaceCar car3 ;
    public RaceCar car4;
    JTextField field1;
    JTextField field2;
    JTextField field3;
    JTextField field4;
    JButton setbutton;
    Lab10_4() {
        JPanel panel = new JPanel(new GridLayout(5, 1));
        JPanel controlpanel = new JPanel(new GridLayout(1, 4));
        JPanel control= new JPanel(new GridLayout(2, 1));
        Listener listen = new Listener();

        JPanel inputarea = new JPanel(new GridLayout(1, 2));
        JLabel label = new JLabel("Car1 : ");
        field1 = new JTextField("10");
        inputarea.add(label);
        inputarea.add(field1);
        setbutton = new JButton("Setcar1");
        setbutton.addActionListener(listen);
        control.add(inputarea);
        control.add(setbutton);
        controlpanel.add(control);
        control= new JPanel(new GridLayout(2, 1));

        JPanel inputarea2 = new JPanel(new GridLayout(1, 2));
        JLabel label2 = new JLabel("Car2 : ");
        field2 = new JTextField("20"); 
        inputarea2.add(label2);
        inputarea2.add(field2);
        setbutton = new JButton("Setcar2");
        setbutton.addActionListener(listen);
        control.add(inputarea2);
        control.add(setbutton);
        controlpanel.add(control);
        control= new JPanel(new GridLayout(2, 1));

        JPanel inputarea3 = new JPanel(new GridLayout(1, 2));
        JLabel label3 = new JLabel("Car3 : ");
        field3 = new JTextField("30"); 
        inputarea3.add(label3);
        inputarea3.add(field3);
        setbutton = new JButton("Setcar3");
        setbutton.addActionListener(listen);
        control.add(inputarea3);
        control.add(setbutton);
        controlpanel.add(control);
        control= new JPanel(new GridLayout(2, 1));
        

        JPanel inputarea4 = new JPanel(new GridLayout(1, 2));
        JLabel label4 = new JLabel("Car4 : ");
        field4 = new JTextField("40"); 
        inputarea4.add(label4);
        inputarea4.add(field4);
        setbutton = new JButton("Setcar4");
        setbutton.addActionListener(listen);
        control.add(inputarea4);
        control.add(setbutton);
        controlpanel.add(control);
        control= new JPanel(new GridLayout(2, 1));

        panel.add(controlpanel);
        car1 = new RaceCar(10);
        car2 = new RaceCar(20);
        car3 = new RaceCar(30);
        car4 = new RaceCar(40);
        panel.add(car1);
        panel.add(car2);
        panel.add(car3);
        panel.add(car4);
        add(panel);

    }
    class Listener implements ActionListener{
        @Override
      public void actionPerformed(ActionEvent e){
        if (e.getActionCommand().equals("Setcar1")) {
            car1.setSpeed(Integer.parseInt(field1.getText()));
        }else if (e.getActionCommand().equals("Setcar2")){
            car2.setSpeed(Integer.parseInt(field2.getText()));
        }else if (e.getActionCommand().equals("Setcar3")){
            car3.setSpeed(Integer.parseInt(field3.getText()));
        }else if (e.getActionCommand().equals("Setcar4")){
            car4.setSpeed(Integer.parseInt(field4.getText()));
        }
      }  
    }

    public static void main(String[] args) {
        Lab10_4 frame = new  Lab10_4();
        frame.setTitle("RaceCar");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(500, 300);
        frame.setLocationRelativeTo(null); // Center the frame
        frame.setVisible(true);
    }

}

class RaceCar extends JPanel {

    private int xBase = 0, speed;
    private Timer timer = new Timer(10, new Listener());

    public RaceCar(int speed) {
        this.speed = speed;
        timer.start();
    }

    class Listener implements ActionListener {

        public void actionPerformed(ActionEvent e) {
            repaint();
        }
    }

    public void setSpeed(int speed){
        this.speed = speed;
    }

    public void paintComponent(Graphics g) {
        super.paintComponent(g);

        int yBase = getHeight();
        if (xBase > getWidth()) {
            xBase = -20;
        } else {
            xBase += speed;
        }

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
