/*Devu and his brother love each other a lot. As they are super geeks, they only like to play with arrays. They are given two arrays a and b by their father. The array a is given to Devu and b to his brother.

As Devu is really a naughty kid, he wants the minimum value of his array a should be at least as much as the maximum value of his brother's array b.

Now you have to help Devu in achieving this condition. You can perform multiple operations on the arrays. In a single operation, you are allowed to decrease or increase any element of any of the arrays by 1. Note that you are allowed to apply the operation on any index of the array multiple times.

You need to find minimum number of operations required to satisfy Devu's condition so that the brothers can play peacefully without fighting.

Input
The first line contains two space-separated integers n, m (1 ≤ n, m ≤ 105). The second line will contain n space-separated integers representing content of the array a (1 ≤ ai ≤ 109). The third line will contain m space-separated integers representing content of the array b (1 ≤ bi ≤ 109).

Output
You need to output a single integer representing the minimum number of operations needed to satisfy Devu's condition.

Examples
inputCopy
2 2
2 3
3 5
outputCopy
3
inputCopy
3 2
1 2 3
3 4
outputCopy
4
inputCopy
3 2
4 5 6
1 2
outputCopy
0
Note
In example 1, you can increase a1 by 1 and decrease b2 by 1 and then again decrease b2 by 1. Now array a will be [3; 3] and array b will also be [3; 3]. Here minimum element of a is at least as large as maximum element of b. So minimum number of operations needed to satisfy Devu's condition are 3.

In example 3, you don't need to do any operation, Devu's condition is already satisfied.

*/

#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int n,m;
    long long ans = 0;
    vector<int> a, b,c;
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        int t;
        cin>>t;
        a.push_back(t);
        c.push_back(t);
    }
    for(int i=0; i<m; i++)
    {
        int t;
        cin>>t;
        b.push_back(t);
        c.push_back(t);
    }
    
    sort(c.begin(),c.end());
    int t = c[m];
    
    for(int i=0; i<n; i++)
        ans += max(0,t-a[i]);
    for(int i=0; i<m; i++)
        ans += max(0,b[i]-t);
        
    cout<<ans;
}
