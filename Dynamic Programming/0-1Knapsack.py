"""
You are given weights and values of N items, put these items in a knapsack of
capacity W to get the maximum total value in the knapsack. Note that we have only
one quantity of each item.

In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent
values and weights associated with N items respectively. Also given an integer W which
represents knapsack capacity, find out the maximum value subset of val[] such that sum 
of the weights of this subset is smaller than or equal to W. You cannot break an item, 
either pick the complete item, or don’t pick it (0-1 property).

Input:
The first line of input contains an integer T denoting the number of test cases. Then
T test cases follow. Each test case consists of four lines.
The first line consists of N the number of items.
The second line consists of W, the maximum capacity of the knapsack.
In the next line are N space separated positive integers denoting the values of the N
items,
and in the fourth line are N space separated positive integers denoting the weights of 
the corresponding items.

Output:
For each testcase, in a new line, print the maximum possible value you can get with the 
given conditions that you can obtain for each test case in a new line.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 1000
1 ≤ W ≤ 1000
1 ≤ wt[i] ≤ 1000
1 ≤ v[i] ≤ 1000

Example:
Input:
2
3
4
1 2 3
4 5 1
3
3
1 2 3
4 5 6
Output:
3
0
"""
def knapsack(val,weight,maxW):
    n = len(val)
    T = [[0 for w in range(maxW+1)] for i in range(n+1)]
    # this array is 1 row bigger in length than values
    # careful to take i-1 when accessing value and weight vector
    for i in range(n+1):
        for w in range(maxW+1):
            # i = 0 means no item this is a dummy row
            # but w = 0 means we dont have any allotted weight
            # so we cant possibly choose any item
            if i==0 or w==0:
                T[i][w] = 0
            # if weight of current item is greater than w
            # then also we cant choose this item
            elif weight[i-1]>w:
                T[i][w] = T[i-1][w]
            # max(either we dont choose the item, so value will be same as row
            # above ie, T[i-1[w] or we choose this item and choose the value of 
            # current weight - current item weight value in the previous row)
            # this is like if we choose this item we have available weight = current
            # weight - current item weight so we can choose the value only 
            #from that column
            else:
                T[i][w] = max(T[i-1][w],val[i-1]+T[i-1][w-weight[i-1]])
    
    return T[n][maxW]

    
if __name__ == "__main__": 
    t = int(input())
    for i in range(t):
        N = int(input())
        maxW = int(input())
        val = [int(i) for i in input().strip().split()]
        weight = [int(i) for i in input().strip().split()]
        
        print(knapsack(val,weight,maxW,N))
