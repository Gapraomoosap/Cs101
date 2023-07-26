package year2.OOP.lab2.lab2_6;

import java.util.Date;

/**
 *
 * @author Name
 */
public class info {
    private int id;
    private double balance,annualInterestRate;
    private Date dateCreate;
    
    info(){}
    info(int id,double balance){
        this.id = id;
        this.balance = balance;
    }
    public int getId(){
        return id;
    }
    public double getBalance()
    {
        return balance;
    }
    public double getAnnualInterestRate(){
        return this.annualInterestRate;
    }
    public Date getDatecreate(){
        return this.dateCreate;
    }
    
    public void setId(int id){
        this.id = id;
    }
    
    public void setBalance(double balance)
    {
        this.balance = balance;
    }
    public void setAnnualInterestRate(double annualInterestRate){
        this.annualInterestRate = annualInterestRate;
    }
    public void setDatecreate(Date dateCreate){
        this.dateCreate = dateCreate;
    }
    public double getMonthlyInterestRate(){
        return annualInterestRate/12;
    }
    public double getMonthlyInterest(){
        return getMonthlyInterestRate() * balance;
    }
    
    void withdraw(double amt){
        this.balance = this.balance - amt;
    }
    void deposit(double amt){
        this.balance = this.balance + amt;
    }
}