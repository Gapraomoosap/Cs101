# หัวข้อ

## OOP

- ### Class / Object
- #### Attributes
- #### Methods

  - Void(no return)
  - int/double/String (return)
  - boolean (return)
- #### Constructors

  - Default
  - Parameter
- ### Modifiers
- #### private
- #### public
- #### protected
- ### Encapsulation
- #### get
- #### set

---

### 1.วิธีสร้าง Object

#### 1. สร้าง Class

`public class "ชื่อclass"{ }`

#### 2. เพิ่ม Attributes

1. `String` + name
2. `int` + age
3. `double` + weight

#### 3.เรียกใช้ Class

`"ชื่อclass" "ชื่อobj" = new "ชื่อclass"();`
เช่น มี Class ชื่อ animal `animal rabbit = new animal();`
เราก็จะได้ Object ของ rabbit

###### Object code

```java
public class animal{
    String name ;
    int age ;
    double weight;
}
```

###### Main Code

```java
public class main{
    public static void main(string[] args) {
    animal rabbit = new animal();
    }
}
```

---

#### วิธีใช้ Object

##### หลังจากสร้าง class เสร็จแล้วก็สามารถทำการกำหนดค่าต่างๆให้มันได้โดยขั้นตอนดังนี้

#### 1.กำหนด attributes = "ชื่อ obj".attributes

- `rabbit.name = "Mali";`
- `rabbit.age = 3;`
- `rabbit.weight = 2.5;`

#### การแสดงผล

- `System.out.println(rabbit.name);`
- `System.out.println(rabbit.age);`
- `System.out.println(rabbit.weight);`

---

## Method

Method = ความสามารถของ object นั้นๆ เช่น พูด อ่าน คำนวน

### วิธีสร้าง Method

- `public void + "ชื่อ Method"` ใช้กับ คำสั่งที่ไม่ต้อง return
- `public int / double / String  +"ชื่อ Method"` ใช้กับ คำสั่งที่ต้องการ return ค่าต่างๆตามต้องการ
- `public boolean +"ชื่อ Method"` ใช้กับ คำสั่งที่ต้องการ return ค่าเป็น True,False

#### ตัวอย่างการใช้งาน ( ใช้งานคล้าย function )

#### การสร้าง Method

1. Method void

   ```java
   public class animal{
    public void speak(){
        System.out.println("I'm animal!!!");
        System.out.println("My name is "+ name);
        }
    }
   ```
2. Mothod int/double/String

   ```java
   public class animal{
    public int Eatrate(){
        return weight * 0.25;
        }
    }
   ```
3. Method boolean

   ```java
   public class animal{
    public boolean check(){
        return weight < 10;
        }
    }
   ```

#### การใช้ Method

```java
public class Main {
    public static void main(String[] args) {
            Animal rabbit = new Animal();
            rabbit.name = "Mali";
            rabbit.speak();
        }
    }
```

จากcode จะทำการเรียกใช้งาน method speak() ที่อยู่ภายใน class rabbit.

---

### การใช้ Method แบบส่งค่า parameter

Method สามารถรับ parameter เพื่อประมวลข้อมูลที่เราต้องการโดยการส่งค่าเข้าไปให้มัน

#### ตัวอย่าง

```java
public class Calculator{
    public int Convert(int c){
        return (c*9/5)+32;
        }
    }
```

ทำการสร้าง method แบบรับค่าเป็น int และรับค่ามาคำนวน ในกรณีนี้จะเป็นการแปลงอุณหภูมิจาก C --> F

```java
public class Main {
    public static void main(String[] args) {
            Calculator X1 = new Calculator();
            int c = 30 ;
            X1.Convert(c);
        }
    }
```

จากนั้นทำการเรียกใช้ method และส่งค่าที่ต้องการแปลงไปให้มัน

---

### Constructors

Constructor ทำหน้าที่เก็บหรือรับค่าเริ่มต้นตอนสร้าง object เช่นถ้าตอนเริ่มสร้าง obj เราอยากกำหนดค่าให้มันเลยตั้งแต่ต้น ก็สามารถทำได้โดยใช้ Constructor

#### 1.Default Constructor

Constructor ที่ไม่ได้รับ input parameters ใช้สำหรับไว้รองรับการสร้าง obj ที่ไม่ได้ใส่ parameters ก็จะมาใช้งาน Constructor นี้

```java
public class animal{
    String name;
    int age;
    public animal(){}
}
```

ขึ้นอยู่ว่าเราจะกำหนดอะไรให้มันหรือถ้าไม่กำหนดเลยก็ได้

#### 2.Constructor Parameters

