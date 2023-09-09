HOMEWORK 3: CONNECT FOUR


NAME:  < Matthew Oh >


ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < 9 >


ORDER NOTATION:
For each of the functions below, write the order notation O().
Write each answer in terms of m = the number of rows and n = the
number of columns.  You should assume that calling new [] or delete []
on an array will take time proportional to the number of elements in
the array.

insert O(2n*m)

insert O(n*m)

numTokensInColum O(n)

numTokensInRow O(m)

numColumns O(1)

numRows O(1)

print O(n*m)

clear O(n)


TESTING & DEBUGGING STRATEGY: 
Discuss your strategy for testing & debugging your program.  
What tools did you use (gdb/lldb/Visual Studio debugger,
Valgrind/Dr. Memory, std::cout & print, etc.)?  How did you test the
"corner cases" of your Matrix class design & implementation?

Used Valgrind to look for memory leaks, and used lldb to look for more information on errors.


