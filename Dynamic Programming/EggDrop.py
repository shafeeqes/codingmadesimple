"""/*
Suppose you have N eggs and you want to determine from which floor in a K-floor building
you can drop an egg such that it doesn't break. You have to determine the minimum number
of attempts you need in order find the critical floor in the worst case while using the
best strategy.There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
For more description on this problem see wiki page

Input:
The first line of input is  T denoting the number of testcases.Then each of the T lines
contains two positive integer N and K where 'N' is the number of eggs and 'K' is number of floor in building.

Output:
For each test case, print a single line containing one integer the minimum number of
attempt you need in order find the critical floor.

Constraints:
1<=T<=30
1<=N<=10
1<=K<=50

Example:
Input:
2
2 10
3 5

Output:
4
3

Solution:

In this post, we will discuss a solution to a general problem with ‘n’ eggs and ‘k’ floors. 
The solution is to try dropping an egg from every floor(from 1 to k) and recursively calculate 
the minimum number of droppings needed in the worst case. The floor which gives the minimum 
value in the worst case is going to be part of the solution.
In the following solutions, we return the minimum number of trials in the worst case; these 
solutions can be easily modified to print floor numbers of every trial also.

Meaning of a worst-case scenario: Worst case scenario gives the user the surety of the threshold
floor. For example- If we have ‘1’ egg and ‘k’ floors, we will start dropping the egg from the 
first floor till the egg breaks suppose on the ‘kth’ floor so the number of tries to give us surety is ‘k’.

1) Optimal Substructure:
When we drop an egg from a floor x, there can be two cases (1) The egg breaks (2) The egg doesn’t break.

If the egg breaks after dropping from ‘xth’ floor, then we only need to check for floors lower 
than ‘x’ with remaining eggs as some floor should exist lower than ‘x’ in which egg would not 
break; so the problem reduces to x-1 floors and n-1 eggs.
If the egg doesn’t break after dropping from the ‘xth’ floor, then we only need to check for floors
higher than ‘x’; so the problem reduces to ‘k-x’ floors and n eggs.
Since we need to minimize the number of trials in worst case, we take the maximum of two cases. 
We consider the max of above two cases for every floor and choose the floor which yields minimum number of trials.

k ==> Number of floors
n ==> Number of Eggs
eggDrop(n, k) ==> Minimum number of trials needed to find the critical
floor in worst case.

eggDrop(n, k) = 1 + min{max(eggDrop(n – 1, x – 1), eggDrop(n, k – x)), where x is in {1, 2, …, k}}

Concept of worst case:
For example :
Let there be ‘2’ eggs and ‘2’ floors then-:



If we try throwing from ‘1st’ floor:
Number of tries in worst case= 1+max(0, 1)
0=>If the egg breaks from first floor then it is threshold floor (best case possibility).
1=>If the egg does not break from first floor we will now have ‘2’ eggs and 1 floor to test which will give answer as
‘1’.(worst case possibility)
We take the worst case possibility in account, so 1+max(0, 1)=2

If we try throwing from ‘2nd’ floor:
Number of tries in worst case= 1+max(1, 0)
1=>If the egg breaks from second floor then we will have 1 egg and 1 floor to find threshold floor.(Worst Case)
0=>If egg does not break from second floor then it is threshold floor.(Best Case)
We take worst case possibility for surety, so 1+max(1, 0)=2.

The final answer is min(1st, 2nd, 3rd….., kth floor)
So answer here is ‘2’.

*/
/*
Formally for filling DP[i][j] state where ‘i’ is the number of eggs and ‘j’ is the number of floors:

We have to traverse for each floor ‘x’ from ‘1’ to ‘j’ and find minimum of:
(1 + max( DP[i-1][j-1], DP[i][j-x] )).
This simulation will make things clear:

i => Number of eggs
j => Number of floors
Look up find maximum
Lets fill the table for the following case:
Floors = ‘4’
Eggs = ‘2’

1 2 3 4

1 2 3 4 => 1

1 2 2 3 => 2

For ‘egg-1’ each case is the base case so the
number of attempts is equal to floor number.

For ‘egg-2’ it will take ‘1’ attempt for 1st
floor which is base case.

For floor-2 =>
Taking 1st floor 1 + max(0, DP[1][1])
Taking 2nd floor 1 + max(DP[1][1], 0)
DP[2][2] = min(1 + max(0, DP[1][1]), 1 + max(DP[1][1], 0))



For floor-3 =>
Taking 1st floor 1 + max(0, DP[2][2])
Taking 2nd floor 1 + max(DP[1][1], DP[2][1])
Taking 3rd floor 1 + max(0, DP[2][2])
DP[2][3]= min(‘all three floors’) = 2

For floor-4 =>
Taking 1st floor 1 + max(0, DP[2][3])
Taking 2nd floor 1 + max(DP[1][1], DP[2][2])
Taking 3rd floor 1 + max(DP[1][2], DP[2][1])
Taking 4th floor 1 + max(0, DP[2][3])
DP[2][4]= min(‘all four floors’) = 3
*/
/*
Time Complexity: O(n*k^2).
Where ‘n’ is the number of eggs and ‘k’ is the number of floors, as we use a nested for loop ‘k^2’ times for each egg
Auxiliary Space: O(n*k).
As a 2-D array of size ‘n*k’ is used for storing elements.
*/
"""

def solution(n,k):
    
    #floors as columns eggs as rows
    T = [[0 for x in range(k + 1)] for x in range(n + 1)] 
    
    # We need one trial for one floor and0 trials for 0 floors 
    for i in range(1,n+1):
        T[i][1] = 1;
        T[i][0] = 0
     # We always need j trials for one egg and j floors.
    for j in range(1,k+1):
        T[1][j] = j
    
    for i in range(2, n + 1): 
        for j in range(2, k + 1): 
            T[i][j] = float('inf')
            for x in range(1, j + 1): 
                res = 1 + max(T[i-1][x-1], T[i][j-x]) 
                if res < T[i][j]: 
                    T[i][j] = res  
    return T[n][k]    

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        n,k = [int(i) for i in input().strip().split()]
        print(solution(n,k))
