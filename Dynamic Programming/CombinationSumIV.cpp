/*
Given an integer array with all positive numbers and no duplicates, 
find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
*/
/*
Might look like a recursion problem in the beginning but it's not

When we look at a single element
[1] target = 1 . only one way
[1 2] target = 2.  2  or 1 1      2 ways.
[1 2] target = 2.  2 1 or 1 1 1 or 1 2.
                          here we can notice that after 1 the rest 2 can be made from [1 2]
                          in 2 ways. which is the previus result
[1 2 3] target = 3. if we select 1 first. the remaining is
                    3 - 1  = 2. 2 can be made with elements less than 2 ( 1 and 2)
                                  so we check up to that element.
                    when we select 2. the remaining is
                    3 - 2 = 1. and 1 can be made with only 1.
                    when we select 3.
                    3 - 3 = 0. so only one way.
      so here we can see that for i = 3. ans[i] = ans[i-1]+ans[i-2]+ans[i-3]

so to find ans[target] we have to find all i's upto target.
*/

class Solution {
public:
    int combinationSum4(vector<int>& A, int target) {
        sort(A.begin(),A.end());
        vector<double> ans(target+1, 0);
        ans[0] = 1;
        
        for(int i = 1; i<= target; i++ ){
            for(int x:A){
                if(x <= i)
                    ans[i] += ans[i-x];
                else
                    break;
            }
        }
        return ans[target];
    }
};
