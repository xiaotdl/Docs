# Java

### Variables and Operators

> List primitive Java data types?

byte(8 bits), char(16 bits), short(16 bits), int(32 bits), long(64 bits), float(32 bits), double(64 bits), boolean


> List default values (of class data members) in Java?

- byte: 0
- float: 0.0f
- double: 0.0d


> What is the range for int data type?

- int data type is a 32-bit signed **two's complement** integer.
- positive number range: 0 ~ 2,147,483,647 (2^31 -1)
- negative number range: -1 ~ -2,147,483,648.(-2^31)
- 32th bit represents sign: 0 => positive, 1 => negative
```
怎么算补码：原码的反码加1
1  -> 00...1
0  -> 00...0
-1 -> 11...1
```


> How many bitwise right shift operators are in Java?

There are two:
- signed right shift (>>)
```java
System.out.print(-1>>1); // prints -1
System.out.print(-4>>1); // prints -2
```
- unsigned right shift (>>>)
```java
// int is stored using 32 bit 2's complement form. 
// Binary representation of -1 is all 1s (11..1111)
System.out.print(-1>>>30);  // prints 3 (00...011)
System.out.print(-1>>>31);  // prints 1 (00...001)
```


> What is **Autoboxing** and **Unboxing** in Java?

- Autoboxing: automatic conversion that Java compiler makes between the primitive types and their corresponding object wrapper class. e.g. int => Integer, double => Double
- Unboxing: the other way around.
```java
// In Java, values from -128 to 127 are cached, so the same objects are returned.
// The implementation of valueOf() uses cached objects if the value is between -128 to 127.

// the value 400 is autoboxed into Integer objects x and y
Integer x = 400;
Integer y = 400;
System.out.println(x == y ? "Same" : "Not Same"); // Not Same

// both x and y are referenced to cached object Integer 40
Integer x = 40;
Integer y = 40;
System.out.println(x == y ? "Same" : "Not Same"); // Same

// explicitly new an Integer object will bypass the cached objects and autoboxing
Integer x = new Integer(40);
Integer y = new Integer(40);
System.out.println(x == y ? "Same" : "Not Same"); // Not Same
```


> When a **byte** data type is used?

This data type is used to save space in large arrays, mainly in place of integers, since a byte (8 bit) is four times smaller than an int (32 bit).


> What is **widening primitive conversion**?

Invoked when there is operator, convert operands to the same type, in such precedence: string, double, float, long, int
```java
System.out.print("a" + "b"); // prints "ab"
System.out.print('a' + 'b'); // prints 195 (97+98)
System.out.print('a'); // prints "a"
System.out.print(2+0+1+6+"GeeksforGeeks"); // prints "9GeeksforGeeks"  <= most binary operators evalutate from left to right, it's converted to string only after it met the first string
System.out.print("GeeksforGeeks"+2+0+1+6); // prints "GeeksforGeeks2016"

```


### static keyword

> Compare static variable vs. non-static variable?

- A static variable is associated with the class as a whole rather than with specific instances of a class.
- Non-static variables take on unique values with each object instance.


> What are **static data member** and **static method** in Java?

- **static data member**: class members that shared among all objects.
```java
    // Example of using static var count to count the number of objects created
    class Klass {
        static int count = 0;
        Klass() { 
           count++; 
        }    
        public static void main(String arr[]) {
           Klass obj1 = new Klass();
           Klass obj2 = new Klass();
           System.out.println("Total objects created: " + count);
        }
    }
Output:
Total objects created: 2
```
- **static method**:
  * can only call other static methods
  * can only access static data member
  * cannot access **this** or **super**
- static data members and static methods can be accessed without creating an object. They can be accessed through class name.


> Can a class be **static** in Java?

Yes, but only for the nested classes.


> What is **static block** in Java?

- static blocks are executed before main method at the time of classloading.  
- This code inside static block is executed only once: the first time you make an object of that class or the first time you access a static member of that class (even if you never make an object of that class).
```java
    class Klass {
        static {
            System.out.println("static block called ");
        }
        Klass(){
            System.out.println("Constructor called");
        }
        public static void main(String args[]) {
     
           // Although we have two objects, static block is executed only once.
           Klass obj1 = new Klass();
           Klass obj2 = new Klass();
        }
    }
Output:
static block called
Constructor called
Constructor called
```


> Are static local variables allowed in Java?

