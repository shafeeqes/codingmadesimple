/*
How many minimum numbers from fibonacci series are required such that sum of numbers should be equal to a given Number N?
Note : repetition of number is allowed.

Example:

N = 4
Fibonacci numbers : 1 1 2 3 5 .... so on
here 2 + 2 = 4 
so minimum numbers will be 2 
*/


int Solution::fibsum(int n) {

    vector<int> fib (2,1);
    
     // Calculate all Fibonacci terms 
    // which are less than or equal to K.
    for(int i = 2; fib[i-1] < n; i++){
        fib.push_back(fib[i-1]+fib[i-2]);
    }
    
    int ans = 0, i = fib.size()-1;
    
     // Subtract Fibonacci terms from  n  
    // until n > 0. 
    while(n>0){
        while(fib[i]>n)
            i--;
         // Divide sum K by j-th Fibonacci term to find 
        // how many terms it contribute in sum. 
        n -= fib[i];
        ans++;
    }
    return ans;
}
