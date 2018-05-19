# The Java Programming language

## Methods

Methods can have modifiers (such as `public` or `static`)

| descriptor  | class | package | subclass | world |
|-------------|:-----:|:-------:|:--------:|:-----:|
| `private`   |   X   |         |          |       |
|  None       |   X   |    X    |          |       |
| `protected` |   X   |    X    |    X     |       |
| `public`    |   X   |    X    |    X     |   X   |

## Arrays

Arrays can be initialized with or without the initialization of such of its elements
```java
int[] arr = new int[5]; // Each element is initialized to 0
arr = {1, 2, 3, 4, 5}; // Each element is initialized to their respective values
Object[] objArr = new Object[5]; // Each element is initialized to null
// initializes each element with an object
for (int i = 0; i < objArr.length; i++) {
  objArr[i] = new Object();
}
```

## ArrayList

```java
ArrayList<String> names;
// Either is acceptable
names = new ArrayList<String>();
names = new ArrayList<>();

names.add("Foo");
names.get(0);
names.set(0, "Bar");
names.add(0, "Foobar");
// Both are acceptable
for (int i = 0; i < names.size(); i++) {
  String name = names.get(i);
  // Do stuff
}
for (String name : names) {
  // Do stuff
}
```

## I/O

For normal use, use a `Scanner` to read `stdin` and `System.out.println()` to write to `stdout`
**Always close every `Scanner`, even for `stdin`**

### Simple File I/O

Use a `Scanner` to read from a file and a `PrintWriter` to write to it. A `PrintWriter` mimics the `System.out` API

```java
File inputFile = new File("path/to/file");
Scanner in = new Scanner(inputFile);
// in.useDelimiter(''); // Optionally, to read character by character
while (in.haxNext()) {
  String word = in.next();
  // Do stuff
}
in.close();
```

```java
File outputFile = new File("path/to/file");
try {
  PrintWriter out = new PrintWriter(outputFile);
  out.println("Hello world!");
}
catch (Exception e) {
  // Catch some Exception
}
finally {
  out.close();
}
```

## Exception Handling

There are two types of exceptions: unchecked and checked exceptions. Unchecked exceptions are instances of `RuntimeException`, `Error`, or their subclasses.  Checked exceptions require handling or a `throws` declaration, enforced by the compiler.

```java
System.out.println("Start");
try {
  // Any exception in this block will be handled by the appropriate catch block in this block level
  try {
    // Any exception in this block will be handled by the appropriate catch block in this block level
    System.out.println("Let's try this");
    int[] arr = null;
    int foo = 8 / 0; // Throws an ArithmeticException
    foo = arr[0]; // Throws a NullPointerException; Does not execute due to exception before it
  }
  // At least one catch is required
  catch (NullPointerException e) {
    // Only NullPointerException's exceptions are handled here
    // So, in this case, this code will never execute
    System.out.println("Handling NullPointerException");
  }
  // finally is optional
  finally {
    // Always executes:
    //   1. After the successful completion of the try block
    //   2. After the execution of the appropriate catch block in this try-catch-finally bundle
    //   3. Before going up the stack if none of the previous catch blocks can handle the exception
    System.out.println("Executing inner `finally`");
  }
}
catch (ArithmeticException e) {
  // Only ArithmeticException's exceptions are handled here
  // In this case, this code will always executes
  System.out.println("Handling ArithmeticException");
}
finally {
  // Always executes
  // Good for closing `Scanners`
  System.out.println("Executing outer `finally`");
}
System.out.println("End");
```

Output:

```
Start
Let's try this
Executing inner `finally`
Handling ArithmeticException
Executing outer `finally`
End
```

## Classes

A class is a set of objects with the same behavior. Every class has a public interface (a collection of methods which felicitate the manipulation of the object). There are a few types:

- Getters
- Setters
- Mutators

The public interface is needed since each class is encapsulated, that is, the implementation of its methods is hidden from those outside of the class.

### Instance variables

A variable that is a member of a class, then it is called an instance variable (or implicit). Otherwise, it is called an explicit variable.

### Constructors

Every class ought to have a constructor and every instance variable ought to be initialized by it.  Though the instance variables will be initialized by a default constructor if they are forgotten by the primary constructor, the code represents bad practice and ought not to be done.

