HOMEWORK 6: STAR BATTLE


NAME:  < Matthew Oh >



COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

< Danny Kim, Maia Di Scala, Jason Chen, Tevin Zhu >

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.



ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < 10 >



ANALYSIS OF PERFORMANCE OF YOUR ALGORITHM:
(running time order notation & concise paragraph, < 200 words)
The dimensions of the board (w and h) 
The number of zones (z)? 
The average number of squares in a zone (t) 
The number of stars per zone(s)? 
etc.


I iterate through the entire board while holding a vector class that holds the string letter of each zone. It keeps track of the number of occurances it appears on the original board, and keeps track of the number stars on the board the class is being used on at the given time. In my vector I have each zone sorted by its size(occurances) and solve the grid by solving from the smallest to largest in my loop throughout the grid. Whenever I reach the desired zone letter, I call my recursion function which calls a column/row/diagonal checker which is O(n)


for sporcle1

Number of solutions: 1

Solution 1:
aab@b
@bbcc
dd@cc
edec@
e@ecc

for puzzle original:
aabbb
abbcc
dddcc
edecc
eeecc

PARAMETERS:
- each row has s stars, each star being represented by a "@"
- no stars can be touching (even diagonally)
- one group of letters is one zone, and each zone should
  have s stars
- Each row can have no more than S stars in it
- Each column can have no more than S stars in it




define output mode: 
define solution mode:

./a.out [input file] [output file] [stars per zone] [output mode] [solution mode]

input file example: sporcle1.txt
output file example: out
stars per zone example: 1,2,3, any number
output mode: "Print" or "Count"
solution mode: "One_solution" or "All_solutions"




MISC. COMMENTS TO GRADER:  
(optional, please be concise!)


