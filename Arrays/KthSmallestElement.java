/*
Given an array arr[] and a number K where K is smaller than size of array, the task
is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

Input:
The first line of input contains an integer T, denoting the number of testcases. Then 
T test cases follow. Each test case consists of three lines. First line of each testcase contains 
an integer N denoting size of the array. Second line contains N space separated integer denoting
elements of the array. Third line of the test case contains an integer K.

Output:
Corresponding to each test case, print the kth smallest element in a new line.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= arr[i] <= 105
1 <= K <= N

Example:
Input:
2
6
7 10 4 3 20 15
3
5
7 10 4 20 15
4
Output:
7
15

Explanation:
Testcase 1: 3rd smallest element in the given array is 7.
Testcase 2: 4th smallest elemets in the given array is 15.
*/


/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		//code
		// create an object of Scanner
        Scanner input = new Scanner(System.in);
        GFG newClass = new GFG();
        // take input from the user
        int t = input.nextInt();
        //System.out.println(t);
        for(; t>0; t--){
            
            int N = input.nextInt();
            //System.out.println(N);
            int A[] = new int[N];
            for(int i=0; i<N; i++){
                A[i] = input.nextInt();
            }
            int k = input.nextInt();
            k = N -k +1;
            int ans = newClass.kthLargest(A,k);
            System.out.println(ans);
        }
		
	}
	public int kthLargest(int[] A,int k){
	    int n = A.length;
	    int left = 0, right = n-1;
	    
	    Random rand = new Random(0);
	    
	    while(left<=right){
	        int upperbound = right - left +1;
	        int chosenpivot = rand.nextInt(upperbound) + left;
	        int finalpivot = partition(A,left,right,chosenpivot);
	        
	        if(finalpivot == n-k){
	            return A[finalpivot];
	        }
	        else if(finalpivot > n-k){
	            right = finalpivot - 1;
	        }
	        else{
	            left = finalpivot + 1;
	        }
	    }
	    return -1;
	}
	private int partition(int[] A,int left,int right,int pivot){
	    int pivotvalue = A[pivot];
	    int tailindex = left;
	    swap(A,pivot,right);
	    for(int i=left;i<right;i++){
	        if(A[i] < pivotvalue){
	            swap(A,i,tailindex);
	            tailindex++;
	        }
	    }
	    swap(A,right,tailindex);
	    return tailindex;
	}
	
	private void swap(int[] arr, int first, int second) {
    int temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
  }
}
