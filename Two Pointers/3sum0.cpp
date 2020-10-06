/*Given an array nums of n integers, are there elements a, b, c in nums 
such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []

*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& A) {
        sort(A.begin(),A.end());
        vector<vector<int> > ans;

        if(A.size()<3)
            return ans;

        for(int i = 0; i < A.size()-2; i++)
        {
            int j = i+1;
            int k =A.size()-1;
            if(i > 0 && A[i] == A[i-1]) continue;
            while(j<k)
            {
                if((long)A[i]+A[j]+A[k] == 0)
                {
                    ans.push_back({A[i],A[j],A[k]});

                    while( j < k and A[j] == A[j+1]){
                        j++;
                    }
                    while( j < k and A[k] == A[k-1]){
                        k--;
                    }
                    j++;
                    k--;
                }
                else if ((long)A[i]+A[j]+A[k] < 0)
                    j++;
                else
                    k--;
            }
        }

        return ans;
    }
};
