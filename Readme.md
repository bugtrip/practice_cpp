# Practice (C++)

1. Remove duplicates from sorted list

Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
The list is guaranteed to be sorted in ascending order.
Definition for singly-linked list.
```
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
```
__________________________________________________________

2. Valid parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
- Open brackets must be closed by the same type of brackets.
- Open brackets must be closed in the correct order.
- Every close bracket has a corresponding open bracket of the same type.
__________________________________________________________

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
__________________________________________________________

4. Length of Last Word

Given a string 's' consisting of words and spaces, return the length of the last word in the string.
A word is a maximal substring consisting of non-space characters only.

Constraints:
- 1 <= s.length <= 10^4
- 's' consists of only English letters and spaces ' '.
- There will be at least one word in 's'.
__________________________________________________________

5. Template-based vector deletion

Implement a template function that takes the following parameters:
- a value x of type `T`
- a vector `arr` of type `T`
- a filter function

The function should iterate through the vector and compare each element with the value x. If an element is equal to x, it must be removed from the vector. Also, implement a separate function that prints out all elements of the vector.
__________________________________________________________

6. 
