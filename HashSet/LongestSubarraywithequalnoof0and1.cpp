/*
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.

Input: arr[] = {1, 0, 1, 1, 1, 0, 0}
Output: 1 to 6 
(Starting and Ending indexes of output subarray)

Input: arr[] = {1, 1, 1, 1}
Output: No such subarray

Input: arr[] = {0, 0, 1, 1, 0}
Output: 0 to 3 Or 1 to 4
*/
/*


Method 2: Hashmap.

Approach: The concept of taking cumulative sum, taking 0’s as -1 will help us in optimising the approach. While taking the cumulative sum, there are two cases when there can be a sub-array with equal number of 0’s and 1’s. 

When cumulative sum=0, which signifies that sub-array from index (0) till present index has equal number of 0’s and 1’s.
When we encounter a cumulative sum value which we have already encountered before, which means that sub-array from the previous index+1 till the present index has equal number of 0’s and 1’s as they give a cumulative sum of 0 .
In a nutshell this problem is equivalent to finding two indexes i & j in array[] such that array[i] = array[j] and (j-i) is maximum. To store the first occurrence of each unique cumulative sum value we use a hash_map wherein if we get that value again we can find the sub-array size and compare it with maximum size found till now.

Algorithm :  

Let input array be arr[] of size n and max_size be the size of output sub-array.
Create a temporary array sumleft[] of size n. Store the sum of all elements from arr[0] to arr[i] in sumleft[i].
There are two cases, the output sub-array may start from 0th index or may start from some other index. We will return the max of the values obtained by two cases.
To find the maximum length sub-array starting from 0th index, scan the sumleft[] and find the maximum i where sumleft[i] = 0.
Now, we need to find the subarray where subarray sum is 0 and start index is not 0. This problem is equivalent to finding two indexes i & j in sumleft[] such that sumleft[i] = sumleft[j] and j-i is maximum. To solve this, we create a hash table with size = max-min+1 where min is the minimum value in the sumleft[] and max is the maximum value in the sumleft[]. Hash the leftmost occurrences of all different values in sumleft[]. The size of hash is chosen as max-min+1 because there can be these many different possible values in sumleft[]. Initialize all values in hash as -1.
To fill and use hash[], traverse sumleft[] from 0 to n-1. If a value is not present in hash[], then store its index in hash. If the value is present, then calculate the difference of current index of sumleft[] and previously stored value in hash[]. If this difference is more than maxsize, then update the maxsize.
To handle corner cases (all 1s and all 0s), we initialize maxsize as -1. If the maxsize remains -1, then print there is no such subarray.

*/


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int n = nums.size();
        if(n < 2)
            return 0;
       /* for(int i = 0; i < n; i++){
            nums[i] = nums[i] == 0 ? -1: 1;
        }*/
        
        unordered_map <int, int> hashmap;
        int start,end;
        int sum = 0;

        hashmap[0] = -1;
        
        int maxlen = 0;
        for(int i = 0; i < n; i++){
            sum = sum + (nums[i] == 1 ? 1 : -1);
            
            if(hashmap.find(sum)!= hashmap.end()){
                int curr_len = i - hashmap[sum];
                if(curr_len > maxlen)
                    maxlen = curr_len;
            }
            else{
                hashmap[sum] = i;
            }
        }
        
        return maxlen;
        
    }
};
