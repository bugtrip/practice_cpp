# Practice

1. Valid parentheses.

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
- Open brackets must be closed by the same type of brackets.
- Open brackets must be closed in the correct order.
- Every close bracket has a corresponding open bracket of the same type.

2. Game field.

Write a program where a 10x10 two-dimensional game field is created, and 12 'mines' are randomly placed such that they do not touch each other (there should be no mines in the neighboring cells of a mine). The game field should be represented as a two-dimensional array, with the type char and size 10x10. Empty cells (without mines) should be assigned the value 0, while cells containing mines should be marked with the symbol '*'.

3. Roman to integer

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
Symbol Value
I      1
V      5
X      10
L      50
C      100
D      500
M      1000

For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.
