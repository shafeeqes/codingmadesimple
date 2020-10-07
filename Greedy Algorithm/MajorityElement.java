/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*/


//O(n)
class Solution {
    public int majorityElement(int[] A) {
        
        int n = A.length;
        HashMap<Integer,Integer> count= new HashMap<>();
        
        for(int i = 0; i < n; i++){
            int curr_count = count.getOrDefault(A[i],0) + 1;
            count.put(A[i], curr_count);
            if(curr_count > n/2)
                return A[i];
        }
        
        return -1;
    }
}



//O(nlogn) but works better in average

class Solution {
    public int majorityElement(int[] A) {
        
        Arrays.sort(A);
        //the majority element is bound to be in the middle of the sorted array
        return A[A.length/2];
    }
}
