/*

There are N Mice and N holes are placed in a straight line.
Each hole can accomodate only 1 mouse.
A mouse can stay at his position, move one step right from x to x + 1, or move one step left from x to x − 1. Any of these moves consumes 1 minute.
Assign mice to holes so that the time when the last mouse gets inside a hole is minimized.

Example:

positions of mice are:
4 -4 2
positions of holes are:
4 0 5

Assign mouse at position x=4 to hole at position x=4 : Time taken is 0 minutes 
Assign mouse at position x=-4 to hole at position x=0 : Time taken is 4 minutes 
Assign mouse at position x=2 to hole at position x=5 : Time taken is 3 minutes 
After 4 minutes all of the mice are in the holes.

Since, there is no combination possible where the last mouse's time is less than 4, 
answer = 4.
Input:

A :  list of positions of mice
B :  list of positions of holes
Output:

single integer value
 NOTE: The final answer will fit in a 32 bit signed integer. 
 */
 
 int Solution::mice(vector<int> &A, vector<int> &B) {
    
    int max = INT_MIN,diff;
    int n=A.size();
    if(n==0)
        return 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    for(int i=0;i<n;i++){
        diff = abs(A[i]-B[i]);
        if(diff>max)
            max = diff;
    }
    
    return max;
    
}
