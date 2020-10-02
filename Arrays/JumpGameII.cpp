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
        
        int pos = 0, des = 0;
        int count = 0;
        
        for(int i = 0;i< nums.size()-1;i++){
            des = max(des, i+nums[i]);
            if(pos == i){
                pos = des;
                count++;
            } 
        }
        return count;
    }
};
