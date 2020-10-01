"""
Given an input stream of N characters consisting only of lower case alphabets. The task is to find the first non repeating character, each time a character is inserted to the stream. If no non repeating element is found print -1.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer N denoting the size of the stream. Then in the next line are x characters which are inserted to the stream.

Output:
For each test case in a new line print the first non repeating elements separated by 
spaces present in the stream at every instinct when a character is added to the stream,
if no such element is present print -1.

Constraints:
1 <= T <= 200
1 <= N <= 500

Example:
Input:
2
4
a a b c
3
a a c

Output:
a -1 b b
a -1 c

Explanation:
Test Case 1: a a b c
The step wise first non-repeating elements are made bold:
a (print a)
a a (no non-repeating element, print -1)
a a b (print b)
a a b c (print b)
Result: a -1 b b

Test Case 2: a a c
a (print a)
a a (no non-repeating element, print -1)
a a c (print c)
Result: a -1 c
"""
#Time O(n) I guess
#space O(n)

from collections import deque
def solution(A):
    ans = []
    q = deque()
    m = [0]*26
    for c in A:
        q.append(c);
        m[ord(c)-97]+=1
        while q and m[ord(q[0])-97]>1:
            q.popleft()
        # instead of .isempty()
        if q:
            ans.append(q[0])
        else:
            ans.append("-1")
    return ans
    


t = int(input())
for i in range(t):
    N = int(input())
    s = input().split()
    ans = solution(s)
    
    print(*ans,sep=' ')
