/*
mplement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m =needle.size();
        if (needle == "")   return 0;
        for(int i =0; i<n; i++){
           if(haystack[i] == needle[0])
               if(i+m-1 < n and (haystack.substr(i,m)==needle))
                   return i;
        }
        return -1;
    }
};

//Alternate solution
//Slower but can be optimized using a stronger hash

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m =needle.size();
        int needlehash = 0;
        if(m == 0) return 0;
        if(n==0) return -1;
        for(char a:needle){
            needlehash += int(a);
        }
        int hayhash = 0;
        for(int i=0;i<m;i++){
            hayhash += int(haystack[i]);
        }
        if(hayhash == needlehash){
            if(haystack.substr(0,m) == needle){
                    return 0; 
            }
        }
        for(int i= m; i<n; i++){
            hayhash -= int(haystack[i-m]);
            hayhash += int(haystack[i]);
                        
            if(hayhash == needlehash){
                if(haystack.substr(i-m+1,m) == needle){
                    return i-m+1; 
                }
            }
        }
        return -1;   
    }  
};

