/* bit.h * Author: hsahu */
#ifndef BIT_H_
#define BIT_H_
/* ----------- TIPS and TRICKS --------- *\
	n & (n-1)
	n & !(n-1)
	n | (n+1)
	n | !(n+1)
	n | (n - (1<<x))
	n | ~(n - (1<<x))
 */
/*
===========================================================================================
Bit Manipulation
===========================================================================================

 1. Check if a number is a Power of 2.
 2. Multiply by 7, 9
 3. Multiple of 3
 4. Write a function to read bit 31 and 21 of a 32-bit register then clear these bits to 0
	11110000111100001111000011110000
	01110000110100001111000011110000

 5. Write a function to read the upper 16-bit of a 32-bit register then store it in the lower 16-bit
	11110000111100002222000022220000
	11110000111100001111000011110000

 6. How to store a negative value in binary system?
    Represent a negative number in binary system.
    Print a negative number in binary.
 7. Check if a Number is a multiple of 9.
 8. Find the position of only SET bit.
 9. Detect if 2 integers have opposite signs.
10. Count number of Set bits in a number.
11. Check if kth bit is SET or not.
12. Set kth bit in a number.
13. Clear kth bit in a number.
14. Toggle kth bit in a number
15. Clear the LOWEST set bit.
16. Extract the lowest set bit.
17. Clear the lowest bit.
18. Extract the lowest clear bit.
19. What is Little Endian and Big Endian?
 	Write a program to check if the system is Little Endian or Big Endian?
 	Write a program to find the endian ness of the System.

20. Convert x = 0x25 to 0x25252525
21. Swap bits : 01010101 -->
                10101010

22. Calculate the number of 0's / Clear bits in a number.
23. Find the parity of an unsigned number.
    [Parity : Whether a number contains odd or even number of 1 bits]
24. Reverse bits of an Integer number.
25. Add 2 numbers without Arithmetic operation.
26. Print he binary representation of a number.
27. TurnOff the Rightmost bit.
28. Rotate bits of a number.
29. Count the number of flips needed to convert a number from A -> B.
30. Multiply a number by 3.5.
31. Check a number for POWER of 4.
32. Compute modulous division by a power of 2 number.
33.
--------------------------
CTCI
--------------------------
5.1 Insertion:
You are given two 32-bit numbers, N and M, and two bit positions, i and j.
Write a method to insert M into N such that M starts at bit j and ends at bit i.
You can assume that the bits j through i have enough space to fit all of M.
That is,
if M = 10011, you can assume that there are at least 5 bits between j and i.
You would not, for example, have j = 3 and i = 2, because M could not fully fit between bit 3 and bit 2.

EXAMPLE
Input: N 10000000000, M =10011, i = 2, j = 6
Output: N = 10001001100
Hints: #137, #769, #215

5.2 Binary to String:
Given a real number between O and 1 (e.g., 0.72) that is passed in as a double,
print the binary representation.
If the number cannot be represented accurately in binary with at most 32 characters, print "ERROR:'
Hints: #743, #767, #7 73, #269, #297

5.3 Flip Bit to Win:
You have an integer and you can flip exactly one bit from a 0 to a 1.
Write code to find the length of the longest sequence of 1's you could create.
EXAMPLE
Input: 1775
Output: 8 (or: 11011101111)
Hints: #759, #226, #374, #352

5.4 Next Number:
Given a positive integer, print the next smallest and the next largest number that
have the same number of 1 bits in their binary representation.
Hints: #747, #7 75, #242, #372, #339, #358, #375, #390

5.5 Debugger:
Explain what the following code does: ( ( n & ( n-1)) == 0).
Hints:#757,#202,#267,#302,#346,#372,#383,#398

5.6 Conversion:
Write a function to determine the number of bits you would need to flip to convert
integer A to integer B.
EXAMPLE
Input: 29 (or: 11101), 15 (or: 01111)
Output: 2
Hints: #336, #369

5.7 Pairwise Swap:
Write a program to swap odd and even bits in an integer with as few instructions as
possible (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, and so on).
Hints: #745, #248, #328, #355

5.8 Draw Line:
A monochrome screen is stored as a single array of bytes, allowing eight consecutive pixels to be stored in one byte.
The screen has width w, where w is divisible by 8 (that is, no byte will be split across rows).
The height of the screen, of course, can be derived from the length of the array
and the width. Implement a function that draws a horizontal line from (xl, y) to (x2, y).
The method signature should look something like:
drawline(byte[] screen, int width, int xl, int x2, int y)

*/
#endif /* BIT_H_ */
