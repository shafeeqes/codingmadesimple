/*
Find out the number of N digit numbers, whose digits on being added equals to a given number S. 
Note that a valid number starts from digits 1-9 except the number 0 itself. i.e. leading zeroes are not allowed.

Since the answer can be large, output answer modulo 1000000007

**

N = 2, S = 4
Valid numbers are {22, 31, 13, 40}
Hence output 4.
*/

int Solution::solve(int n, int s) {
    long long int dp[n][s];
    if(s<1||s>9*n) return 0;
    
    for(int i=0;i<s;i++){
        // ways of making sum upto 9 with single digit is 1 and sum > 9 is 0
        if(i+1 <= 9) 
          dp[0][i]=1;
        else 
          dp[0][i]=0;
    }
    //ways of making sum 1 with any number of digits is only 1
    for(int j=0;j<n;j++){
        dp[j][0]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<s;j++){
            dp[i][j]=0;
            int k=0;
            if(j>=9) 
              k=j-9;
            for(;k<=j;k++)
             dp[i][j]=(dp[i][j]+dp[i-1][k])%1000000007;
        }
    }
    return dp[n-1][s-1];    
}
