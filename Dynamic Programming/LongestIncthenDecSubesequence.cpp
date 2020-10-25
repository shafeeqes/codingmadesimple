/*Given an 1D integer array A of length N, find the length of longest subsequence which is first increasing then decreasing.



Problem Constraints
0 <= N <= 3000

-107 <= A[i] <= 107



Input Format
The first and the only argument contains an integer array A.



Output Format
Return an integer representing the answer as described in the problem statement.



Example Input
Input 1:

 A = [1, 2, 1]
Input 2:

 A = [1, 11, 2, 10, 4, 5, 2, 1]


Example Output
Output 1:

 3
Output 2:

 6


Example Explanation
Explanation 1:

 [1, 2, 1] is the longest subsequence.
Explanation 2:

 [1 2 10 4 2 1] is the longest subsequence.
 */
 
//O(nlogn) solution
//See longest increasing subsequence for explanation

int Solution::longestSubsequenceLength(const vector<int> &A) {
    
    int n = A.size();
    
    if(n == 0)  return 0;
    
    vector<int> lis(n,1);
    vector<int> lds(n,1);
    vector<int> c(n);
    
    c[1] = A[0];
    int j = 1;
    for(int i = 1; i < n; i++){
        if(A[i] < c[1]){
            c[1] = A[i];
            lis[i] = 1;
        }
        else if(A[i] > c[j]){
            j++;
            c[j] = A[i];
            lis[i] = j;
        }
        else{
            int k = upper_bound(c.begin(),c.begin()+j, A[i]) - c.begin();
            if(A[i] == c[k-1])
                continue;
            c[k] = A[i];
            lis[i] = k;
        }
    }
    
    c.clear();
    c[1] = A[n-1];
    j = 1;
    for(int i = n-2; i >= 0; i--){
        if(A[i] < c[1]){
            c[1] = A[i];
            lds[i] = 1;
        }
        else if(A[i] > c[j]){
            j++;
            c[j] = A[i];
            lds[i] = j;
        }
        else{
            int k = upper_bound(c.begin(),c.begin()+j, A[i]) - c.begin();
            if(A[i] == c[k-1])
                continue;
            c[k] = A[i];
            lds[i] = k;
        }
    }
    
    
    int ans=0;
    for(int i = 0; i < n; i++)
        ans=max(ans, lis[i] + lds[i]-1);
    
    return ans;
}

 //O(n^2) solution
 int Solution::longestSubsequenceLength(const vector<int> &A) {
    int n = A.size();

    vector<int> lis(n,1);
    vector<int> lds(n,1);
    
    for(int i = 1; i < n; i++){
        for(int j = 0;j < i; j++){
            if(A[i] > A[j] && lis[i] < lis[j]+1)
             lis[i] = lis[j]+1;
        }
    }
    
    for(int i = n-2; i >= 0; i--){
        for(int j= n-1; j > i; j--){
            if(A[i] > A[j] && lds[i] < lds[j]+1)
             lds[i] = lds[j]+1;
        }
    }
    
    int ans=0;
    for(int i = 0; i < n; i++)
        ans=max(ans, lis[i] + lds[i]-1);
    
    return ans;
}
