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
/*
It turns out that for N greater than or equal to 7, to produce maximum number of As, the sequence
of N keystrokes that will be used will always end with a suffix of Ctrl-A, Ctrl-C, followed by all
Ctrl-V's. We have to basically figure out the point(say critical-point) after which we should use
this suffix of Ctrl-A, Ctrl-C, followed by all Ctrl-V's to obtain maximum number of As.

To find out this critical point for input N, we try out each of the values from N-3 to 1 and 
compute the number of As that are produced after making a value as critical point and then 
appending it with the suffix of Ctrl-A, Ctrl-C, followed by all Ctrl-V's. While computing maximum
number of As possible with each trial critical point(from N-3 to 1) plus above suffix of Ctrl-A, 
Ctrl-C, followed by all Ctrl-V's, we use maximum number of As already computed for each value(N-3 to 1).

Say f(N) denotes the maximum number of As possible for N keystrokes. Let use see how do we compute
f(N) for N = 7.  

First we choose critical point 'N_critical' as 4. We already know the value of f(4) which is 4. 
For remaining 3 keystrokes, we use Ctrl-A, Ctrl-C, Ctrl-V. The string of keystrokes produced will
be A,A,A,A,Ctrl-A,Ctrl-C, Ctrl-V. These last 3 keystrokes essentially double the value of f(4). 
Hence for 'N_critical = 4', we get 8 number of As which is 2*f(4).

Now we choose critical point 'N_critical' as 3. We already know the value of f(3) which is 3. For 
remaining 4 keystrokes, we use Ctrl-A, Ctrl-C, Ctrl-V, Ctrl-V. The string of keystrokes produced 
will be A,A,A,Ctrl-A,Ctrl-C, Ctrl-V, Ctrl-V. These last 4 keystrokes essentially triple the value 
of f(3). Hence for 'N_critical = 3', we get 9 number of As which is 3*f(3).

Similarly, for 'N_critical' = 2, we get 4*f(2) number of As which is 8. And for 'N_critical' = 1,
maximum number of As possible is 5*f(1) which is 5.

Therefore choosing 'N_critical' as 3 gives us maximum number of As. In other words, f(7) = 9.

In general,
f(N) = N if N < 7
     = max{2*f(N-3), 3*f(N-4),..., (N-2)*f(1)}

*/

class Solution{
public:
    unsigned long long int optimalKeys(int N){
        // The optimal string length is N when N is smaller than 7 
        if (N <= 6) 
            return N; 
      
         // An array to store result of subproblems 
        long long int screen[N]; 
      
        int b; // To pick a breakpoint 
      
        // Initializing the optimal lengths array for uptil 6 input 
        // strokes. 
        int n; 
        for (n = 1; n <= 6; n++) 
            screen[n - 1] = n; 
      
        // Solve all subproblems in bottom manner 
        for (n = 7; n <= N; n++) { 
            // Initialize length of optimal string for n keystrokes 
            screen[n - 1] = 0; 
      
            // For any keystroke n, we need to loop from n-3 keystrokes 
            // back to 1 keystroke to find a breakpoint 'b' after which we 
            // will have ctrl-a, ctrl-c and then only ctrl-v all the way. 
            for (b = n - 3; b >= 1; b--) { 
                // if the breakpoint is at b'th keystroke then 
                // the optimal string would have length 
                // (n-b-1)*screen[b-1]; 
                int curr = (n - b - 1) * screen[b - 1]; 
                if (curr > screen[n - 1]) 
                    screen[n - 1] = curr; 
            } 
        } 
      
        return screen[N - 1]; 
    }
};
