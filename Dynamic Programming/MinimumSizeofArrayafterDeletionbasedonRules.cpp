/*


Find minimum possible size of array with given rules for removing elements

Given an array of numbers and a constant k, minimize size of array with following rules for removing elements.

Exactly three elements can be removed at one go.
The removed three elements must be adjacent in array, i.e., arr[i], arr[i+1], arr[i+2]. And the second element must
be k greater than first and third element must be k greater than second, i.e., arr[i+1] – arr[i] = k and arr[i+2]-arr[i+1] = k.
Example:

Input: arr[] = {2, 3, 4, 5, 6, 4}, k = 1
Output: 0
We can actually remove all elements. 
First remove 4, 5, 6 => We get {2, 3, 4}
Now remove 2, 3, 4   => We get empty array {}

Input:  arr[] = {2, 3, 4, 7, 6, 4}, k = 1
Output: 3
We can only remove 2 3 4

*/

/*

For every element arr[i] there are two possibilities
1) Either the element is not removed.
2) OR element is removed (if it follows rules of removal). When an element is removed, there are again two possibilities.
…..a) It may be removed directly, i.e., initial arr[i+1] is arr[i]+k and arr[i+2] is arr[i] + 2*k.
…..b) There exist x and y such that arr[x] – arr[i] = k, arr[y] – arr[x] = k, and subarrays “arr[i+1…x-1]” & “arr[x+1…y-1]” can be completely removed.

Below is recursive algorithm based on above idea.



// Returns size of minimum possible size of arr[low..high]
// after removing elements according to given rules
findMinSize(arr[], low, high, k)

// If there are less than 3 elements in arr[low..high]
1) If high-low+1 < 3, return high-low+1

// Consider the case when 'arr[low]' is not considered as
// part of any triplet to be removed.  Initialize result 
// using this case
2) result = 1 + findMinSize(arr, low+1, high)

// Case when 'arr[low]' is part of some triplet and removed
// Try all possible triplets that have arr[low]
3) For all i from low+1 to high
    For all j from i+1 to high
      Update result if all of the following conditions are met
      a) arr[i] - arr[low] = k  
      b) arr[j] - arr[i]  = k
      c) findMinSize(arr, low+1, i-1, k) returns 0
      d) findMinSize(arr, i+1, j-1, k) also returns 0
      e) Result calculated for this triplet (low, i, j)
         is smaller than existing result.

4) Return result
*/


// C++ program to find size of minimum possible array after 
// removing elements according to given rules 
#include <bits/stdc++.h> 
using namespace std; 
#define MAX 1000 

// dp[i][j] denotes the minimum number of elements left in 
// the subarray arr[i..j]. 
int dp[MAX][MAX]; 

int minSizeRec(int arr[], int low, int high, int k) 
{ 
	// If already evaluated 
	if (dp[low][high] != -1) 
		return dp[low][high]; 

	// If size of array is less than 3 
	if ( (high-low + 1) < 3) 
		return high-low +1; 

	// Initialize result as the case when first element is 
	// separated (not removed using given rules) 
	int res = 1 + minSizeRec(arr, low+1, high, k); 

	// Now consider all cases when first element forms a triplet 
	// and removed. Check for all possible triplets (low, i, j) 
	for (int i = low+1; i<=high-1; i++) 
	{ 
		for (int j = i+1; j <= high; j++ ) 
		{ 
			// Check if this triplet follows the given rules of 
			// removal. And elements between 'low' and 'i' , and 
			// between 'i' and 'j' can be recursively removed. 
			if (arr[i] == (arr[low] + k) && 
				arr[j] == (arr[low] + 2*k) && 
				minSizeRec(arr, low+1, i-1, k) == 0 && 
				minSizeRec(arr, i+1, j-1, k) == 0) 
			{ 
				res = min(res, minSizeRec(arr, j+1, high, k)); 
			} 
		} 
	} 

	// Insert value in table and return result 
	return (dp[low][high] = res); 
} 

// This function mainlu initializes dp table and calls 
// recursive function minSizeRec 
int minSize(int arr[], int n, int k) 
{ 
	memset(dp, -1, sizeof(dp)); 
	return minSizeRec(arr, 0, n-1, k); 
} 

// Driver prrogram to test above function 
int main() 
{ 
	int arr[] = {2, 3, 4, 5, 6, 4}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	int k = 1; 
	cout << minSize(arr, n, k) << endl; 
	return 0; 
} 