```java
public class Foo {
  private int foo;
  // Must have the same name as the class
  public Foo() {
    // This provides a default value
    this(0); // must be first statement
  }
  // Can be overloaded
  public Foo(int foo) {
    // the left-side variable is the implicit variable; it refers to the declaration above
    // the right-side assignment is the explicit variable; it is an argument passed to the Constructor
    // if the argument's name did not coincide with the implicit variable's name,
    //   then, the implicit variable could be referenced as `foo` instead of `this.foo`
    this.foo = foo;
  }

  /**
   * A getter
   */
  public void getFoo() {
    return foo;
  }
}
```

### Inheritance

A class can inherit variables and methods from a parent class (a subclass from a superclass). Instance methods can be overloaded; Inherited methods can be overridden (one prime example is to override the `.toString()` method). For example, if the `Comparable` interface (`.compareTo(Foo)` method) is overridden/implemented, an array of `Foo`s can be sorted with `Arrays.sort(Foo[])`. Create a `final` method to prevent overriding.

- Can inherit only one superclass

```java
public class Parent {
  private int foo;
  public void doStuff() {
    doStuff(1);
  }
  // Overload
  public void doStuff(int value) {
    // Do something
  }
}
```
```java
public class Foo extends Parent {
  // When Foo is instantiated, .doStuff can be called on it because Foo extends Parent

  // However, if we need more functionality, we can override it
  @Override
  public void doStuff() {
    super.doStuff(); // Calls to the original doStuff method
    // Do additional stuff
  }

  // It is also tipical to override these methods
  @Override
  public String toString() {
    return "";
  }
  @Override
  public int compareTo(Foo f) {
    // Some real object here
    return 0;
  }
}
```

### Polymorphism & the Substitution Principle

Using inheritance for processing objects of different types in the same program.
**Substitution Principle: You can always use a subclass object when a superclass object is expected**

```java
public class MyClass {
  public void doStuff(Object obj) {
    // obj could be an Object, but it could be a SpecificSubClass as well
    if (obj instanceof SpecificSubClass) {
      // If `obj` is a SpecificSubClass, then its variable can be casted to that type
      // If it is not, the following will produce an exception
      SpecificSubClass newObj = (SpecificSubClass) obj;
    }
  }
}
```

#### `instanceof`

In the form `obj instanceof Foo`, where `Foo` can be a class or an interface.

### Abstraction

The using of only the required details

```java
// This class cannot be instantiated
public abstract class Account { // Must be abstract if contains abstract methods
  // Purposefully unimplemented method; Must be implemented in a sub class
  public abstract void deducFees();
}
public class SavingsAccount extends Account {
  public void deducFees() {
    // Provide an implementation
  }
}
```

### Interface

- Cannot have instance variables
- Can have constants
- A class can have multiple interfaces

Ex: the `Comparable` interface. It enables `java.util.Arrays.sort()` to work.

- `1`: `thisValue > otherValue`
- `0`: `thisValue == otherValue`
- `-1`: `thisValue < otherValue`

```java
// An interface contains the return type, the name, and the parameter variables
interface MyInterface {
  double getMeasure(); // equivalent to `public abstract`; need implementation;
}
```
```java
class BankAccount implements MyInterface {
  private double balance = 0;

  public double getMeasure() {
    return balance;
  }
}
```
```java
public class Foo {
  public static double average(MyInterface[] objects) {
    // Do stuff
    // Works for any class which implements MyInterface
  }
}
```

### Copying

Copying a primitive value is easy (a shallow copy) but copying an object is more involved. A shallow copy of an object copies its memory reference and results in one instance of the object. A deep copy, however, recreates the object by mimicking all of its properties.  One means of doing this is through a copy constructor. Another is through the `.clone()` method, inherited from `Object`.

```java
public class Foo {
  // The following is a copy constructor. It merely copies the properties of the object passed to it
  public Foo(Foo obj) {
    this(obj.getFoo());
  }
}
```

### Cumulative Example

#### `FlightControls.java`
```java
public interface FlightControls {
    // These methods are declared as public and abstract by default
    void setRateOfChangeOfPitch(int rate);
    void setRateOfChangeOfYaw(int rate);
    void setRateOfChangeOfRoll(int rate);
    void setRateOfChangeOfThrust(int rate);
}
```

#### `EngineControls.java`
```java
public interface EngineControls {
    void startEngine();
    void stopEngine();
}
```

