/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
*/

/*
this explanation is for longest non decereasing subsequence. only change is while comparing put <=

What Is A Subsequence?

A subsequence of an array is a subset of the array that maintains temporal order.

It does not have to be contiguous but it might turn out to be contiguous by chance.


Problem Name / Variants

This problem also comes in the form of asking for the longest strictly decreasing subsequence.

This is longest non-decreasing subsequence meaning that we will have a non-strictly increasing subsequence (aka we can have deltas of 0 between contiguous elements in the subsequence).


Approach 1 (Brute Force)

We can enumerate all 2^n subsets of the original array and then test them for the non-decreasing property.

The answer will be the longest subset that has the property.

This is too expensive.


Approach 2 (Dynamic Programming)

Do you see the potential for a subproblem here?

If you do, then we have the opportunity to use dynamic programming.

Example
[ -1, 3, 4, 5, 2, 8 ]

At the index 0 I always know that I can have a subsequence of length 1.

In fact, at all positions the longest non-decreasing subsequence can be at least length 1.

We then look at index 1, I need to ask myself if the item at index 1 can lengthen the longest subseqence found at index 0.

We check if 3 is greater than or equal to 1...it is. Great. index 1 can be tacked on but...should I?

The LNDS (longest non-decreasing subsequence) at index 1 is 1.

The LNDS at index 0 is 1.

so we add (LNDS at 0) + 1 to LNDS at index 1

Yeah...it makes sense because if I tack 3 onto the LNDS I found for the subproblem of just [ -1 ] then at index 1 I will also have a LDNS.

So what we basically do is build a table and ask ourselves these questions all along the way.

EACH CELL REPRESENTS THE ANSWER TO THE SUBPROBLEM ASKED AGAINST the subsequence from index 0 to index i (including the element at index i).


Complexities:

Time: O( n^2 )

n is the length of the array.

For each of the n elements we will solve the LNDS problem which takes O(n) time, therefore we yield a O( n^2 ) runtime complexity.

Space: O( n )

We will store our answers for each of the n LNDS subproblems.
*/


// O(n^2) solution

class Solution {
public:
    int lengthOfLIS(vector<int>& A) {
        int n = A.size();
        if(n==0) return 0;
        //minimum length will be 1
        vector<int> dp(n,1);
        int ans = 1;
        
        //for each j we have to check i from 0 to j-1
        // whether the element at j can add to value at i
        // if A[j] is greater, it can add. so we add +1
        for(int j = 1; j < n; j++){
            for(int i = 0; i < j; i++){
                if(A[i] < A[j]){            //if(A[i] < A[j] and dp[j]<=dp[i]) this can increase the speed slightly
                    dp[j] = max(dp[j], dp[i]+1);
                }
            }
            ans = max(ans,dp[j]);
        }
        return ans;
    }
};
