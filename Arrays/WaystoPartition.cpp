/*Problem Description

You are given a 1D integer array B containing A integers.

Count the number of ways to split all the elements of the array into 3 contiguous parts so that the sum of elements in each part is the same.

Such that : sum(B[1],..B[i]) = sum(B[i+1],...B[j]) = sum(B[j+1],...B[n])



Problem Constraints
1 <= A <= 105

-109 <= B[i] <= 109



Input Format
First argument is an integer A.

Second argument is an 1D integer array B of size A.



Output Format
Return a single integer denoting the number of ways to split the array B into three parts with the same sum.



Example Input
Input 1:

 A = 5
 B = [1, 2, 3, 0, 3]
Input 2:

 A = 4
 B = [0, 1, -1, 0]


Example Output
Output 1:

 2
Output 2:

 1


Example Explanation
Explanation 1:

 There are no 2 ways to make partitions -
 1. (1,2)+(3)+(0,3).
 2. (1,2)+(3,0)+(3).
Explanation 2:

 There is only 1 way to make partition -
 1. (0)+(-1,1)+(0).
 */
 
 
 
 int Solution::solve(int A, vector<int> &B) {
 
    int i,j,count=0;
    int p[A];
    //long int sum=0,sum1=0,sum2=0,sum3=0;
    long int u,v,sum=0;
    
    for(i=0;i<A;i++)
        sum+=B[i];
        
    if(sum%3!=0)
        return 0;
    
    p[0]=B[0];    
    for (i = 1; i <A; i++) 
    {
        p[i] = p[i-1]+B[i];                           // Make a prefix array for getting sum in O(1)
    }
    u = sum/3;
    v = 2*sum/3;
       
    for(i=0;i<A;i++)
        if(p[i]==u)
            for(j=i+1;j<A-1;j++)
                if(p[j]==v)
                    count++;
                
    return count;
}