NO.
```java
    static int x= 10; // Error: Static local variables are not allowed
```


> Can we Overload or Override static methods in Java?

- Overload (YES):
    * We can have two or more static methods with same name, but different input paramters.
    * We cannot overload two methods if they differ only static keyword.
- Override (NO):
    * Static methods don't take part in polymorphism. If we attempt to override the static methods they will just hide the superclass static methods instead of overriding them.
    * Static members are universal members. They can be accessed from anywhere.
```java
    /* Java program to show that if static method is redefined by
       a derived class, then it is not overriding. */
     
    // Superclass
    class Base {
         
        // Static method in base class which will be hidden in subclass 
        public static void display() {
            System.out.println("Static or class method from Base");
        }
         
         // Non-static method which will be overridden in derived class 
         public void print()  {
             System.out.println("Non-static or Instance method from Base");
        }
    }
     
    // Subclass
    class Derived extends Base {
         
        // This method hides display() in Base 
        public static void display() {
             System.out.println("Static or class method from Derived");
        }
         
        // This method overrides print() in Base 
        public void print() {
             System.out.println("Non-static or Instance method from Derived");
       }
    }
     
    // Driver class
    public class Test {
        public static void main(String args[ ])  {
           Base obj1 = new Derived();
            
           // As per overriding rules this should call to class Derive's static 
           // overridden method. Since static method can not be overridden, it 
           // calls Base's display() 
           obj1.display();  
            
           // overriding
           obj1.print();     
           
           // This is hiding superclass's method, instead of overriding
           Derived obj2 = new Derived();
           obj2.display();
        }
    }
Output:
Static or class method from Base
Non-static or Instance method from Derived
Static or class method from Derived
```
- Defining a Method with the Same Signature as a Superclass's Method  

|                            |**Superclass Instance Method**|**Superclass Static Method**|
|----------------------------|------------------------------|----------------------------|
|**Subclass Instance Method**| Overrides                    | compile error              |
|**Subclass Static Method**  | compile error                | Hides                      |


### Exception

> What is an **Exception**?

- An exception is a problem that arises during the execution of a program. Exceptions are caught by handlers positioned along the thread's method invocation stack.


> Explain **Checked Exceptions** and **Unchecked Exceptions**?

- **Checked Exceptions**:
    * must be explicitly checked at compile time, checked means caught (try..catch..finally) or propagated (throws Exception).
    * typically a user error or a problem that cannot be forseen by the programmer. For example, if a file is to be opened, but the file cannot be found, an exception occurs.
    * extends java.lang.Exception
- **Unchecked Exceptions**:
    * doesn't have to be checked at compile time, checked means caught or propagated.
    * probably could have been avoided by the programmer.
    * extends java.lang.RuntimeException
- Which one is better?
    * If a client can reasonably be expected to recover from an exception ==> use checked exception.
    * If a client cannot do anything to recover from the exception ==> use unchecked exception.
    * Both have their own benefits and use cases. It's an [open discussion](http://tutorials.jenkov.com/java-exception-handling/checked-or-unchecked-exceptions.html#checked-or-unchecked-exceptions).


> What are the two main subclasses under **Exception** class?

- IOException class
- RuntimeException class


> Compare keywords, **throws** vs. **throw**?

- **throws**: if a method does not handle a checked exception, the method must declare it using **throws** keyword, e.g.
```java
    public void write() throws IOException { ... }
```
- **throw**: used to trigger an exception, either a newly instantiated one or an exception that you just caught, by using **throw** keyword, e.g.
```java
    throw new Exception(errMsg);
```


> How to handle Java Exceptions?

- try { ... } catch { ... } finally { ... }, e.g.
```java
    public void openFile(){
        FileReader reader = null;
        try {
            // read file into reader
        } catch (IOException e) {
            // do sth clever with the exception
            e.printStackTrace()
        } finally {
            // finally block always gets executed
            // make sure everything is cleaned up
        }
    }
```


> What is NullPointerException (NPE)?

An NPE is thrown when calling the instance method, accessing/modifying the field of a null object.


> Does it matter in what order catch statements for FileNotFoundException (derived class) and IOException (base class) are written?

Yes, it does. The FileNoFoundException extends the IOException. Exception's subclasses have to be caught first.


> Compare error vs. exception?

