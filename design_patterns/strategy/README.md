## Problem
For supporting more and more features for a class, the main class gets branched to lot of combinations for those feature usage and the inheritance tree inflates. This causes:-
- Code Reuse
- To add new feature a lot of changes were required
- Breaking OCP

## Strategy Design Pattern
Defines a family of algorithms, put them into separate classes so that they can be changed at run time.
- Separate changing (dynamic) part from static part from a class
- More inheritance doesn't solve problem of inheritance (it complicates the family tree)
- Favor composition over inheritance
