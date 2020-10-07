"""
Problem Description

Given an 2D integer array A of size N x 2 denoting time intervals of different meetings.

Where:

A[i][0] = start time of the ith meeting.
A[i][1] = end time of the ith meeting.
Find the minimum number of conference rooms required so that all meetings can be done.



Problem Constraints
1 <= N <= 10

0 <= A[i][0] < A[i][1] <= 2 * 109



Input Format
The only argument given is the matrix A.



Output Format
Return the minimum number of conference rooms required so that all meetings can be done.



Example Input
Input 1:

 A = [      [0, 30]
            [5, 10]
            [15, 20]
     ]

Input 2:

 A =  [     [1, 18]
            [18, 23]
            [15, 29]
            [4, 15]
            [2, 11]
            [5, 13]
      ]


Example Output
Output 1:

 2
Output 2:

 4


Example Explanation
Explanation 1:

 Meeting one can be done in conference room 1 form 0 - 30.
 Meeting two can be done in conference room 2 form 5 - 10.
 Meeting one can be done in conference room 2 form 15 - 20 as it is free in this interval.
Explanation 2:

 Meeting one can be done in conference room 1 from 1 - 18.
 Meeting five can be done in conference room 2 from 2 - 11.
 Meeting four can be done in conference room 3 from 4 - 15.
 Meeting six can be done in conference room 4 from 5 - 13.
 Meeting three can be done in conference room 2 from 15 - 29 as it is free in this interval.
 Meeting two can be done in conference room 4 from 18 - 23 as it is free in this interval.
 """.
 
 
 #similar to minimum platforms
 
 
 class Solution:
    # @param A : list of list of integers
    # @return an integer
    def solve(self, A):
        
        starttime = [meet[0] for meet in A]
        endtime = [meet[1] for meet in A]
        
        starttime.sort()
        endtime.sort()
        
        n = len(starttime)
        i = 1
        j = 0
        #print(starttime,endtime)
        
        maxrooms = 1
        curr_rooms = 1
        while i < n and j < n:
            # put <= depending on the question
            if starttime[i] < endtime[j]:
                curr_rooms +=1
                i += 1
            else:
                curr_rooms -=1
                j += 1
            
            maxrooms = max(maxrooms,curr_rooms)
            
        return maxrooms
       
       
       
  """
  
int solve2(vector<vector<int> > &A){
    int n=A.size();
    sort(A.begin(),A.end());
        
        priority_queue<int, vector<int>, greater<int>> heap;
        int rooms = 0;
        heap.push(A[0][1]);
        rooms++;
        for (int i = 1; i < n; i++) {
            if (A[i][0] < heap.top()) {
                rooms++;
            } else {
                heap.pop();
            }
            heap.push(A[i][1]);
        }
        return rooms;
}
  """
