/*

https://www.geeksforgeeks.org/longest-subsegment-1s-formed-changing-k-0s/

similar to this but different;

Q: An array of size 26 is given.
  corresponding to each alphabet a-z, 0 or 1 is given
  0 means special char, 1 means normal char;
  
  Q is to find the max length of substring with atmost k special characters.
 
 */
 
#include <iostream> 
using namespace std; 
  
int longestSubSeg(string s, string special, int k) 
{ 

//special string contains 26 char either 0 or 1
//string s can be of any size

    int n = s.size();
    if(n < 1) return n;
    
    int count = 0;
    for(int i = 0
    int l = 0; 
    int max_len = 0; 
  
    // i decides current ending point 
    for (int i = 0; i < n; i++) { 
        if (a[i] == 0) 
            cnt0++; 
  
        // If there are more 0's move 
        // left point for current ending 
        // point. 
        while (cnt0 > k) { 
            if (a[l] == 0) 
                cnt0--; 
            l++; 
        } 
  
        max_len = max(max_len, i - l + 1); 
    } 
  
    return max_len; 
} 
 
 
  
