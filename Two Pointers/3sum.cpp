/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
Return the sum of the three integers.

Assume that there will only be one solution

Example:
given array S = {-1 2 1 -4},
and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)
*/

int Solution::threeSumClosest(vector<int> &A, int B) {
    
    sort(A.begin(),A.end());
    
    int minDiff = INT_MAX,j,k,diff,temp,sum;
    
    for(int i=0;i<A.size()-2;i++)
    {
        
        j = i+1;
        k = A.size()-1;
        
        while(j<k)
        {
            temp = A[i]+A[j]+A[k];
            diff = abs(temp-B);
            if(diff==0)
                return B;
            else if(diff<minDiff)
            {
                minDiff=diff;
                sum=temp;
            }
            
            if(temp<B)
                j++;
             
            else
                k--;
        }
    }  
    
    return sum;
}
