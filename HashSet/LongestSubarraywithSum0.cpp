/*
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1:

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.
Your Task:
You just have to complete the function maxLen() which takes two arguments an array A and n, where n is the size of the array A and returns the length of the largest subarray with 0 sum.

Expected Time Complexity: O(N*Log(N)).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 104
-1000 <= A[i] <= 1000, for each valid i
*/


int maxLen(int A[], int n)
{
    unordered_map <int,int> hash;
    int sum = 0;
    int start = 0;
    int maxlen = 0;
    for(int i=0 ; i<n; i++){
        sum += A[i];
        // if any element is zero and maxlen is still 0
        if (A[i] == 0 && maxlen == 0) 
            maxlen = 1; 
        //this means all the elements up to i sum upto zero
        if (sum == 0) 
            maxlen = i + 1;     
        if(hash.find(sum) != hash.end()){
            start = hash[sum];
            if(i- start > maxlen){
                maxlen = i - start;
            }
        }else{
            hash[sum] = i;
        }
    }
    return maxlen;
}
