/*
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?*/

class Solution {
public:
    vector<int> intersect(vector<int>& A, vector<int>& B) {
        int i=0,j=0;
        vector<int> v;
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        

        while(i<A.size() && j<B.size())
        {
            if(A[i]<B[j])
                i++;

            else if(A[i]>B[j])
                j++;

            else
            {
                v.push_back(A[i]);
                i++;
                j++;
            }
        }
        return v;
    }
};



//little bit slower


class Solution {
public:
    vector<int> intersect(vector<int>& A, vector<int>& B) {
        int i=0,j=0;
        vector<int> v;
        
        unordered_map <int,int> map1;
        unordered_map <int,int> map2;
        
        for(int i:A){
            map1[i]++;
        }
        
        for(int i:B){
            map2[i]++;
        }
        
        for(auto item:map1){
            if(map2.find(item.first)!=map2.end()){
                for(int i=0; i< min(item.second,map2[item.first]);i++){
                    v.push_back(item.first);
                }
            }
        }
       
        return v;
    }
};
