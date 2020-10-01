"""
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets
"""

class Solution(object):
    def isAnagram(self, s1, s2):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if(len(s1)!=len(s2)):
            return False
        
        c1count = [0]*26
        c2count = [0]*26
        
        for char in s1:
            c1count[ord(char)-97] +=1;
            
        for char in s2:
            c2count[ord(char)-97] +=1;
        
        for i in range(26):
            if(c1count[i]!=c2count[i]):
                return False
            
        return True
