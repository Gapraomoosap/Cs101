package year2.OOP.lab6.lab6_6;

public class Person {
    String name;
    String surname;
    int age;
    Account.Date dDate;

    Person() {
    }

    @Override
    public String toString() {
        return " " + name + surname;
    }

    Person(String name, String surname) {
        this.name = name;
        this.surname = surname;
    }
    void setName(String name)
    {
        this.name = name;
    }
    void setSurname(String surname)
    {
        this.surname = surname;
    }
    void setAge(int age)
    {
        this.age = age;
    }
    void setdDate(Account.Date D)
    {
        this.dDate = D;
    }
    String getName()
    {
        return this.name;
    }
    String getSurname()
    {
        return this.surname;
    }
    int getAge()
    {
        return this.age;
    }
    Account.Date getdDate()
    {
        return this.dDate;
    }
}

