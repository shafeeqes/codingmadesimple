/*
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:

Each of the array element will not exceed 100.
The array size will not exceed 200.
 

Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
 

Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.
*/


class Solution {
public:
    bool canPartition(vector<int>& A) {
     
        int total = 0;
        for(int i:A){
            total += i;
        }
        
        if(total %2 != 0)
            return false;
        unordered_map<string,bool> state;
        return canPartition(A,0,0,total, state);
        
    }
    bool canPartition(vector<int> &A, int index, int currSum, int total, unordered_map<string,bool> &state){
        
        string s = to_string(index);
        s += to_string(currSum);
        
        //cout<<s<<endl;
        
        if(state.find(s)!= state.end()){
            return state[s];
        }
        if(currSum *2 == total)
            return true;
        
        if(currSum > total/2 or index >= A.size())
            return false;
        
        bool foundPartition = canPartition(A,index+1,currSum,total,state) or canPartition(A,index+1, currSum + A[index],total,state);
        
        state[s] = foundPartition;
        return foundPartition;
    }
};
