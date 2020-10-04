/*
Given two sorted arrays arr1[] of size N and arr2[] of size M. Each array is sorted in non-decreasing order. Merge the two arrays into one sorted array in non-decreasing order without using any extra space.


Example 1:

Input:
N = 4, M = 5
arr1[] = {1, 3, 5, 7}
arr2[] = {0, 2, 6, 8, 9}
Output: 0 1 2 3 5 6 7 8 9
Explanation: Since you can't use any 
extra space, modify the given arrays
to form 
arr1[] = {0, 1, 2, 3}
arr2[] = {5, 6, 7, 8, 9}

Example 2:

Input:
N = 2, M = 3
arr1[] = {10, 12}
arr2[] = {5, 18, 20}
Output: 5 10 12 18 20
Explanation: Since you can't use any
extra space, modify the given arrays
to form 
arr1[] = {5, 10}
arr2[] = {12, 18, 20}
 

Your Task:
You don't need to read input or print anything. Complete the function merge()
which takes the two arrays arr1[], arr2[] and their sizes n and m, as input parameters. 
The function does not return anything. Use the given arrays to sort and merge arr1[] and arr2[] in-place. 
Note: The generated output will print all the elements of arr1[] followed by all the elements of arr[2].


Expected Time Complexity: O((n+m)*log(n+m))
Expected Auxiliary Space: O(1)
*/


class Solution{
public:
	void merge(int a[], int b[], int n, int m) {
	    // code here
	    int c=n,sr=0,i=0,j=0;
	    while(c-- && i<n && j<m)
	    {
	        if(a[i]<b[j])
	        i++;
	        else if(a[i]>=b[j])
	        {
	            sr++;
	            j++;
	        }
	    }
	    for(i=0;i<sr;i++){
	        swap(b[i],a[n-i-1]);
	    }
	    sort(a,a+n);
	    sort(b,b+m);
	}
};


class Solution{
public:
	void merge(int a1[], int a2[], int m, int n) {
	    // code here
	    for(int i= n-1; i>=0; i--){
	        int last = a1[m-1];
	        int j;
	        for(j = m-2; j>=0 and a1[j]>a2[i]; j--){
	           a1[j+1] = a1[j];
	        }
	        if(j!=m-2 or last>a2[i]){
	            a1[j+1] = a2[i];
	            a2[i] = last;
	        }
	    }
	}
};