#### `Spacecraft.java`
```java
// This is the superclass
public abstract class Spacecraft implements FlightControls, EngineControls {
    // Instance variables
    private int hullHealthPercentage; // Could be initialized here but we'll leave it to a constructor
    private int maximumAgility;
    private int rateOfChangeOfPitch;
    private int rateOfChangeOfYaw;
    private int rateOfChangeOfRoll;
    private int rateOfChangeOfThrust;
    private int flightSpeed;
    private int[] location;

    /**
     * Constructors can be overloaded
     */
    public Spacecraft() {
        // Supplies a default value to the Spacecraft(int) constructor
        // Must be first statement in body
        this(5);
    }

    /**
     * Spacecraft constructor
     */
    public Spacecraft(int maximumAgility) {
        // Initializes all instance variables
        this.hullHealthPercentage = 100;
        this.maximumAgility = maximumAgility;
        this.rateOfChangeOfPitch = 0;
        this.rateOfChangeOfYaw = 0;
        this.rateOfChangeOfRoll = 0;
        this.rateOfChangeOfThrust = 0;
        this.flightSpeed = 0;
        this.location = new int[3];
        // If an instance variable were to be forgotten, it would initialized with a default constructor
        // However, the dependence of the latter is considered bad practice
    }

    /**
     * An instance method
     */
    public void updateLocation() {
        updateLocation(1);
    }

    /**
     * An instance method, which overloads the first
     */
    public void updateLocation(int timeSinceLastComputation) {
        this.location[0] += rateOfChangeOfThrust * rateOfChangeOfThrust * timeSinceLastComputation / 2 + flightSpeed;
        this.location[1] += rateOfChangeOfPitch + rateOfChangeOfYaw;
        this.location[2] += rateOfChangeOfRoll;
    }

    // Instance methods which implement the FlightControls interface
    public void setRateOfChangeOfPitch(int rate) {
        rateOfChangeOfPitch = rate;
    }
    public void setRateOfChangeOfYaw(int rate) {
        rateOfChangeOfYaw = rate;
    }
    public void setRateOfChangeOfRoll(int rate) {
        rateOfChangeOfRoll = rate;
    }
    public void setRateOfChangeOfThrust(int rate) {
        rateOfChangeOfThrust = rate;
    }

    /**
     * Instance methods can be abstract; this forces subclasses to implement them.
     * It must be implemented before any subclasses can be instantiated.
     * This class must be labeled as abstract
     */
    public abstract void hailShip();

    // Getters
    public final int getHullHealthPercentage() { // Cannot be overridden
        return hullHealthPercentage;
    }
    public int getMaximumAgility() {
        return maximumAgility;
    }


    // However, the EngineControls interface is unimplemented so the class must be
    // declared `abstract`
}
```

#### `MillenniumFalcon.java`
```java
public class MillenniumFalcon extends Spacecraft {
    // Instance variables
    private enum EngineStatus {
        stopped, running, hyperdrive
    }
    private EngineStatus engineState;

    /**
     * Constructor
     */
    public MillenniumFalcon(int maximumAgility) {
        // Calls the Spacecraft constructor; Must be the first statement in this body
        super(maximumAgility);
        // Initialize additional instance variables specific to this MillenniumFalcon
        this.engineState = EngineStatus.stopped;
    }

    /**
     * Instance methods
     */
    public void startHyperdrive() {
        engineState = EngineStatus.hyperdrive;
    }
    public void stopHyperdrive() {
        engineState = EngineStatus.running;
    }

    /**
     * Override methods inherited from Spacecraft
     */
    @Override
    public void updateLocation(int timeSinceLastComputation) {
        // Enable support for hyperdrive
        if (engineState != EngineStatus.hyperdrive) {
            super.updateLocation(timeSinceLastComputation);
        }
        else {
            // Use hyperdrive calculations
            super.updateLocation(5 * timeSinceLastComputation);
        }
    }

    // Implement EngineControls interface from Spacecraft
    public void startEngine() {
        engineState = EngineStatus.running;
    }
    public void stopEngine() {
        engineState = EngineStatus.stopped;
    }

    /**
     * Instance method which implements an abstract method from Spacecraft
     */
    public void hailShip() {
        // Do something
    }
}
```

## Packages

A collection of classes. Parent directory of packaged source files must share the package name. Naming could be based on a backwards internet domain name or a backwards internet email address (such as `edu.example.username`). (So, the directory tree must be either `edu/example/username` or `edu.example.username`)

```java
package com.packagename;
```

# Designing Object-Oriented Programs

## Design Process

1. Software requirements
  - Helpful to include typical scenarios
2. Software design
  - Identify nouns and verbs
3. Software construction
4. Software testing
  - checks to see whether requirements are met

