/*
Imagine you have a special keyboard with the following keys: 

Key 1:  Prints 'A' on screen
Key 2: (Ctrl-A): Select screen
Key 3: (Ctrl-C): Copy selection to buffer
Key 4: (Ctrl-V): Print buffer on screen appending it after what has already been printed.

Find maximum numbers of A's that can be produced by pressing keys on the special keyboard N times. 


Example 1:

Input: N = 3
Output: 3
Explaination: Press key 1 three times.

Example 2:

Input: N = 7
Output: 9
Explaination: The best key sequence is 
key 1, key 1, key 1, key 2, key 3,
key4, key 4.

Your Task:
You do not need to read input or print anything. Your task is to complete the 
function optimalKeys() which takes N as input parameter and returns the maximum number of
A's that can be on the screen after performing N operations.


Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)
a) For N < 7, the output is N itself.

b) Ctrl V can be used multiple times to print current buffer (See last two examples above). 
The idea is to compute the optimal string length for N keystrokes by using a simple insight. 
The sequence of N keystrokes which produces an optimal string length will end with a suffix 
of Ctrl-A, a Ctrl-C, followed by only Ctrl-V’s . (For N > 6)

The task is to find out the break=point after which we get the above suffix of keystrokes. 
Definition of a breakpoint is that instance after which we need to only press Ctrl-A, Ctrl-C 
once and the only Ctrl-V’s afterwards to generate the optimal length. If we loop from N-3 to
1 and choose each of these values for the break-point, and compute that optimal string they
would produce. Once the loop ends, we will have the maximum of the optimal lengths for various 
breakpoints, thereby giving us the optimal length for N keystrokes.
*/