- An error is an irrecoverable condition occuring at runtime. e.g. OutOfMemory error. (Error caused by the environment in which application is running)
- An exception is a condition that occur because of bad input etc. e.g. FileNotFoundException, NPE (Exception caused by the application itself)


### Basics

> List some Java **IDEs**?

IntelliJ, Eclipse, vim, emacs, etc.


> What is **method signature** in Java?

- A method signature is the method name and the number and type of its parameters.
- Return types and thrown exceptions are not considered to be part of the method signature. 


> Define **Class**?

A class is a blue print/template, from which individual objects are created.
A class can contain fields and methods to describe the behavior of an object.


> What kind of **variables** a class can consist of? Describe them.

- **Local variable**: variables defined inside methods, constructors, or blocks. The variable that declared and initialized within the method will be destroyed when the mothod has completed.
- **Instance variable**: variables defined inside a class, outside any method. These variables are instantiated when the class is loaded.
- **Class variable/static variable**: variables declared within a class, outside any method, with the static keyword.


> What is **Constructor**?

Constructor gets invoked when a new object is created. Every class has a constructor. If we do not explicitly write one, the Java compiler will build a default constructor for that class.


> Is constructor inherited?

No. A subclass inherits all the members (fields, methods, and nested classes) from its superclass. Constructors are not members, so they are not inherited by subclasses, but the constructor of the superclass can be invoked from the subclass(using super();).


> List the three steps for creating an Object for a class?

- declared
- instantiated
- initialized


