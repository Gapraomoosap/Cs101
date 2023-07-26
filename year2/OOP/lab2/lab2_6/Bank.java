package year2.OOP.lab2.lab2_6;

public class Bank {
    public static void main(String[] args) {
        info account = new info(123,1000);
        account.setAnnualInterestRate(7.0/100.0);
        account.withdraw(200);
        account.deposit(500);
        System.out.println(String.format("Balance = %.2f ,Monthly Interest rate = %.2f",
                account.getBalance(),account.getMonthlyInterest() ));
        
    }
}
