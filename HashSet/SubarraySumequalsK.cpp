/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:

Input:nums = [1,1,1], k = 2
Output: 2
 

Constraints:

The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
*/
/*
Algorithm

The idea behind this approach is as follows: If the cumulative sum(repreesnted by sum[i]sum[i] for sum upto i^{th}i 
th
  index) upto two indices is the same, the sum of the elements lying in between those 
  indices is zero. Extending the same thought further, if the cumulative sum upto two indices, 
  say ii and jj is at a difference of kk i.e. if sum[i] - sum[j] = ksum[i]−sum[j]=k, the sum of 
  elements lying between indices ii and jj is kk.

Based on these thoughts, we make use of a hashmap mapmap which is used to store the cumulative sum
upto all the indices possible along with the number of times the same sum occurs. We store the data 
in the form: (sum_i, no. of occurences of sum_i)(sum 
i
​	
 ,no.ofoccurencesofsum 
i
​	
 ). We traverse over the array numsnums and keep on finding the cumulative sum. Every time we encounter
 a new sum, we make a new entry in the hashmap corresponding to that sum. If the same sum occurs again,
 we increment the count corresponding to that sum in the hashmap. Further, for every sum encountered,
 we also determine the number of times the sum sum-ksum−k has occured already, since it will determine
 the number of times a subarray with sum kk has occured upto the current index. We increment the countcount by the same amount.

After the complete array has been traversed, the countcount gives the required result.

The animation below depicts the process.
*/

O(n)

class Solution {
public:
    int subarraySum(vector<int>& A, int k) {
        int n = A.size();
        int count = 0, sum = 0;
        
        unordered_map <int,int> hash;
        hash[0] = 1;
        for(int i = 0; i < n; i++){
            sum += A[i];
            if(hash.find(sum - k) != hash.end()){
                count += hash[sum-k];
            }
            hash[sum]++;
        }
        return count;
    }
};
