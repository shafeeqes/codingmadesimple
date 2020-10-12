/*
https://leetcode.com/problems/maximal-rectangle/

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = []
Output: 0
Example 3:

Input: matrix = [["0"]]
Output: 0
Example 4:

Input: matrix = [["1"]]
Output: 1
Example 5:

Input: matrix = [["0","0"]]
Output: 0

*/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int r = matrix.size();
        if(r == 0)  return 0;
        int c = matrix[0].size();
        
        int ans = INT_MIN;
        vector<int> histogram(c,0);
        
        for(int i = 0; i <r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(matrix[i][j] == '0')
                    histogram[j] = 0;
                else if(matrix[i][j] =='1')
                    histogram[j] += 1; 
            }
            ans = max(ans, maxArea(histogram));
        }
        
        return ans;
        
    }
    //see largest area histogram problem in stacks section
    int maxArea(vector<int>& A) {
        
        int n = A.size();
        if(n == 0) return 0;
        if(n == 1)
            return A[0];
        int area;
    
        stack<int> s;
        int ans = 0;
        int i = 0;
        
        while(i < n)
        {
             if(s.empty() or A[i] >= A[s.top()])
             {
                 s.push(i);
                 i++;
             }
             else
             {
                 int top = s.top();
                 s.pop();
                 
                 if(s.empty())
                     area = A[top]*i;
                 else     
                     area = A[top] * (i - s.top() -1);
                 
                 ans = max(ans,area);
             }
        }
      
        while(!s.empty())
        {
            int top = s.top();
            s.pop();

            if(s.empty())
                area = A[top] * i;
            else
                area = A[top] * (i - s.top() - 1);

            ans = max(ans,area);
        }
        
        return ans;
    }
};
