/*Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.

*/

class Solution {
public:
    int jump(vector<int>& nums) {
        
        if (nums.size() == 1) {
            return 0;
        }
        int count = 0;
        int i = 0;
        while (i + nums[i] < nums.size() - 1) {
            int maxVal = 0;
            int maxValIndex = 0;
            for (int j = i + 1; j <= i + nums[i]; j++) {
                if (nums[j] + j  > maxVal) {
                    maxVal = nums[j ] + j ;
                    maxValIndex = j;
                }
            }
            i = maxValIndex;
            count++;
        }
        return count + 1;
        
    }
};


class Solution {
public:
    int jump(vector<int>& nums) {
        
        if (nums.size() == 1) {
            return 0;
        }
        int count = 0;
        int i = 0;
        while (i + nums[i] < nums.size() - 1) {
            int maxVal = 0;
            int maxValIndex = 0;
            for (int j = 1; j <= nums[i]; j++) {
                if (nums[j + i] + j > maxVal) {
                    maxVal = nums[j + i] + j;
                    maxValIndex = i + j;
                }
            }
            i = maxValIndex;
            count++;
        }
        return count + 1;
        
    }
};


int Solution::jump(vector<int> &A) {
    int currP = 0, explored = 0, index = 0, N = A.size(), nJumps = 0;
    
    while(currP < N-1){
        explored = currP;
        ++nJumps;
        for(; index <= explored; ++index){
            currP = max(currP, A[index]+index);        
        }
        if(currP == explored) return -1;
    }
    
    return nJumps;
}
