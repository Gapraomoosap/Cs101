package year2.OOP.lab6.lab6_6;

import java.util.Date;

public class Account {
    private int id;
    private double balance;
    private double annuallnterestRate;
    private Date dateCreated;
    private Person objPerson;


    class Date {
        int day;
        String month;
        int year;

        Date() {
        }
        Date(int D, String M, int Y) {
            this.day = D;
            this.month = M;
            this.year = Y;
        }
        void setDay(int D)
        {
            this.day = D;
        }

        void setMonth(String M)
        {
            this.month = M;
        }

        void setYear(int Y)
        {
            this.year = Y;
        }
        int getDay()
        {
            return this.day;
        }
        int getYear()
        {
            return this.year;
        }
        String getMonth()
        {
            return this.month;
        }
    }

    Account() {

    }

    Account(int id, double balance) {
        this.id = id;
        this.balance = balance;
    }

    int getId() {
        return id;
    }

    double getBalance() {
        return balance;
    }

    double getAnnuallnterestRate() {
        return annuallnterestRate;
    }

    Date getDateCreated() {
        return dateCreated;
    }

    void setId(int id) {
        this.id = id;
    }

    void setBalance(double B) {
        this.balance = B;

    }

    void setAnnuallnterestRate(double A) {
        this.annuallnterestRate = A;
    }

    void setDateCreated(Date D) {
        this.dateCreated = D;
    }

    double getMonthlyInterestRate() {
        return (annuallnterestRate / 100) / 12;
    }

    double getMonthlyInterest() {
        return getMonthlyInterestRate() * balance;
    }

    void withdraw(double w) {
        this.balance = this.balance - w;
    }

    void deposit(double d) {
        this.balance = this.balance + d;
    }
    void tranferMoney(Account acc1,double amount){
        this.balance = this.balance-amount;
        acc1.balance = acc1.balance+amount;
    }

    public static void main(String[] args) {
        Account BB = new Account(1122, 20000);
        BB.setAnnuallnterestRate(4.5);
        BB.withdraw(2500);
        BB.deposit(3000);
        System.out.println(BB.balance);
        System.out.println(BB.getMonthlyInterest());
    }

}
