/*
Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k.

Example:

Input: n = 12, primes = [2,7,13,19]
Output: 32 
Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12 
             super ugly numbers given primes = [2,7,13,19] of size 4.
Note:

1 is a super ugly number for any given primes.
The given numbers in primes are in ascending order.
0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
The nth super ugly number is guaranteed to fit in a 32-bit signed integer.
*/

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        int size = primes.size();
        //saves the current index of ugly number which is made by this prime
        vector<int> pointer(size,0);
        
        vector<int> ugly(n);
        ugly[0] = 1;
        
        for(int i = 0; i < n-1; i++){
            int minval = INT_MAX;
            
            //find minval out of all ugly[last number made by prime[j]] * prime[j]
            for(int j=0; j < size; j++){
                minval = min(minval, ugly [pointer[j] ] * primes[j]);
            }
            
            ugly[i+1] = minval;
            
            //skip all values which are same as minval. this is important as duplication can occur
            for(int j=0; j < size; j++){
                if(minval == ugly[ pointer[j] ] * primes[j])
                    pointer[j]++;
            }
        }
        return ugly[n-1];
    }
};

//slower
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        set<int> s;
        
        for(int prime: primes)
            s.insert(prime);
        
        vector<long int> ans;
        ans.push_back(1);
        
        while(ans.size()<n){
            auto it = s.begin();
            ans.push_back((int) *it);
            for(auto x:ans){
                if(*it * x > INT_MAX)
                    continue;
                s.insert(x* (int)*it);
            }
            s.erase(it);
        }
        return ans[n-1];
    }
};
