/*
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Note:

Each element in the result must be unique.
The result can be in any order.
*/


class Solution {
public:
    vector<int> intersection(vector<int>& A, vector<int>& B) {
        int i=0,j=0;
        vector<int> v;
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        unordered_set<int> s;

        while(i<A.size() && j<B.size())
        {
            if(A[i]<B[j])
                i++;

            else if(A[i]>B[j])
                j++;

            else
            {
                s.insert(A[i]);
                i++;
                j++;
            }
        }
        for(auto item:s){
            v.push_back(item);
        }
        return v;
    }
};
