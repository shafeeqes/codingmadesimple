//https://www.interviewbit.com/problems/largest-rectangle-in-histogram/
//https://leetcode.com/problems/largest-rectangle-in-histogram/
/*
Given an array of integers A of size N. A represents a histogram i.e A[i] denotes height of
the ith histogram’s bar. Width of each bar is 1.

Largest Rectangle in Histogram: Example 1

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

Largest Rectangle in Histogram: Example 2

The largest rectangle is shown in the shaded area, which has area = 10 unit.

Find the area of largest rectangle in the histogram.



Input Format

The only argument given is the integer array A.
Output Format

Return the area of largest rectangle in the histogram.
For Example

Input 1:
    A = [2, 1, 5, 6, 2, 3]
Output 1:
    10
    Explanation 1:
        The largest rectangle is shown in the shaded area, which has area = 10 unit.
    */
    
    
class Solution {
public:
    int largestRectangleArea(vector<int>& A) {
        
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
                 {
                     //if this is the last element which implies either this is the first element
                     // overall or this is the last in the current stack, so automatically all the                                    // elements before it should have been more than this.
                     area = A[top]*i;
                 }
                 else
                 {      
                     //height is current value, width will be current index - stack top - 1 .
                     // this  -1 is there because current index will be standing on the lower element found
                     // because of which we entered this else clause
                     area = A[top] * (i - s.top() -1);
                     
                     //NB: we are not incrementing i. so in the next loop, A[top] and s.top() will 
                     //change it will so it width will increase, height will decrease
                 }
                 //either way, save max in ans 
                 ans = max(ans,area);
             }
        }
        
        //do the area calculation one more time after exiting the loop
        //because when i exceeds n and if it is a increasing height graph,and for other obvious reasons
        
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
    
    
