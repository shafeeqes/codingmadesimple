/*Occurrences of a pattern in binary representation of a number
Last Updated: 15-04-2019
Given a string pat and an integer N, the task is to find the number of occurrences of the pattern pat in binary representation of N.

Examples:

Input: N = 2, pat = “101”
Output: 0
Pattern “101” doesn’t occur in the binary representation of 2 (10).

Input: N = 10, pat = “101”
Output: 1
Binary representation of 10 is 1010 and the given pattern occurs only once.

Recommended: Please try your approach on {IDE} first, before moving on to the solution.
Naive Approach: Convert the number into its binary string representation and then use a pattern matching algorithm to 
check the number of times the pattern has occurred in the binary representation.



Efficient Approach:

Convert the binary pattern into it’s decimal representation.
Take an integer all_ones, whose binary representation consists of all set bits (equal to the number of bits in the pattern).
Performing N & all_ones now will leave only the last k bits unchanged (others will be 0) where k is the number of bits in the pattern.
Now if N = pattern, it means that N contained the pattern in the end in its binary representation. So update count = count + 1.
Right shift N by 1 and repeat the previous two steps until N ≥ pattern & N > 0.
Print the count in the end.
Below is the implementation of the above approach:
*/
// C++ program to find the number of times 
// pattern p occurred in binary representation 
// on n. 
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to return the count of occurrence 
// of pat in binary representation of n 
int countPattern(int n, string pat) 
{ 
    // To store decimal value of the pattern 
    int pattern_int = 0; 
  
    int power_two = 1; 
  
    // To store a number that has all ones in 
    // its binary representation and length 
    // of ones equal to length of the pattern 
    int all_ones = 0; 
  
    // Find values of pattern_int and all_ones 
    for (int i = pat.length() - 1; i >= 0; i--) { 
        int current_bit = pat[i] - '0'; 
        pattern_int += (power_two * current_bit); 
        all_ones = all_ones + power_two; 
        power_two = power_two * 2; 
    } 
  
    int count = 0; 
    while (n && n >= pattern_int) { 
  
        // If the pattern occurs in the last 
        // digits of n 
        if ((n & all_ones) == pattern_int) { 
            count++; 
        } 
  
        // Right shift n by 1 bit 
        n = n >> 1; 
    } 
    return count; 
} 
  
// Driver code 
int main() 
{ 
    int n = 500; 
    string pat = "10"; 
    cout << countPattern(n, pat); 
} 
