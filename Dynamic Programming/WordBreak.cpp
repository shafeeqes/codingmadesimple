/*
iven a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false

*/
//DP


class Solution {
public:
   
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set <string> words;
        for(string word:wordDict){
            words.insert(word);
        }
        int n = s.size();
        vector<bool> dp(n+1,false);
        //empty string, always true
        dp[0] = true;
        
        //for length from one to n
        for(int len = 1; len <= n; len++){
            for(int i = 0; i<len; i++){
                //if the word can be made upto a previous character and the rest of
                //the word is already in the dictionary, then dp of this length is true
                if(dp[i] and words.find(s.substr(i,len-i))!=words.end()){
                    dp[len] = true;
                    break;
                }
            }
        }    
        return dp[n];
    
    }
};



//hashset. slow
class Solution {
public:
    
    unordered_set <string> words;
    unordered_map <string,bool> wordmap;
    bool wordBreak(string s, vector<string>& wordDict) {
        
        for(string word:wordDict){
            words.insert(word);
        }
        return dfs(s);
 
    }
    bool dfs(string s){
        int n = s.size();
        if(s == "") return true;
        if(wordmap.find(s)!= wordmap.end()){
            return wordmap[s];
        }
        for(int i = 1; i <=n ; i++){
            string nextword = s.substr(i,n-1);
            if(words.find(s.substr(0,i))!= words.end() and dfs(nextword)){
                wordmap[nextword] = true;
                return true;
            }
        }
        wordmap[s] = false;
        return false;
    
    }
};

/*

 vector<vector<bool>> dp(n+1, vector<int>(n+1,false));
        
        int len;
        for(len = 1; len <= n; len++ ){
            for(int i = 0; i < n - len; i++){
                string t = s.substr(i,len);
                if(words.find(t) != words.end()){
                    dp[i][]
                }
            }
        }
        
        
        */