> What is [**Access Modifier**](http://tutorials.jenkov.com/java/access-modifiers.html)?

- Java provides access modifiers to set access level for classes, variables, methods, and constructors. A member has package or default accessibility when no access modifier is specified. Here are the four Access Modifiers that Java provides:
    * **private** - Visible to the class only.
    * **default (package)** - (By default) Visible to the package. No modifiers are needed.
    * **protected**: Visible to the package and all subclasses.
    * **public** - Visible to the world
- methods and data members of a class/interface can have one of the above four access specifiers
- classes and interfaces can only have two access specifiers: public and default; There must be only one public class per .java source file and the name of the file must match with this public class.


> What are **order of precedence** and **associativity** and how are they used?

- **Order of precedence** determines the order in which operators are evaluated in expressions.
- **Associativity** determines whether an expression is evaluated left-to-right or right-to-left.


> According to Java [**Operator precedence**](https://docs.oracle.com/javase/tutorial/java/nutsandbolts/operators.html), which operator has the highest precedence?

Postfix operators, i.e. () [].


> Compare **String**, **StringBuilder**, and **StringBuffer**?

 - **String** class is **immutable** and **thread-safe**, so that once it is created a String object cannot be changed. Since String is immutable, it can safely be shared between many threads, which is considered very important for multi-threaded programming.
 - **StringBuffer** class is **mutable** and **thread-safe**, so that modifications to string chars can be made.
 - **StringBuilder** class is **mutable** but **NOT thread-safe**, modifications can also be made to string chars, and it's **faster** than StringBuffer. Use this whenever possible except for the multi-threaded cases.


> What package is used for pattern matching with regular expressions? and what classes does it have?

The **java.util.regex** package primarily consists of the following three classes:
- java.util.regex.Pattern – Used for defining patterns
- java.util.regex.Matcher – Used for performing match operations on text using patterns
- PatternSyntaxException – Used for indicating syntax error in a regular expression pattern
```java
    // A Simple Java program to demonstrate working of
    // String matching in Java
    import java.util.regex.Matcher;
    import java.util.regex.Pattern;
     
    class RegexDemo
    {
        public static void main(String args[])
        {
            // Create a pattern to be searched
            Pattern pattern = Pattern.compile("ge*");
     
            // Search above pattern in given string
            Matcher m = pattern.matcher("geeksforgeeks.org");
     
            // Print starting and ending indexes of the pattern in given string
            while (m.find())
                System.out.println("Pattern found from " + m.start() + " to " + (m.end()-1));
        }
    }
Output:
Pattern found from 0 to 2   //gee
Pattern found from 8 to 10  //gee
Pattern found from 16 to 16 //g

```


> What is finalized() method?

It is possible to define a method that will be called just before an object's final destruction by the garbage collector (GC). This method is called finalize(), and it's used to ensure that an object terminates cleanly.



> Define **Packages** in Java?

A Package is defined as a grouping of related types (classes, interfaces, enumerations, and annotations) providing access protection and name space management.


> Why **Packages** are used?

- prevent naming conflicts
- access control
- make searching/locating and usage classes, interfaces, enumerations, annotations, etc. easier


> Explain **garbage collection** in Java?

GC is used to free the memory. It's cleaning objects that is no longer referenced by any of the program.


> Explain **Set** Interface?

It is a collection of elements that cannot contain duplicate elements.


> Compare **HashSet** vs. **TreeSet** vs. **LinkedHashSet**?

- HashSet: no duplicate elements.
- TreeSet: no duplicate elements + in sorted order.
- LinkedHashSet: no duplicate elements + in insertion order.


> Compare [**Comparable** Interface vs. **Comparator** Interface](http://www.programcreek.com/2011/12/examples-to-demonstrate-comparable-vs-comparator-in-java/)?

- **Comparable** interface is implemented by a class itself in order to compare itself with some other objects.
```java
    class Dog implements Comparable<Dog>{
        int size;
        Dog(int s) { size = s; }
        @Override
        public int compareTo(Dog other) {
            return other.size - this.size;
        }
    }
    public class Main{
        public static void main(String[] args) {
            TreeSet<Dog> d = new TreeSet<Dog>();
            d.add(new Dog(1));
            d.add(new Dog(2));
            ...
        }
    }
```
- In some situations, you may not want to change a class and make it comparable. In such cases, **Comparator** can be used if you want to compare objects based on certain attributes/fields.
```java
    class Dog {
        int size;
        Dog(int s) { size = s; }
    }
    class SizeComparator implements Comparator<Dog> {
        @Override
        public int compare(Dog d1, Dog d2) {
            return d1.size - d2.size;
        }
    }
    class Main {
        public static void main(String[] args) {
            TreeSet<Dog> d = new TreeSet<Dog>(new SizeComparator()); // pass comparator
            d.add(new Dog(1));
            d.add(new Dog(2));
            ...
    }
}
```


> Explain the following line:
**public static void main (String args[ ])**

- public - access modifier
- static - allows main() to be called without instantiating an instance of a class
- void - tells the compiler that no value is returned by main()
- main() - method called at the beginning of a Java program
- String args[] - an instance of String arrays passed as args


> Define **JVM**, i.e. Java Virtual Machine?

JVM is the virtual machine that runs the Java bytecodes (.class files). It interprets the bytecodes into the machine code depending on the underlying operating system and hardware combination. It allows Java to be a "portable language" (write once, run anywhere).
JVM has three notions:
- specification  - describes requirements of the JVM implementation, so that all implementations are interoperable.
- implementation - a computer program that meets the requirements of the JVM specification. 
- instance       - an implementation running in a process that executes a computer program compiled into Java bytecodes.


> Define **JRE**, i.e. Java Runtime Environment?

JRE is an implementation of the JVM which executes Java programs. It provides the minimum requirements for executing a Java application.


> Define **JDK**, i.e. Java Development Kit?

JDK has a complete JRE and besides a collection of programming tools for development:
- javac: Java Compiler, which converts source code to Java bytecodes.
- java: loader of Java App; interpreter that interpretes class file generated by javac.
- jar: the archiver, which packages related class libs into a single JAR file.
- jdb: the debugger.
- javadoc: doc generater, which automatically generates doc from source code.


> Compare **JVM**, **JRE**, **JDK**?

JDK (JRE + dev libs/tools) > JRE (JVM + class libs) > JVM


> What is **JAR** file, i.e. Java Archive file?

JAR file is used to aggregates many files into one. It holds Java classes in a library. JAR files are built on ZIP file format and have .jar file extension.


> What is **WAR** file, i.e. Web Archive file?

WAR file is used to store XML, java classes, and Java Server pages (JSP), which is used to distribute a collection of JavaServer Pages, Java Servlet, Java classes, XML files, static Web pages etc.


> Define [**JIT**](http://whatis.techtarget.com/definition/just-in-time-compiler-JIT) compiler, i.e. just-in-time compiler?

- JIT compiler is a program that turns Java bytecode (a program that contains instructions that must be interpreted) into instructions that can be sent directly to the processor.


> How Java program gets executed?

- **(Java Compiler) src codes -> bytecode**: Java compiler compiles Java src codes into bytecode, rather than machine code that contains instructions that match a particular hardware platform's processor (e.g. Pentium, IBM processor etc.) The bytecode is platform-independent code that can be sent to any platform and run on that platform.
- **(JIT) bytecode -> instructions**: While the virtual machine handles one bytecode instruction at a time. Using the Java JIT compiler (really a second compiler) at the particular system platform compiles the bytecode into the particular system code (as though the program had been compiled initially on that platform). Once the code has been (re-)compiled by the JIT compiler, it will usually run more quickly in the computer.



> What is **final keyword**?

- **final variable**: can only be assigned once; If the variable is a reference, it cannot be re-bound to reference other object.
- **final method**: used in superclass to disallow overiding in subclass.
- **final class**: A final class cannot be extended.


> How many bits are used to represent Unicode, ASCII, UTF-8, UTF-16 characters?

- Unicode - 16 bits
- ASCII   - 7 bits/8 bits
- UTF-8   - 8, 16, 18 bit patterns
- UTF-16  - 16 bit and larger bit patterns


> What are Wrapper Classes?

These are classes that allow primitive types to be accesssed at objects. e.g. Integer, Character, Double, Boolean, etc.


> Why do we need Wrapper Classes?

We can pass them around as method parameters where a method expects an object. It also provides utility methods.


> What is the purpose of **File class**?

It is used to create objects that provide access to the files and directories of a local file system.


> Compare Reader/Writer class hierarchy vs. InputStream/OutputStream class hierarchy?

- The Reader/Writer class hierarchy is **character-oriented**.
- The InputStream/OutputStream class hierarchy is **byte-oriented**.


> What is **Serialization** and **Deserialization**?

- Serialization is the process of writing the state of an object to a byte stream.
- Deserialization is the process of restoring these objects.


> Compare sleep() method vs. wait() method?

- sleep(2000) puts thread aside for exactly two seconds.
- wait(2000) causes a wait of **up to** two seconds. A thread could stop waiting if it receives the notify() or notifyAll() call.
- sleep() is defined in the class Thread.
- wait() is defined in the class Object.


> What is **private variable**?

A private variable is a variable that can only be accessed within the class in which it is declared.


> Can constructor be inherited?

No, constructor cannot be inherited.  
Unlike fields, methods, and nested classes ,Constructors are not class members. A subclass inherits all the members (fields, methods, and nested classes) from its superclass. Constructors are not members, so they are not inherited by subclasses, but the constructor of the superclass can be invoked from the subclass.


> What are the advantages of ArrayList over arrays?

- ArrayList can grow dynamically
- ArrayList provides more powerful insertion and search mechanisms.


> What is dot operater (.)?

- It is used to access the variables and methods of class objects.
- It is also used to access classes and sub-pakcages from a package.


> Does Java allow Default Arguments?

No, Java does NOT allow Default Arguments.


### OOP concepts

> Explain the use of **subclass** in Java?

Subclass inherits all public, protected, and default/package modifier methods, along with their implementations.


> Define **Inheritance**?

It's the process where one object acquires the properties (public and protected fields & methods) of another. With the use of inheritance, the information is made manageable **in a hierarchical order**.


> Explain private members in Java inheritance?

Only the public and protected member are inherited. A subclass does not inherit the private members of its parent class. However, if the superclass has public or protected methods for accessing its private fields, these can also be used by the subclass.


> What happens when more restrictive access is given to a derived class method in Java?

Compile error. The method defined in subclass cannot be more restrictive than overiden method in superclass.


> Compare Inheritance in C++ vs. Inheritance in Java?

- default superclass
    * In Java, all classes inherit from the Object class directly or indirectly. (class extends Object by default) Therefore, there is always a single inheritance tree of classes in Java.
    * C++ doesn't have default superclass.
- inheritance specifiers
    * Java does't have inheritance specifiers.
    * C++ provides inheritance specifiers like public, protected or private.
- virtual method (allow overriding)
    * Java doesn't have virtual keyword. Methods behave like virtual methods by default. Use final keyword to methods to forbid overiding.
    * In C++, method are non-virtual by default. We need to explicitly use virtual keyword.
- multiple inheritance
    * Java does't support multiple inheritance. A class cannot inherit from multiple classes. A class can implement multiple interfaces though.
    * C++ supports multiple inheritance.
- In Java, members of the grandparent class are not directly accessible. [REF](http://www.geeksforgeeks.org/g-fact-91/)


> Define **Composition**?

Composition uses instance variables to refer to other objects, so that you can use the properties (fields & methods) of another class.


> Compare [**Inheritance** vs. **Composition**](http://www.artima.com/designtechniques/compoinh3.html)?

- They both are used to establish relationships between classes.
- Inheritance is an "is-a" relationship. Composition is a "has-a" relationship.
- Composition is a bit more flexible and has stronger encapsulation.
```java
    // Inheritance example
    class Fruit {
        public int peel() {
            System.out.println("Peeling is appealing.");
            return 1;
        }
    }
    class Apple extends Fruit { }
    class InheritanceDemo {
        public static void main(String[] args) {
            Apple apple = new Apple();
            int pieces = apple.peel();
        }
    }
```
```java
    // Composition example
    class Fruit {
        public int peel() {
            System.out.println("Peeling is appealing.");
            return 1;
        }
    }
    class Apple {
        private Fruit fruit = new Fruit();
        public int peel() {
            return fruit.peel();
        }
    }
    class CompositionDemo {
        public static void main(String[] args) {
            Apple apple = new Apple();
            int pieces = apple.peel();
        }
    }
```


> When is **super** keyword used?

- calls parameterized contructor of superclass ([super(args..);](http://www.geeksforgeeks.org/g-fact-67/))
- overrides one of its superclass's method (super.method())
- refers to a hidden field (super.value)

- 1. (super.method() && super.value) It is used to differentiate the members of superclass from the members fo subclass, if they have same name.
- 2. (super(args..)) It is uesd to invoke the superclass constructor from subclass. (If a class is inheriting the properties of another class, the subclass automatically acquires the default constructor of the super class. But if you want to call a parametrized constructor of the super class, you need to use the super keyword.)


> What is [**Polymorphism**](http://www.sitepoint.com/quick-guide-to-polymorphism-in-java/)?

Polymorphism describes a language’s ability to process objects of various types and classes through a single, uniform interface. There are two forms of polymorphism in Java:
- **Compile time polymorphism (static binding)**: achived by **Method Overloading**, which means there are several methods present in a class having the same name but different types/order/number of parameters. (methods cannot be overloaded according to return type.)
```java
    class DemoOverload{
        // method 1
        public int add(int x, int y){ return x+y; }
        // method 2
        public int add(int x, int y, int z){ return x+y+z; }
        // method 3
        public int add(double x, int y){ return (int)x+y; }
    }
```
- **Runtime polymorphism (dynamic binding/late binding)**: achieved by **Method Overriding**, which means a sub class overrides a particular method of the super class. The binding of a method call to a object is not known until the time of the call at run-time.
```java
    class Parent{
        public void talk(){
            System.out.println("I'm Parent.");
        }
    }
    class Child extends Parent{
        public void talk(){
            super.talk(); // invokes the super class method
            System.out.println("I'm Child.");
        }
    }
    class Main{
        public static void main(String[] args){
            Parent obj = new Child();
            obj.talk();
            // prints I'm Parent.   -- super call
            // prints I'm Child.    -- sub class overrides super class's method
            obj = new Parent();
            obj.talk();    // prints I'm Parent.
        }
    }
```


> What is **Encapsulation**?

It is the technique of making the fields in a class private and providing access to the fields via public methods **(getters, setters)**. If a field is declared private, it cannot be accessed by anyone outside the class, thereby hiding the fields within the class. Therefore, encapsulation is also referred to as **Data Hiding**.

It is a mechanism of wrapping the data(variables) and code acting on the data(methods) together as single unit. In encapsulation the variables of a class will be hidden from other classes, and can be accessed only through the methods of their current class, therefore it is also know as data hiding.

```java
    public class EncapTest{
       private String name;
       private String idNum;
       private int age;
    
       public int getAge() {return age;}
       public String getName() {return name;}
       public String getIdNum() {return idNum;}
       public void setAge( int newAge) {age = newAge;}
       public void setName(String newName) {name = newName;}
       public void setIdNum( String newId) {idNum = newId;}
    }
```

> Benefits of **Encapsulation**?

- The fields of a class can be made read-only or write-only.
- A class can have total control over what is stored in its fields.
- The users of a class do not know how the class stores its data. A class can change the data type of a field and users of the class do not need to change any of their code.


> What is **Abstraction**?

Abstraction is used to hide certain details and only show the essential features of the object. i.e. it deals with the outside view of an object (interface). It helps to reduce the complexity and also improves the maintainability.


> What is [**Abstract class** and **Abstract method**](https://docs.oracle.com/javase/tutorial/java/IandI/abstract.html)?

- **Abstract class**: a class cannot be instantiated, but can be subclassed. Abstract class usually contains abstract methods.
- **Abstract method**: a method that is declared without an implementation (without braces, and followed by a semicolon)
- When an abstract class is subclassed, the subclass usually provides implementations for all of the abstract methods in its parent class. However, if it does not, then the subclass must also be declared abstract.
```java
    // Abstract class
    abstract class GraphicObject {
        // declare fields and non-abstract methods
        int x, y;
        void moveTo(int newX, int newY) { ... }
        // declare abstract methods
        abstract void draw();
        abstract void resize();
    }
    class Circle extends GraphicObject {
        // implements parent's abstract methods
        void draw() { ... }
        void resize() { ... }
    }
    class Rectangle extends GraphicObject {
        // implements parent's abstract methods
        void draw() { ... }
        void resize() { ... }
    }
    abstract class RectangularObject extends GraphicObject {
        // provides only partial implementations to parent's abstract methods,
        // therefore has to de declared as abstract class
        void draw() { ... }
    }
```


> What is [**Interface**](https://docs.oracle.com/javase/tutorial/java/IandI/createinterface.html)?

An interface is a collection of abstract methods. A class implements an interface, thereby inheriting the abstract methods of the interface.
- Interface cannot be instantiated, and doesn't contain constructor function.
- All methods in an Inteface are automatically abstract.
- Define an Interface. e.g.
```java
    public interface OperateCar {
       // constant declarations, if any
       // method signatures
       int turn(Direction direction);
       int changeLanes(Direction direction);
       ...
    }
```
- Use an Interface. e.g.
```java
    public class OperateBMW760i implements OperateCar {
        // implement all methods defined in Interface
        int turn(Direction direction) { ... };
        int changeLanes(Direction direction) { ... };
    }
```


> Compare **Abstract class** vs. **Interface**?

- With interfaces, all fields are automatically public, static, and final, and all methods that you declare or define (as default methods) are public.
- You can extend only one class, whether or not it is abstract, whereas you can implement any number of interfaces.


### OO Design Pattern

> What is a **Singleton** class?

A class that can only have one object created. Usually used as a single Manager class, e.g. manager for DB connection, etc.
```java
    class MySingleton {
        private static MySingleton instance = null;
       
        private MySingleton() { ... };
      
        // Factory method to provide the users with instances
        public static MySingleton getInstance() {
            if (instance == null)        
                 instance = new MySingleton();
            return instance;
        } 

        public static void main(String args[]) {
            MySingleton a = MySingleton.getInstance();
            MySingleton b = MySingleton.getInstance();
            System.out.println(a == b); // prints true
        }    
    }
```


### Thread

> What are the two ways that Thread can be created?

- implementing Runnable interface
- extending Thread class


> List Java's [Thread.State](https://docs.oracle.com/javase/7/docs/api/java/lang/Thread.State.html)?

- NEW: a thread has not yet started
- RUNNABLE: a thread is executing in the JVM
- BLOCKED: a thread is blocked waiting for a monitor lock
- WAITING: a thread is waiting **indefinitely** for another thread to perform a particular action
- TIMED_WAITING: a thread is waiting **till timeout** for another thread to perform a particular action
- TERMINATED: a thread has exited


> What invokes a thread's run() method?

After a thread is started, via its start() method of the Thread class, the JVM invokes the thread's run() method when the thread is initially executed.


> What are the ways in which a thread can enter the waiting state?

- by invoking its sleep() method
- by blocking on IO
- by unsuccessfully attempting to acquire an object's lock
- by invoking an object's wait() method
- (deprecated) invoking suspend() method



### Multithreading

> What is **synchronization**?

Synchronization is the capability to control the access of multiple threads to shared resources. **synchronized** keyword in Java provides locking which ensures mutual exclusive access of shared resource and prevent data race.


> What is **synchronized** Non Access Modifier?

Java provides such modifier for providing funtionalities other than Access Modifiers. **synchronized** is used to indicate that a method can be accessed by only one thread at a time.


> What are **synchronized methods** and **synchronized statements**?

- Synchronized methods are methods that are used to control access to an object.
- A synchronized statement can only be executed after a thread has acquired the lock for the object or class referenced in the synchronized statement.