เป็น constructor ที่สามารถรับค่าได้ตั้งแต่ต้นมาทำงานได้เลยเช่น ต้องการเช็ตชื่อตั้งแต่สร้าง obj ก็ใช้ constructor แบบนี้ได้เลย

```java
public class animal{
    String name;
    int age;
    public animal(String n){
        name = n;
    }
}
```

```java
public class Main {
    public static void main(String[] args) {
            animal rabbit = new animal("Mali");
        }
    }
```

---

### Modifiers

- #### Public

  : สามารถเข้าถึงได้จากทุกที่ ทุก class
- #### Private

  : สามารถเข้าถึงได้แค่จาก class ตัวเองเท่านั้น
- #### Protected

  : ยังไม่เรียนเอาไว้ก่อน

---

### Encapsulation

##### Get & Set ทำหน้าที่รับและส่งค่าสำหรับ parameter ที่มีค่าเป็นprivate ในคลาสอื่นๆ

#### Getter

```java
public class animal{
    private name;

    public String getName(){
        return this.name;
    }
}
```

return ค่าที่ต้องการออกมาจาก method เพื่อให้สามารถใช้งานนอก class ได้

#### Setter

```java
public class animal{
    private name;

    public void setName(String name){
        this.name=name;
    }
}
```

ส่งค่าเข้ามา เพื่อเปลี่ยนค่าที่ต้องการใน class จาก method

---

### Array

#### Array list

##### วิธีประกาศ array list

```java
import java.util.ArrayList;

public class main(){
    public static void main(String[] args){
        ArrayList<String> students = new ArrayList<string>();
    }
}
```

##### function ในการใช้งาน

1. add เพิ่มค่าเข้าไปในarray `students.add("Focus")` , `students.add("Smild")`
2. get เลือกดูค่าจาก arrayจากตำแหน่งนั้นๆ `students.get(1)`
3. set เลือกเปลี่ยนค่าในตำแหน่งต่างๆในarray `students.set(1,"PP")`
4. remove เลือกลบค่าจากตำแหน่งนั้นๆออก `students.remove(0)`
5. clear เลือกที่จะเคลียร์ array ทิ้ง = ลบค่าทุกอย่างทิ้งไปให้หมด `students.clear()`
6. size ดูขนาดของarrayว่ามีข้อมูลกี่ตัว `students.size()` **ต้อง print มาดูนะจ๊ะ

___
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>

### Inheritance

##### Inheritance คือการสืบทอด class จาก class จากแม่ --> ลูก ลูกจะมีคุณสมบัติและใช้งาน methodได้เหมือน class แม่ ทั้ง attribute และ method

<span style="color:red"> ❗️ การสืบทอดแบบนี้สามารถทำได้แค่ 1 ตัวเท่านั้น </span>

#### How to Inheritance

```java
public class Employee {
    String Name,Surname;
    int age;

}

public class programmer extends Employee {

}
```

programmer ได้ทำการสืบทอดจาก class แม่ซึ่งคือ Employee โดยใช้คำสั่ง extends ต่อไปนี้ programmer ก็จะสามารถทำงานได้เหมือน class employee แล้วเช่น

```java
public class Employee {
    String Name,Surname;
    int age;

    void Say(){
        System.out.println("I'm employee of Facebook");
    }
    public static void main(String[] args){
        Employee p1 = new Employee();
        programmer p2 = new programmer();
        p1.Say();
        p2.Say();
    }
}

public class programmer extends Employee {

}
```
<br>
<br>
<br>
<br>
<br>
<br>

output

```txt

I'm employee of Facebook
I'm employee of Facebook
```

จะเห็นได้ว่า programmer สามารถใช้งาน method Say()ของ clss employeeได้โดยที่ไม่ต้องประกาศ method เอง

<span style="color:red">❗️ไม่สามารถทำแบบนี้ได้ ถ้าจะสืบทอดหลายตัวต้องใช้ Interface </span>
<br>

```java
public class programmer extends Employee , People{}
```

---

#### Overriding

##### คือการเปลี่ยนค่าการทำงานใน method ที่เรา inheritance เพื่อใช้งานให้ตรงจุดประสงค์ของ ตัวclassลูก

```java
public class Employee {
    String Name,Surname;
    int age;

    public void Say(){
        System.out.println("I'm employee of Facebook");
    }
    public static void main(String[] args){
        programmer p2 = new programmer();
        p2.Say();
    }
}
public class programmer extends Employee {
    @Override
    public void Say() {
        System.out.println("I'm programmer");
    }
}

```

output

```txt
I'm programmer
```

