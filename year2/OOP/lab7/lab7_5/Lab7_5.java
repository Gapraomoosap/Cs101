package year2.OOP.lab7.lab7_5;

public class Lab7_5 {
    public static void main(String[] args) {
        Employee emp = new Manager();
        Address address = new Address();
        address.setCity("Bangkok");
        address.setStreet("KMUTNB");
        emp.setAddress(address);
        emp.setSalary(20000);
        emp.setId(1);
        emp.setName("Satid");
        ((Manager)emp).setParkingNo("123");
        System.out.println();
        System.out.println(emp.getDetails());
        System.out.println();
    }
}
class Address{
    protected String street;
    protected String city;
    public String getStreet(){
        return street;
    }
    public void setStreet(String street){
        this.street = street;
    }
    public String getCity(){
        return city;
    }
    public void setCity(String city){
        this.city = city;
    }
    public String getAddressinfo(){
        return "street: "+street+" city: "+city;
    }
}
class Employee{
    protected int id;
    protected String name;
    protected double salary;
    protected Address address;
    public String getDetails(){
        return "id: "+id+" name:"+name+" salary:"+salary+" Address:"+address.getAddressinfo();
    }
    public int getId(){
        return id;
    }
    public void setId(int id){
        this.id = id;
    }
    public String getName(){
        return name;
    }
    public void setName(String name){
        this.name=name;
    }
    public double getSalary(){
        return salary;
    }
    public void setSalary(double salary){
        this.salary = salary;
    }
    public Address getAddress(){
        return address;
    }
    public void setAddress(Address address){
        this.address = address;
    }
}
class Manager extends Employee{
    protected String parkingNo;
    public String getParkinginfo(){
        return parkingNo;
    }
    public void setParkingNo(String parkingNo){
        this.parkingNo = parkingNo;
    }   
    public String getDetails(){
        return "id: "+getId()+" name: "+getName()+" salary: "+getSalary()+" Address: "+getAddress().getAddressinfo()+" ParkingNO: "+getParkinginfo();
    }
}
