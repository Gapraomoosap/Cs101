package year2.OOP.lab9.lab9_4;

import java.awt.BorderLayout;
import java.awt.GridLayout;
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Lab9_4 extends JFrame {
     JLabel jlbUS = new JLabel("US Dollars");
    JLabel jlbCanadian = new JLabel("Canadian Dollars");
    JTextField jtfUS = new JTextField(4);
    JTextField jtfCanadian = new JTextField(4);
    JButton jbtConvert = new JButton("Convert");

    Lab9_4()
    {
        setLayout(new BorderLayout());
        JPanel p1 = new JPanel(new BorderLayout());
        JPanel p3 = new JPanel(new GridLayout(2,1));
        JPanel p4 = new JPanel(new GridLayout(2,1));
        p1.add(p3,BorderLayout.CENTER);
        p1.add(p4,BorderLayout.WEST);
        p4.add(jlbUS);
        p4.add(jlbCanadian);
        p3.add(jtfUS);
        p3.add(jtfCanadian);
        jtfUS.setHorizontalAlignment(JTextField.RIGHT);
        jtfCanadian.setHorizontalAlignment(JTextField.RIGHT);
        JPanel p2 = new JPanel(new BorderLayout());
        p2.add(jbtConvert,BorderLayout.EAST);
        add(p2,BorderLayout.SOUTH);
        add(p1,BorderLayout.CENTER); 
        Listener spyObj = new Listener();
        jbtConvert.addActionListener(spyObj);
    }
    
    class Listener implements ActionListener
    {
        @Override
        public void actionPerformed(ActionEvent e)
        {
            if(e.getActionCommand() == "Convert")
            {
                double moneyUS = Double.parseDouble(jtfUS.getText());
                double moneyCanadian = moneyUS*1.5;
                jtfCanadian.setText(" "+moneyCanadian);
            }
        }
    }
    public static void main(String[] args) {
        // TODO code application logic here
        Lab9_4 frame = new Lab9_4();
        frame.setTitle("Convert US Dollars to Canadian Dollars");
        frame.setSize(400,150); //size
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //keep in memory
        frame.setVisible(true);
    }
}
