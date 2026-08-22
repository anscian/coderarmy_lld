## Single Responsibility Principle (SRP)
- class should only have one responsibility
- thus would need only one reason to change

## Open-Close Principle (OCP)
- class should be open for extension but close for modification
- uses abstraction, inheritance and polymorphism

## Liskov Substitution Principle (LSP)
- subclasses should be substitutable for their base classes
- thus subclass always exapands base class features
- Goal is to support the client when it uses objects in generalization of their parent class
- Guidelines:
    - **Signature Rule**: signature of overriding method in sub-class should use same signature as parent with each argument as one of the anscestors or same as of argument class in parent class declaration
        - **Return Type Rule**: return type of overriding method in sub-class should return same or child class of the return type of the same method in parent class. When child class is used, its called **Covariance**
        - **Exception Rule**: exception raised by overriden sub-class methods must be of same or child of exception thrown by same method in parent class
    - **Property Rule**
        - **Class Invariant**: An invariant in parent class must be enforeced or strengthened furthur by its child class
        - **History Invariant**: Any constraint set by parent class on behavior of the class should be obeyed by child class
    - **Method Rule**
        - **Pre-Condition**: If parent sets some pre-conditions before its method, then the child should either enforce same or weaker version of this pre-condition
        - **Post-Condition**: If parent sets some post-conditions after its method, then the child should either enforce or strengthen the post-condition

## Interface Segregation Principle (ISP)
- many client specific interfaces are better than one general purpose interface
- client should not be forced to implement methods they don't need

## Dependency Inversion Principle (DIP)
