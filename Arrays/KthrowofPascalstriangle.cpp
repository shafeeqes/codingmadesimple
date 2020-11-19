/*

Given an index k, return the kth row of the Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Input : k = 3

Return : [1,3,3,1]
 NOTE : k is 0 based. k = 0, corresponds to the row [1]. 
Note:Could you optimize your algorithm to use only O(k) extra space?

*/


#include<vector>
vector<int> Solution::getRow(int A) {
    
    vector <int> v;
    int i = A + 1, c = 1;
    for(int j=1; j<=i; j++)
    {
        v.push_back(c);
        c = c*(i - j)/j;
    }
    return v; 
}
