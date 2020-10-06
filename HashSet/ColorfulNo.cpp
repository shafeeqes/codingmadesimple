/*
For Given Number N find if its COLORFUL number or not

Return 0/1

COLORFUL number:

A number can be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different
Example:

N = 23
2 3 23
2 -> 2
3 -> 3
23 -> 6
this number is a COLORFUL number since product of every digit of a sub-sequence are different. 

Output : 1
*/

int Solution::colorful(int n) {
    
    vector<int> A;
    unordered_set<int> hash;
    
    while(n!=0)
    {
        A.push_back(n%10);
        n/=10;
    }
    
    for(int i = 0; i < A.size(); i++){
        long int product = 1;
        for(int j = i; j < A.size(); j++){
            product *= A[j];
            if(hash.find(product) != hash.end())
                return 0;
            else
                hash.insert(product);
        }
    }
    return 1;
}

