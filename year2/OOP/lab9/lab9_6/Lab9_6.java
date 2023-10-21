package year2.OOP.lab9.lab9_6;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
/**
 *
 * @author acer
 */
public class Lab9_6 {
        public static void main(String[] args) {
        JFrame frame = new Hang();
        frame.setTitle("Hangman");
        frame.setLocationRelativeTo(null);
        // Center the frame
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(350, 300);
        frame.setVisible(true);
    } 
}
class Hang extends JFrame {

    private HangmanPanel h = new HangmanPanel();

    public Hang() {
        JPanel panel = new JPanel();
        this.add(h, BorderLayout.CENTER);
        this.add(panel, BorderLayout.SOUTH);
    }
}

class HangmanPanel extends JPanel {

    int radius = 20;
    int x = 0;
    int y = 0;
    int A;
    Timer timer = new Timer(10, new Listener());

    HangmanPanel() {
        timer.start();
    }

    class Listener implements ActionListener {

        public void actionPerformed(ActionEvent e) {
            repaint();
        }
    }

    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.drawArc(20, 220, 80, 40, 0, 180); //base
        g.drawLine(20 + 40, 220, 20 + 40, 20); // |
        g.drawLine(20 + 40, 20, 20 + 40 + 100, 20);  // -
        if (160 - x == 200 || 160 + y == 120) {
            A = 1;
        }
        if (160 - x == 120 || 160 + y == 200) {
            A = 0;
        }

        g.drawLine(160, 20, 160 - x, 40);
        g.setColor(Color.red);
        g.drawOval(20 + 40 + 100 - x - radius, 40, 2 * radius, 2 * radius);  //head
        g.setColor(Color.orange);
        g.drawLine(20 + 40 + 100 - x - (int) (radius * Math.cos(Math.toRadians(45))), 40 + radius
                + (int) (radius * Math.sin(Math.toRadians(45))), 20 + 40 + 100 - 60 - x * 2, 40 + radius + 60); //a-left
        g.setColor(Color.yellow);
        g.drawLine(20 + 40 + 100 - x + (int) (radius * Math.cos(Math.toRadians(45))), 40 + radius
                + (int) (radius * Math.sin(Math.toRadians(45))), 20 + 40 + 100 + 60 - x * 2, 40 + radius + 60);//a-right
        g.setColor(Color.green);
        g.drawLine(20 + 40 + 100 - x, 40 + 2 * radius, 160 - x * 2, 40 + radius + 80);  //body
        g.setColor(Color.blue);
        g.drawLine(20 + 40 - 2 * x + 100, 40 + radius + 80, 140 - x * 3, 40 + radius + 80 + 40);//l-left
        g.setColor(Color.MAGENTA);
        g.drawLine(20 + 40 - 2 * x + 100, 40 + radius + 80, 180 - x * 3, 40 + radius + 80 + 40);//l-left
        if (A == 0) {
            x--;
            y--;
        }
        if (A != 0) {
            x++;
            y++;
        }
    }
}