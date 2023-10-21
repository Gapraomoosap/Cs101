package year2.OOP.lab6.lab6_5;

import java.util.Date;

public class Account {
    private int id;
    private double balance;
    private double annuallnterestRate;
    private Date dateCreated;

    Account()
    {

    }
    Account(int id,double balance){
        this.id = id;
        this.balance = balance;
    }
    int getId()
    {
        return id;
    }
    double getBalance()
    {
        return balance;
    }
    double getAnnuallnterestRate()
    {
        return annuallnterestRate;
    }
    Date getDateCreated()
    {
        return dateCreated;
    }
    void setId(int id)
    {
        this.id = id;
    }
    void setBalance(double B)
    {
        this.balance = B;

    }
    void setAnnuallnterestRate(double A)
    {
        this.annuallnterestRate = A;
    }
    void setDateCreated(Date D)
    {
        this.dateCreated = D;
    }
    double getMonthlyInterestRate(){
        return annuallnterestRate / 12;
    }
    double getMonthlyInterest()
    {
        return getMonthlyInterestRate()*balance;
    }
    void withdraw(double w)
    {
        this.balance = this.balance - w;
    }
    void deposit(double d)
    {
        this.balance = this.balance + d;
    }
    public static void main(String[] args){
        Account BB = new Account(1122,20000);
        BB.setAnnuallnterestRate(0.045);
        BB.withdraw(2500);
        BB.deposit(3000);
        System.out.println(BB.balance);
        System.out.println(BB.getMonthlyInterest());
    }


}