Tactical classes: classes which will be used but are not part of the design.

Classes are to be self-documenting (if you cant determine the purpose of a class from its name; perhaps it is off-track)

## CRC Card Method

Make 3-by-5 cards with the following details for each class

- Responsibilities
- Collaborators
  - Relationships of UML diagram

## UML (Unified modeling language)

### Inheritance

    [ source ] ------)> [ operand ]

### Interface implementation

    [ source ] - - - )> [ operand ]

### Dependency

    [ source ] • • • •> [ operand ]

Sometimes abused. ex: a tire should not inherit a circle since not all tires are circles. (Aggregation should be used instead)

### Aggregation

    [ source ] <>------ [ operand ]

Special type of dependency. A dependency, in general, is a means toward an end whereas an aggregation, specifically, uses the dependency in a persistent variable

## Java GUI

### `JFrame([String title])`

- `void setSize(int pixelWidth, int pixelHeight)`
- `void pack()`: Sets to preferred size
- `void setTitle(String title)`
- `void setDefaultCloseOperation(int constant)`
  - Defines what happens when the frame is closed
    - Possible Values (not exhaustive)
      - `static int EXIT_ON_CLOSE`
- `void setVisible(Boolean visibilityStatus)`
- `void add(JComponent component)`

### `JPanel([LayoutManager layoutManager])`

Allows multiple items to be added to a `JFrame` without overlapping each other.

- `void add(JComponent component)`
- `setLayout(LayoutManager layoutManager)`

### `JButton(String text)`

- `void addActionListener(eventListener)`

### `JLabel(String text)`

Like an HTML text node

- `void setText(String)`

### Event Listeners

A class that implements ActionListener. Often implemented as a local class or a nested class.

- `void actionPerformed(ActionEvent event)`

#### `ActionEvent`

- `object getSource()`: Returns the object that caused this action

#### Local classes

A class within a method. Has access to all `final` variables within method. Parameters can be declared as final.

#### Nested classes

A class within a class. Is not declared as `public`. Has access to variables and methods contained in parent block of code, e.g. the outer class.

### `JTextField`

- `String getText()`

### `JTextArea`

- `void append(String text)`
- `void setEditable(Boolean val)`

### `JScrollPane(JTextArea)`



### Drawing

Draw on a component.

```java
public class ChartComponent extends JComponent {
  // Called for every needed graphical update
  public void paintComponent(Graphics g) {
    // Drawing instructions
    g.fillRect(0, 10, 200, 10);
  }
}
```

#### Graphics

- `void fillRect(int x, int y, int width, int height)`
- `void drawOval(int x, int y, int width, int height)`
- `void fillOval(int x, int y, int width, int height)`
- `void drawLine(int x1, int y1, int x2, int y2)`
- `void drawString(String text, int x, int y)`
- `void setColor(Color c)`

To force a call to `paintComponent`: `component.repaint();`

#### `Color(int r, int g, int b)`

### Layout Management

Components are arranged by placing them inside containers (such as a `JPanel`). Each container has its own layout manager.

- `panel.setLayout(new BorderLayout())`

Types of layouts

- `FlowLayout` (`JPanel` default) (left to right and wrap)
- `BorderLayout`
  - Container is divided into regions. (Each region can hold at most one `JComponent`).
    - `static final String BorderLayout.NORTH`
    - `static final String BorderLayout.SOUTH`
    - `static final String BorderLayout.EAST`
    - `static final String BorderLayout.WEST`
    - `static final String BorderLayout.CENTER`
  - How to add: `panel.add(JComponent component, String layoutPositionConstant)`
- `GridLayout(int rows, int cols)`
  - Container is divided into a grid, starting from left to right, up to down. All cells have same width and height.
  - How to add
    - `panel.add(JComponent component)`
- `GridBagLayout`
  - Like `GridLayout` but more complex. Allows for variable column width and merged cells.

### Radio buttons

Think about old radios. You press one button and the others pop out (they are mutually exclusive)

```java
ButtonGroup group = new ButtonGroup();
JRadioButton button1 = new JRadioButton(String text);
group.add(button1);
```

#### `JRadioButton()`

- `Boolean isSelected()`
- `void setSelected(Boolean val)`

### `JCheckBox(String name)`

- `Boolean isSelected()`

### `JComboBox(Object[] items)`

- `void setEditable(Boolean val)`
- `void addItem(Object option)`
- `Object getSelectedItem()`

### Borders

