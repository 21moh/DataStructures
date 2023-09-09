HOMEWORK 4: Pizza Event SimulaTOr (PESto)


NAME:  < Matthew Oh >


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

< Maia Di Scala, Danny Kim >

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.


ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < 10 >


ORDER NOTATION:
For each function, using the variables:

  c = number of items still being cooked
  d = number of items completely cooked, but not yet added to an order
  m = number of different item names available
  o = number of orders that have not been filled and are not expired
  p = min number of items per order
  q = max number of items per order

Include a short description of your order notation analysis.

add_order: O(n)

add_item: O(n)

print_orders_by_time: O(o * q)

print_orders_by_id: O(o * q)

print_kitchen_is_cooking: O(c)

print_kitchen_has_completed: O(d)

run_until_next: O(n^q)

run_for_time: O(n^q)



MISC. COMMENTS TO GRADER:  
Optional, please be concise!






