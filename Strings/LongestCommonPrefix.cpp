/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& A) {
        int n = A.size();
        if(n == 0)  return "";
        
        string prefix = "";
        int index = 0;
        //comparing characters of first string to every other string
        for(char c:A[0]){
            for(int i = 1; i < n; i++){
                // if the index is greater than current string size or the
                // characters doesnt match
                if(index >= A[i].size() or c!= A[i][index])
                    return prefix;
            }
            prefix += c;
            index++;
        }
        
        return prefix;
    }
};

//Slower but easier

class Solution {
public:
    string longestCommonPrefix(vector<string>& A) {
        int n = A.size();
        if(n == 0)  return "";
        sort(A.begin(),A.end());

        int m = min(A[0].size(),A[n - 1].size()); 

        string first = A[0];
        string last = A[n - 1]; 
        int i = 0; 
        while (i < m && first[i] == last[i]) 
            i++; 

        string pre = first.substr(0, i);
        if(i==0)    return "";
        return pre;
    }
};
