/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

 

Constraints:

intervals[i][0] <= intervals[i][1]

*/

class Solution {
public:
    
    vector<int> parent;
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        parent.resize(n);
        bool changed = false;
        for(int i= 0; i < n; i++)
            parent[i] = i;
        
        for(int i = 1; i < n; i++)
        {
            if( intervals[i][0] <= intervals[i-1][1]){
                if(parent[i] != parent[i-1])
                    Union(i-1,i);
                changed = true;
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            if(parent[i] != i)
            {
                int par = find(i);
                if( intervals[par][1] < intervals[i][1])
                    intervals[par][1] = intervals[i][1];
            }
        }
        
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++)
        {
            if(parent[i] == i)
                ans.push_back(intervals[i]);
        }
        if(changed){
            return merge(ans);
        }
        return ans;
    }
    
    int find (int x)
    {
        if( parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void Union( int x, int y)
    {
        int xp = find(x);
        int yp = find(y);
        
        parent[yp] = xp;
    }
};
