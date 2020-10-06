/*Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

*/

class Solution {
public:
    int longestConsecutive(vector<int>& A) {
        
        unordered_set <int> hash;
        for (int i: A){
            hash.insert(i);
        }
        int ans = 0;
        for(auto item:hash){
            if(hash.find(item-1) == hash.end()){
                int count = 0;
                int i = item;
                while(hash.find(i)!=hash.end()){
                    i++;
                    count++;
                }
                ans = max(ans,count);
            }
        }
        return ans;
    }
};
