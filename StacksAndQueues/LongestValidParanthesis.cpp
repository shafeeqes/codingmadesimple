/*
//
https://www.youtube.com/watch?v=r0-zx5ejdq0&ab_channel=TimeComplexityInfinity


Given a string A containing just the characters ’(‘ and ’)’.

Find the length of the longest valid (well-formed) parentheses substring.



Input Format:

The only argument given is string A.
Output Format:

Return the length of the longest valid (well-formed) parentheses substring.
Constraints:

1 <= length(A) <= 750000
For Example

Input 1:
    A = "(()"
Output 1:
    2
    Explanation 1:
        The longest valid parentheses substring is "()", which has length = 2.

Input 2:
    A = ")()())"
Output 2:
    4
    Explanation 2:
        The longest valid parentheses substring is "()()", which has length = 4.
        */
        
 int Solution::longestValidParentheses(string A) {
    
    stack<int> s;
    int ans = 0;
    
    //NB: we are pushing the index to the stack not the brackets
    for(int i = 0; i < A.size(); i++){
        //if it is opening bracket, just push the index
        if(A[i] == '('){
            s.push(i);
        }
        else if(A[i] == ')'){
            //if it is closing and our current is also closing
            //we push because we need to restart the count for longest
            //valid parenthesis. this index now acts as our zero
            if(s.empty() or A[s.top()] == ')'){
                s.push(i);
            }
            //if prev is opening bracket, we pop it and calculate length
            // of valid parentesis and update max
            else if (A[s.top()] == '('){
                s.pop();
                //if stack is empty that means we have valid parenthesis
                //equal to the current index
                if(s.empty()){
                    ans = max(ans,i+1);
                }
                //otherwise calculate length using our recent reference index
                else{
                    int prev = s.top();   
                    ans = max(ans, i - prev);
                }
            }
        }
    }
    
    return ans;
}
