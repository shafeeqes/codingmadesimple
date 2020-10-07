"""
There are n bulbs that are initially off. You first turn on all the bulbs. Then, you turn off every second bulb. On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the i-th round, you toggle every i bulb. For the n-th round, you only toggle the last bulb. Find how many bulbs are on after n rounds.

Example:

Input: 3
Output: 1 
Explanation: 
At first, the three bulbs are [off, off, off].
After first round, the three bulbs are [on, on, on].
After second round, the three bulbs are [on, off, on].
After third round, the three bulbs are [on, off, off]. 

So you should return 1, because there is only one bulb is on.
"""

"""
Consider each number right from 1,2,3.....N
Every swich is on. If switch is to change its state, then that particular 
number should have odd number of factors. Think about only that switch. Lets say number 5. 
5 will be hit by 1 and 5 , it has even factors, so there will no change in state. 
Guess which numbers have odd number of factors ? Yes, perfect squares have odd no of factors. 
They will be hit by odd times, leaving their position changed.
So at last perfect squares will be the numbers which are on now

so under 9, only 1 and 4 will be hit odd number of times. so ans = 2. from 9 it will be 3.
similarly upto 15, only 1,4,9 will be hit odd number of times. so ans  is 3.
 so we can easily just return the integer part of sqrt(n)
"""

class Solution:
    def bulbSwitch(self, n: int) -> int:
        
        return int(n**0.5);

"""

If a particular number n is divisible by k , it means it will also be divisible by n/k.
So it will bring it to original state i.e.off. So toggling at kth iteration will turn ON but toggling at (n/k)th iteration will bring it to OFF. So no change.
But for a prefect square sqrt(n) will only toggle it once , so it will be overall ON.

"""
