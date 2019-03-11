# Multiplication-Boards-and-Number-Formatting
1st assignment from year 1, 2nd semester of Computer Science

(C)

This assignment has 2 parts to it:

**Question 1:

A. Write a program that prints out a 10x10 multiplication table.
B. Write a program that recieves as input a number 'MaxMult', & prints out the corresponding MaxMulti x MaxMulti multiplication table.

EX:

for MaxMult = 4, the program would print out:

 1 2  3  4
 2 4  6  8
 3 6  9 12
 4 8 12 16


*Notes:
- All printouts must be in table form, & each instance must be alligned correctly to the right (each digit above and under the correct ones
from all lines).
- Refrain from adding too many spaces (number on the bottom right should have 1 space before it).


**Question 2:

Write the function: 'void printFormattedIntegers(char* format, char* numbers)'

The function receives as input:
1) char array 'format'   - contains the printing format for numbers
2) char array 'numbers'  - contains several (matching in number to the formatters) decimal numbers with an uncertain number of whitespaces between them.

The functions must printout all text from 'format', with the numbers from array 'numbers' in the correct formatting dictated (by order) instaed of the '%' formatters in array 'format'.

Possible formatters:
- %d - converts 'int' to decimal
- %x - converts 'int' to hexadecimal
- %o - converts 'int' to octal
- %b - converts 'int' to binary
- %r - converts 'int' to roman numerals

EX:

For 'printFormattedIntegers("Dec: %d Hex: %x Roman: %r"," 123 10 9")'
The function will printout: "Dec: 123 Hex: A Roman: IX"

For 'printFormattedIntegers("%b in Binary is %o in Octal" ,"18 18")'
The function will printout: "10010 in Binary is 22 in Octal"