Add to `JPanel`.

Types of borders

- `EtchedBorder()`
- `TitledBorder(EtchedBorder, String title)`

### Menu

```java
JMenuBar bar = new JMenuBar();
JMenu fileMenu = new JMenu("File");
JMenuItem exitItem = new JMenuItem("Exit");

class SomeActionListener implements ActionListener {
  void actionPerformed(ActionEvent e) {
    // Do something
  }
}

exitItem.addActionListener(new SomeActionListener());
fileMenu.add(exitItem);
bar.add(fileMenu);
JFrame.setMenuBar(bar);

// Only menu items trigger events. Can have further submenus
```

## `Timer(int interval, ActionListener obj)`

```java
class SomeActionListener implements ActionListener {
  void actionPerformed(ActionEvent e) {
    // Do something
  }
}

int interval = 60; // milliseconds
Timer timer = new Timer(interval, new SomeActionListener());
timer.start();
// ...
timer.stop();
```

## `MouseListener`

- `void mousePressed(MouseEvent event)`
- `void mouseReleased(MouseEvent event)`
- `void mouseClicked(MouseEvent event)`
- `void mouseEntered(MouseEvent event)`
- `void mouseExited(MouseEvent event)`

```java
component.addMouseListener(MouseListener listener);
```

## `MouseEvent`

- `int getX()`
- `int getY()`

## Raw Notes

Pass variables to Listener constructor for multiple menu items or make class inside method (a local inner class).  A local inner class can access final variables within the method scope (parameters can be declared as final)

Timer class for animations. Generates an event every interval.

Mouse Listeners `implements MouseListener`

- `public void mousePressed(MouseEvent event)`

## Recursion

When a method calls itself. Every recursive call must simplify input to a point where the simplest input is handled through special cases.

Example application: Fibonacci sequence (although a loop is much more efficient for this case)

- $$ f_1 = 1 $$
- $$ f_2 = 1 $$
- $$ f_n = f_{n-1} + f_{n-2} $$

## Backtracking

When a partial solution cannot be correct, one abandons it. Think of a maze, a crossword puzzle, or of system where the solution is constrained by rules.  If you figure out midway that your solution is incorrect, move on to the next one.

Pseudo-code:

```
Examine ( partial solution )
If ( accepted )
  Then add to list of full solutions
Else if ( !abandoned )
  Then for each p in partial solution
  Solve (p)
```

## Random Access File I/O

Each file has a file pointer position. If data is read when this pointer is beyond the contents of the file, then an exception is thrown.

### `RandomAccessFile(File file, String mode)`, `RandomAccessFile(String filename, String mode)`

`mode`: "r" or "rw"

- `void seek(long bytePosition)`
- `long getFilePointer()`
- `void skipBytes(int bytes)`
- `void write(byte val)`: Writes 1 byte
- `void writeChar`: Writes 2 bytes
- `void writeInt`: 4 byte
- `void writeLong`: 8 bytes
- `void writeChars`: 2 bytes per character
- `void writeBytes`: 1 byte per character
- `int read()`
- `byte readByte()`: Reads a `byte` value
- `char readChar()`: Reads a `char` value
- `int readInt()`: Reads
- `long readLong()`

### `InputStream`

1. `FileInputStream(String filename)`
2. `DataInputStream(InputStream fileInputStream)`

## Buffering File I/O

### Buffering input

1. `FileReader(String filename)`
2. `BufferedReader(Reader fileReader)`

#### `BufferedReader(Reader fileReader)`

- `String readLine()`: Check to see if it returns `null`
- `void close()`

### Buffering sequential output

Wraps the `FileWriter` with an output buffer.

1. `FileWriter(String filename, Boolean append)`
2. `BufferedWriter(Writer fileWriter)`
3. `PrintWriter(OutputStream bufferedWriter)`

### Buffering non-sequential output

1. `FileOutputStream(String filename, Boolean append)`
2. `DataOutputStream(OutputStream fileOutputStream)`
3. `BufferedOutputStream(OutputStream dataOutputStream)`

#### `BufferedOutputStream(OutputStream dataOutputStream)`

- `void writeInt(int val)`
- `void writeChars(String str)`
- `void close()`

## Serialization

Saving and reading objects to binary file. The serialized class implements Serializable (an empty interface).

### `ObjectInputStream(InputStream fileInputStream)`

- `Object readObject()`

### `ObjectOutputStream(OutputStream fileOutputStream)`

- `void writeObject(Object obj)`
