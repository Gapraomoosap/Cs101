package year2.OOP.lab6.lab6_6;

public class SavingAccount extends Account{
    @Override
    void tranferMoney(Account acc1, double amount){
        this.setBalance(this.getBalance() - amount-20);
        acc1.setBalance(acc1.getBalance() + amount);

    }
}
