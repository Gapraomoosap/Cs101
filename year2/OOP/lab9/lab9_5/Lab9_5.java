package year2.OOP.lab9.lab9_5;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

public class Lab9_5 extends JFrame {
     public JButton jbtPNumber;
     public JButton Etc;
     public JTextField jtfScreen;
     public String operand = "";
     public String A0 = "";
     public String A1 = "";
     Lab9_5(){
        setLayout(new BorderLayout());
        JPanel p1 = new JPanel();
        Listener lisa = new Listener();
        GridLayout grid = new GridLayout(5,4);
        grid.setHgap(2);
        grid.setVgap(2);
        p1.setLayout(grid);
        Etc = new JButton("√");
        Etc.addActionListener(lisa);
        p1.add(Etc);
        Etc = new JButton("x²");
        Etc.addActionListener(lisa);
        p1.add(Etc);
        Etc = new JButton("±");
        Etc.addActionListener(lisa);
        p1.add(Etc);
        Etc = new JButton("C");
        Etc.setForeground(Color.RED);
        Etc.addActionListener(lisa);
        p1.add(Etc);
        for(int i=7;i<=9;i++){
             jbtPNumber =new JButton(""+i);
             jbtPNumber.addActionListener(lisa);
             p1.add(jbtPNumber);
        }
        Etc = new JButton("+");
        Etc.addActionListener(lisa);
        p1.add(Etc);
        for(int i=4;i<=6;i++){
            jbtPNumber =new JButton(""+i);
            jbtPNumber.addActionListener(lisa);
            p1.add(jbtPNumber);
        }
        Etc = new JButton("-");
        Etc.addActionListener(lisa);
        p1.add(Etc);
        for(int i=1;i<=3;i++){
            jbtPNumber =new JButton(""+i);
            jbtPNumber.addActionListener(lisa);
            p1.add(jbtPNumber);
        }
        Etc = new JButton("*");
        Etc.addActionListener(lisa);
        p1.add(Etc);
        Etc = new JButton("0");
        Etc.addActionListener(lisa);
        p1.add(Etc);
        Etc = new JButton(".");
        Etc.addActionListener(lisa);
        p1.add(Etc);
        Etc = new JButton("=");
        Etc.addActionListener(lisa);
        p1.add(Etc);
        Etc = new JButton("/");
        Etc.addActionListener(lisa);
        p1.add(Etc);
        jtfScreen = new JTextField("");
        jtfScreen.setEditable(false);
        jtfScreen.setHorizontalAlignment(SwingConstants.RIGHT);
        add(p1,BorderLayout.SOUTH);
        add(jtfScreen, BorderLayout.CENTER);
     }
    //inner
    class Listener implements ActionListener{
          @Override
        public void actionPerformed(ActionEvent e){
            if (e.getActionCommand().equals("C")) {
                jtfScreen.setText("");
                operand = "";
                A0 = "";
                A1 = "";
            }else if (e.getActionCommand().equals("±")){
                if(jtfScreen.getText() == "" || operand != "") return;
                jtfScreen.setText(""+Double.parseDouble(jtfScreen.getText()) * -1);
            }else if (e.getActionCommand().equals("x²")){
                if(jtfScreen.getText() == "" || operand != "") return;
                jtfScreen.setText(""+Math.pow(Double.parseDouble(jtfScreen.getText()), 2));
            }else if (e.getActionCommand().equals("√")){
                if(jtfScreen.getText() == "" || operand != "") return;
                jtfScreen.setText(""+Math.sqrt(Double.parseDouble(jtfScreen.getText())));
            }else if (e.getActionCommand().equals("+")){
                if(jtfScreen.getText() == "" || operand != "") return;
                operand = "+";
                A0 = jtfScreen.getText();
                jtfScreen.setText("");
            }else if (e.getActionCommand().equals("-")){
                if(jtfScreen.getText() == "" || operand != "") return;
                operand = "-";
                A0 = jtfScreen.getText();
                jtfScreen.setText("");
            }else if (e.getActionCommand().equals("*")){
                if(jtfScreen.getText() == "" || operand != "") return;
                operand = "*";
                A0 = jtfScreen.getText();
                jtfScreen.setText("");
            }else if (e.getActionCommand().equals("/")){
                if(jtfScreen.getText() == "" || operand != "") return;
                operand = "/";
                A0 = jtfScreen.getText();
                jtfScreen.setText("");
            }else if (e.getActionCommand().equals("=")){
                if(A0 == "" || operand == "") return;
                A1 = jtfScreen.getText();
                if(operand == "+"){
                    jtfScreen.setText(""+(Double.parseDouble(A0) + Double.parseDouble(A1)));
                }else if(operand == "-"){
                    jtfScreen.setText(""+(Double.parseDouble(A0) - Double.parseDouble(A1)));
                }else if(operand == "*"){
                    jtfScreen.setText(""+(Double.parseDouble(A0) * Double.parseDouble(A1)));
                }else if(operand == "/"){
                    jtfScreen.setText(""+(Double.parseDouble(A0) / Double.parseDouble(A1)));
                }
                operand = "";
                A0 = jtfScreen.getText();
                A1 = "";
            }else{
                jtfScreen.setText(jtfScreen.getText()+((JButton) e.getSource()).getText());
            }
        }  
    }

    public static void main(String[] args) {
        JFrame cal = new Lab9_5();
        cal.setTitle("Calculator App");
        cal.setSize(220,220);
        cal.setLocationRelativeTo(null);
        cal.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        cal.setVisible(true);
        cal.setResizable(false);
    }
}