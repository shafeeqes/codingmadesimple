//nth catalan number
/*
Given a number A, return number of ways you can draw A chords in a circle with 2 x A points such that no 2 chords intersect.

Two ways are different if there exists a chord which is present in one way and not in other.

Return the answer modulo 109 + 7.



Input Format:

The first and the only argument contains the integer A.
Output Format:

Return an integer answering the query as described in the problem statement.
Constraints:

1 <= A <= 1000
Examples:

Input 1:
    A = 1

Output 1:
    1

Explanation 1:
    If points are numbered 1 to 2 in clockwise direction, then different ways to draw chords are:
    {(1-2)} only.
    So, we return 1.

Input 2:
    A = 2

Output 2:
    2

Explanation 2:
    If points are numbered 1 to 4 in clockwise direction, then different ways to draw chords are:
    {(1-2), (3-4)} and {(1-4), (2-3)}.
    So, we return 2.
*/
/*
//Catalan no.
C0=1  and \ Cn+1= sum_{i=0 to n} Ci * Cn-i \ for n>=0;    
C0 = 1
C1 = 1
C2 = C0*C1 + C1*C0 = 2
C3 = C0*C2+ C1*C1+ C2*C0
C4 = C0*C3+ C1*C2+ C2*C1+ C3*C0

*/
//O(n^2)
int Solution::chordCnt(int n){
    long long int dp[n+1];
   
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2;i <= n; i++){
        dp[i] = 0;
        for(int  k = 0; k < i; k++){
            dp[i]= (dp[i] + dp[i-k-1] * dp[k]) % 1000000007;
        }
    }
    return dp[n] % 1000000007;
}

//O(n)
BINOMIAL COEFFICIENT:-
// C++ program for nth Catalan Number 
#include<iostream> 
using namespace std; 

// Returns value of Binomial Coefficient C(n, k) 
unsigned long int binomialCoeff(unsigned int n, unsigned int k) 
{ 
	unsigned long int res = 1; 

	// Since C(n, k) = C(n, n-k) 
	if (k > n - k) 
		k = n - k; 

	// Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1] 
	for (int i = 0; i < k; ++i) 
	{ 
		res *= (n - i); 
		res /= (i + 1); 
	} 

	return res; 
} 

// A Binomial coefficient based function to find nth catalan 
// number in O(n) time 
unsigned long int catalan(unsigned int n) 
{ 
	// Calculate value of 2nCn 
	unsigned long int c = binomialCoeff(2*n, n); 

	// return 2nCn/(n+1) 
	return c/(n+1); 
} 
