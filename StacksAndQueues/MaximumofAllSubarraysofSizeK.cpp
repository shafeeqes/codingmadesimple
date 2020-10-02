/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
Example 3:

Input: nums = [1,-1], k = 1
Output: [1,-1]
Example 4:

Input: nums = [9,11], k = 2
Output: [11]
Example 5:

Input: nums = [4,-2], k = 2
Output: [4]
 
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& A, int k) {
        int n = A.size();
        deque <int> q(k);
        vector<int> ans;
        int i; 
        for (i = 0; i < k; ++i) { 
            while ((!q.empty()) && A[i] >= A[q.back()]) 
                q.pop_back(); 
            q.push_back(i); 
        } 
        for (; i < n; ++i) { 
            // The element at the front of the queue is the largest element of 
            // previous window, so print it 
            ans.push_back(A[q.front()]); 

            // Remove the elements which are out of this window 
            while ((!q.empty()) && q.front() <= i - k) 
                q.pop_front(); // Remove from front of queue 

            // Remove all elements smaller than the currently 
            // being added element (remove useless elements) 
            while ((!q.empty()) && A[i] >= A[q.back()]) 
                q.pop_back(); 

            // Add current element at the rear of Qi 
            q.push_back(i); 
        } 

        // Print the maximum element of last window 
        ans.push_back(A[q.front()]);

        return ans;
    }
};
