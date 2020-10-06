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

//if the subarray is asked
vector<int> Solution::lszero(vector<int> &A)
{
    if(A.size()==0)
        return {};
    //concept of prefix-sum and hashing
    vector<int> ans;
    unordered_map<int,int> m;//{prefixsum,index}
    int sum = 0;
    int start = 0, end = 0;
    
    m.insert({0,-1});//if first element is 0
    
    for(int i = 0; i < A.size(); i++)
    {
        sum += A[i];
        if(m.find(sum)!=m.end())
        {
            if(i-m[sum] > end-start)//strictly greater as we want as left as possible
            {
                start = m[sum];
                end = i;
            }
        }
        else
            m.insert({sum,i});
    }
    for(int i = start + 1; i <= end; i++)//all elements after first occurance of prefix sum
        ans.push_back(A[i]);
    return ans;
}


//if only length is asked

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
