/*
Given two positive integers L and R, return count of numbers having exactly 3 divisors from L to R inclusive.

 

Example 1:

Input:
L = 1, R = 10
Output:
2
Explanation:
4 and 9 are two numbers between 1 and 10
and have exactly 3 divisors.
Example 2:

Input:
L = 2, R = 5
Output:
1
Explanation:
4 is the only number between 2 and 5
and have exactly 3 divisors.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function count3DivNums() which takes 2 Integers L, 
and R as input and returns the count of numbers between L and R having exacly 3 divisors.

 

Expected Time Complexity: O(sqrt(R)*log(R))
Expected Auxiliary Space: O(sqrt(R))

 

Constraints:
1 <= L <= R <= 109

*/



// { Driver Code Starts


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


/*
The numbers having exactly 3 divisors are square of prime numbers.
for example:  4, 9, 25, 49, ............

Now the problem is reduced to find the number of square of prime numbers
between L and R inclusive. It will be equivalent to number of prime numbers
between square root of L to square root of R inclusive. We can pre construct
prime numbers using Sieve of Eratosthenes.
*/

#include <bits/stdc++.h> 
using namespace std; 
class Solution {
  public:
    
    vector<bool> prime;
    void SieveOfEratosthenes(int n) 
    { 
        prime.resize(n+1,true);
        prime[0] = false;
        prime[1] = false; 
      
        for (int p = 2; p * p <= n; p++) { 
            if (prime[p]){ 
                for (int i = p * 2; i <= n; i += p) 
                    prime[i] = false; 
            } 
        } 
    } 
    int count3DivNums(long long L, long long R) {
        
        SieveOfEratosthenes(sqrt(R));
  
        int count = 0;
        int a = ceil(sqrt(L));
        int b = sqrt(R);
      
        for(int i = a; i <=b; i++){
            if(prime[i])
                count ++;
        }
        
        return count;
    }
    
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long L,R;
        
        cin>>L>>R;

        Solution ob;
        cout << ob.count3DivNums(L,R) << endl;
    }
    return 0;
}  // } Driver Code Ends
