/*Problem Description

Given a binary grid A of size N x M consisting of 0's and 1's, find the area of the largest rectangle inside the grid such that all the cells inside the chosen rectangle should have 1 in them.

You are allowed to permutate the columns matrix i.e. you can arrange each of the column in any order in the final grid.

Please follow the sample input and explanation for more clarity.



Input Format
First and only argument is an 2D binary array A.



Output Format
Return a single integer denoting the area of the largest rectangle inside the grid such that all the cells inside the chosen rectangle should have 1 in them.



Example Input
Input 1:

 A = [  [1, 0, 1]
        [0, 1 ,0]
        [1, 0, 0]
    ]


Example Output
Output 1:

 2


Example Explanation
Explanation 1:

    1 0 1
    0 1 0
    1 0 0


At present we can see that max rectangle satisfying the criteria mentioned in the problem
 is of 1 * 1 = 1 area i.e either of the 4 cells which contain 1 in it.



Now since we are allowed to permutate the columns of the given matrix, we can take column 1
 and column 3 and make them neighbours. One of the possible configuration of the grid can be:
 1 1 0
 0 0 1
 1 0 0



Now In this grid, first column is column 1, second column is column 3 and third column
 is column 2 from the original given grid.



Now, we can see that if we calculate the max area rectangle, we get max area as 1 * 2 = 2
 which is bigger than the earlier case. Hence 2 will be the answer in this case.
 */
 
 int Solution::solve(vector<vector<int> > &A) {
	int n, m, res = 0;
	n = A.size();
	m = A[0].size();
	int dp[n+1][m+1];
	memset(dp, 0, sizeof(dp));
	
	//counting the number of consecutive zeros in each column
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if(A[j-1][i-1] == 0) {
				dp[j][i] = 0;
			}
			else {
				dp[j][i] += dp[j-1][i] + 1;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		int arr[n + 1], cnt = 0;
		memset(arr, 0, sizeof(arr));
		for (int j = 1; j <= m; ++j) {
			arr[dp[i][j]] ++;
		}
		for (int j = n; j >= 0; --j) {
			cnt += arr[j];
			res = max(res, cnt * j);
		}
	}

	return res;
}
