/*Given an array of real numbers greater than zero in form of strings.
Find if there exists a triplet (a,b,c) such that 1 < a+b+c < 2 .
Return 1 for true or 0 for false.

Example:

Given [0.6, 0.7, 0.8, 1.2, 0.4] ,

You should return 1

as

0.6+0.7+0.4=1.7

1<1.7<2

Hence, the output is 1.

O(n) solution is expected.

Note: You can assume the numbers in strings don’t overflow the primitive data type and there are no leading zeroes in numbers. Extra memory usage is allowed.
*/
int Solution::solve (vector < string > &A) {
    vector < double > arr;
    
    for (auto s:A)
        arr.push_back (stod (s));

    double a = arr[0], b = arr[1], c = arr[2];
    
    for (int i = 3; i < A.size ()+1; i++) {
        double sum = a+b+c;
        
        if (sum>1 && sum<2)
            return 1;
        
        if (i>=A.size())
            break;
        
        double x = arr[i];
        double m = sum>2 ? max(a, max(b,c)): sum<=1 ? min(a, min(b,c)): -1;
        
        if (m==a) a=x;
        else if (m==b) b=x;
        else if (m==c) c=x;
    }
    return 0;
}