จะสังเกตุได้ว่า p2 ที่ใช้งาน method say จะไม่ได้Printค่าเหมือนกับ class แม่แล้วเพราะว่า ได้ถูก override ไปเรียบร้อยแล้ว

---

#### keyword super

##### super ทำหน้าที่ไว้เรียกใช้งาน method ของ class แม่ที่มีชื่อเหมือนกับmethodที่อยู่ในclassของตัวเอง เช่น

```java
public class Employee {
    private String Name,Surname;
    private int age;

    public void Say(){
        System.out.println("I'm employee of Facebook");
    }

    public static void main(String[] args){
        programmer p2 = new programmer();
        p2.Say();
    }
}
public class programmer extends Employee {
    @Override
    public void Say() {
        super.Say(); //super อันนี้เรียกใช้งานmethodของclassแม่
        System.out.println("I'm programmer");
    }
}
```

output

```txt
I'm employee of Facebook
I'm programmer
```

</br>

#### keyword final

##### final ใช้ทำหมันหรือไม่สามารถนำไปใช้งานต่อได้ทั้งการ inherite และ override เช่น

```java
public final class programmer extends Employee {
    @Override
    public void Say() {
        super.Say();
        System.out.println("I'm programmer");
    }
}
```

❌`public class hr extends programmer{}`
การใส่ final เข้าไปที่ class programmer จะทำให้ ไม่มีclassอื่นๆ เอาไป extends ต่อได้

<br>

#### keyword Abstract

##### abstract ใช้ทำให้ class ที่inheriteไปจำเป็นต้อง Implement methods ทุกอันที่ติด abstract และ ไม่สามารถประกาศ abstract method ใน class ที่ไม่ได้เป็น abstract ได้

<span style="color:red"> ❗️ แต่การประกาศ abstract จะทำให้ class นั้นๆไม่สามารถ สร้างตัวเองเป็น object ได้และไม่สามารถกำหนดการทำงานต่างๆใน method ได้เลย </span>

```java
public abstract class Employee {

    abstract public void Say();
    abstract public void CalBonus();

    public static void main(String[] args){
        programmer p2 = new programmer();
        p2.Say();
    }
}
```

```java
public final class programmer extends Employee {
    @Override
    public void Say() {
        System.out.println("I'm programmer");
    }
}
```

❌ ต้อง implement method ทุกอันขาดของ CalBonus

```java
public final class programmer extends Employee {
    @Override
    public void Say() {
        System.out.println("I'm programmer");
    }
    @Override
    public void CalBonus() {
      
    }
}
```

✔️ implement method ครบทุกอัน

---

<br>

#### Overloading

##### คือการใช้งาน method ที่มีชื่อเหมือนกันแต่เปลี่ยน parameter ที่ใช้รับค่าทำให้ไม่เกิด Error

```java
public final class programmer extends Employee {
    // parameter เป็น int ,int
    public int Cal(int x,int y){
        return x+y;
    }
    // parameter เป็น double double
    public double Cal(double x,double y){
        return x*y;
    }
    // parameter เป็น double double String
    public double Cal(double x,double y,String a){
        if(a == "+"){
            return x+y;
        }
        else if(a == "*"){
            return x*y;
        }
        else return 0;
    }
}
```

จะเห็นได้ว่า method มีชื่อเหมือนกันแต่สามารถใช้งานได้

---

<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>

#### Interface

##### Interface ทำงานคล้ายการ Abstract ต่างกันตรงที่ class ที่ inherite จาก Interface class ต้องทำการ implement method ทุกตัวของclassแม่ และสามารถสืบทอดได้หลายตัว

การสร้าง Interface เหมือนกับการสร้าง abstract แค่ไม่ต้องใส่คำว่า abstract หน้า method

```java
public interface Camera {
    void setSS();
    void setISO();
}
```

เรียกใช้งานโดยการเติมคำว่า implements ตามตัวชื่อ class  หลังจากนั้นต้องทำการ implement ทุก method ที่มี

```java
public class Phone implements Camera{
    @Override
    public void setSS() {

    }

    @Override
    public void setISO() {

    }
}
```
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>


##### multiple inherite

```java
public interface Camera {
    void setSS();
    void setISO();
}
```

```java
public interface contact {

    void saveNumber();
    Void deleteData();
}
```

```java
public class System {
    public void open(){}
    public void close(){}
}
```

```java
public class Phone extends System  implements Camera,contact{
    @Override
    public void setSS() {

    }

    @Override
    public void setISO() {

    }

    @Override
    public void saveNumber() {

    }

    @Override
    public Void deleteData() {
        return null;
    }
}
```
