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
___
## 1.วิธีสร้าง Object

#### 1. สร้าง Class
`public class "ชื่อclass"{ }`
### 2. เพิ่ม Attributes 
1. `String` + name
2. `int` + age
3. `double` + weight

### 3.เรียกใช้ Class
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
___
## วิธีใช้ Object 
##### หลังจากสร้าง class เสร็จแล้วก็สามารถทำการกำหนดค่าต่างๆให้มันได้โดยขั้นตอนดังนี้
#### 1.กำหนด attributes = "ชื่อ obj".attributes
- `rabbit.name = "Mali"; `
- `rabbit.age = 3;`
- `rabbit.weight = 2.5;`
  
#### การแสดงผล 
-   `System.out.println(rabbit.name);`
-   `System.out.println(rabbit.age);`
-   `System.out.println(rabbit.weight);`

___
## Method
Method = ความสามารถของ object นั้นๆ เช่น พูด อ่าน คำนวน
 
### วิธีสร้าง Method
-   `public void + "ชื่อ Method"` ใช้กับ คำสั่งที่ไม่ต้อง return
-   `public int / double / String  +"ชื่อ Method"` ใช้กับ คำสั่งที่ต้องการ return ค่าต่างๆตามต้องการ 
-   `public boolean +"ชื่อ Method"` ใช้กับ คำสั่งที่ต้องการ return ค่าเป็น True,False

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
___
### การใช้ Method แบบส่งค่า parameter
Method สามารถรับ parameter เพื่อประมวลข้อมูลที่เราต้องการโดยการส่งค่าเข้าไปให้มัน 
#### ตัวอย่าง:
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
___
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
___

### Modifiers

- #### Public
    : สามารถเข้าถึงได้จากทุกที่ ทุก class
- #### Private
    : สามารถเข้าถึงได้แค่จาก class ตัวเองเท่านั้น
- #### Protected
    : ยังไม่เรียนเอาไว้ก่อน

___

### Encapsulation
##### Get & Set ทำหน้าที่รับและส่งค่าสำหรับ parameter ที่มีค่าเป็น private ในคลาสอื่นๆ
#### Getter
```java
public class animal{
    private name;

    public getName(){
        return this.name;
    }
}
```
return ค่าที่ต้องการออกมาจาก method เพื่อให้สามารถใช้งานนอก class ได้
#### Setter
```java 
public class animal{
    private name;

    public setName(String name){
        this.name=name;
    }
}
```
ส่งค่าเข้ามา เพื่อเปลี่ยนค่าที่ต้องการใน class จาก method 

___
