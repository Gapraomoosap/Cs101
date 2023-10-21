package year2.OOP.lab9.lab9_7;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.border.TitledBorder;


class Panel extends JFrame{
    JPanel p1 = new JPanel();
    JLabel headtext = new JLabel("ACCOUNT MONEY");
    
    JPanel p2 = new JPanel(new FlowLayout(FlowLayout.CENTER, 10, 20));
    JLabel id = new JLabel("ID:");
    JTextField idinputtext = new JTextField(10);
    JLabel money = new JLabel("MONEY:");
    JTextField moneyinputtext = new JTextField(10);
    JLabel baht = new JLabel("Baht");
    JLabel annual = new JLabel("ANNUALINTERATE RATE:");
    JTextField annualinputtext = new JTextField(20);
    JLabel dayopenac = new JLabel("DAY OPEN ACCOUNT:");
    
    String[] day = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17",
        "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31"};
    JComboBox<String> cbd = new JComboBox<String>(day);
    
    String[] month = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    JComboBox<String> cbm = new JComboBox<String>(month);
    
    String[] year = {"1995", "1996", "1997", "1998", "1999", "2000", "2001", "2002", "2003", "2004", "2005", "2006", "2007", "2008", "2009", "2010"};
    JComboBox<String> cby = new JComboBox<String>(year);
    
    JLabel fnl = new JLabel("FIRST NAME:");
    JTextField fnf = new JTextField(20);
    
    JLabel lnl = new JLabel("LAST NAME:");
    JTextField lnf = new JTextField(20);
    
    JLabel birthdayl = new JLabel("YOUR BIRTH DAY (d/m/y):");
    
    String[] bday = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17",
        "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31"};
    JComboBox<String> bcbd = new JComboBox<String>(day);
    
    String[] bmonth = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    JComboBox<String> bcbm = new JComboBox<String>(month);
    
    String[] byear = {"1995", "1996", "1997", "1998", "1999", "2000", "2001", "2002", "2003", "2004", "2005", "2006", "2007", "2008", "2009", "2010"};
    JComboBox<String> bcby = new JComboBox<String>(year);
    
    JLabel agel = new JLabel("AGE:");
    JTextField agef = new JTextField(20);
    JLabel yearl = new JLabel("YEAR");
    
    JPanel p3 = new JPanel(new FlowLayout(FlowLayout.RIGHT, 5, 5));
    
    JButton saveb = new JButton("SAVE");
    JButton showb = new JButton("SHOW");
    
    /* Variable */
    int idaccount = 0;
    double moneyaccount, annualrate;
    String dayopen, monthopen, yearopen;
    String Firstnameaccount, Lastnameaccount;
    String dayaccout, monthaccount, yearaccount;
    int age;
    
    Panel(){
        p1.add(headtext);
        p2.setBorder(new TitledBorder("Enter Data Account Money"));
        p2.add(id);
        p2.add(idinputtext);
        p2.add(money);
        p2.add(moneyinputtext);
        p2.add(baht);
        p2.add(annual);
        p2.add(annualinputtext);
        p2.add(dayopenac);
        p2.add(cbd);
        p2.add(cbm);
        p2.add(cby);
        p2.add(fnl);
        p2.add(fnf);
        p2.add(lnl);
        p2.add(lnf);
        p2.add(birthdayl);
        p2.add(bcbd);
        p2.add(bcbm);
        p2.add(bcby);
        p2.add(agel);
        p2.add(agef);
        p2.add(yearl);
        
        p3.add(saveb);
        p3.add(showb);
        
        add(p1, BorderLayout.NORTH);
        add(p2, BorderLayout.CENTER);
        add(p3, BorderLayout.SOUTH);
        saveb.addActionListener(new SaveData());
        showb.addActionListener(new ShowData());
    }
    
    class ShowData implements ActionListener{
        @Override
        public void actionPerformed(ActionEvent e){
            
            if(idaccount == 0){
                JFrame f2 = new JFrame();
           
                JOptionPane.showMessageDialog(f2, "Don't have Data Account, Please Enter Data!"); 
            }
            else{
                
                JFrame fshow = new JFrame();

                fshow.setSize(410, 450);
                fshow.setVisible(true);
                fshow.setTitle("Show Detail of Account Money");

                JPanel pshowhead = new JPanel();
                JPanel pshow = new JPanel(new FlowLayout(FlowLayout.CENTER, 10, 20));
                JLabel headtext = new JLabel("ACCOUNT MONEY");

                String showid = "ID: " + idaccount + " | ";
                JLabel showidlabel = new JLabel(showid);

                String showmoney = "MONEY: " + moneyaccount + " BAHT" + " | ";
                JLabel showmoneylabel = new JLabel(showmoney);

                String showannualrate = "ANNUALINTERATE RATE: " + annualrate + " | ";
                JLabel showannualratelabel = new JLabel(showannualrate);

                String dmyopen = "DAY OPEN ACCOUNT: " + dayopen + " " + monthopen + " " + yearopen + " | ";
                JLabel showdmyopenlabel = new JLabel(dmyopen);

                String firstnameshow = "FIRST NAME: " + Firstnameaccount + " | ";
                JLabel showfirstnamelabel = new JLabel(firstnameshow);

                String lastnameshow = "LAST NAME: " + Lastnameaccount + " | ";
                JLabel showlastnamelabel = new JLabel(lastnameshow);

                String dmybirth = "BIRTH DAY OF YOU: " + dayaccout + " " + monthaccount + " " + yearaccount + " | ";
                JLabel showdmybirthlabel = new JLabel(dmybirth);
 
                String ageshow = "AGE: " + age + " YEAR" + " | ";
                JLabel showagelabel = new JLabel(ageshow);

                pshowhead.add(headtext);
                pshow.setBorder(new TitledBorder("Data Account Money"));

                pshow.add(showidlabel);
                pshow.add(showmoneylabel);
                pshow.add(showannualratelabel);
                pshow.add(showdmyopenlabel);
                pshow.add(showfirstnamelabel);
                pshow.add(showlastnamelabel);
                pshow.add(showdmybirthlabel);
                pshow.add(showagelabel);

                fshow.add(pshowhead, BorderLayout.NORTH);
                fshow.add(pshow, BorderLayout.CENTER); 
            }
        }
    }
    
    class SaveData implements ActionListener{
        @Override
        public void actionPerformed(ActionEvent e){
            try{
                idaccount = Integer.parseInt(idinputtext.getText());
                moneyaccount = Double.parseDouble(moneyinputtext.getText());
                annualrate = Double.parseDouble(annualinputtext.getText());
                dayopen = cbd.getSelectedItem().toString();
                monthopen = cbm.getSelectedItem().toString();
                yearopen = cby.getSelectedItem().toString();
                Firstnameaccount = fnf.getText();
                Lastnameaccount = lnf.getText();
                dayaccout = bcbd.getSelectedItem().toString();
                monthaccount = bcbm.getSelectedItem().toString();
                yearaccount = bcby.getSelectedItem().toString();
                age = Integer.parseInt(agef.getText());
                
                JFrame f2 = new JFrame();
                JOptionPane.showMessageDialog(f2, "Save Account Success!"); 
            }catch (Exception er){
                JFrame f2 = new JFrame("Error");
                JOptionPane.showMessageDialog(f2, er);
            }

        }
    }
}
public class Lab9_7 {
     public static void main(String[] args){
        JFrame window = new Panel();
        window.setSize(410, 450);
        window.setVisible(true);
        window.setLocationRelativeTo(null);
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        window.setTitle("Show Detail of Account Money");
    }
}
