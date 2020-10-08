/*
Given two words A and B, and a dictionary, C, find the length of shortest transformation sequence from A to B, such that:

You must change exactly one character in every transformation.
Each intermediate word must exist in the dictionary.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.


Input Format:

The first argument of input contains a string, A.
The second argument of input contains a string, B.
The third argument of input contains an array of strings, C.
Output Format:

Return an integer representing the minimum number of steps required to change string A to string B.
Constraints:

1 <= length(A), length(B), length(C[i]) <= 25
1 <= length(C) <= 5e3
Example :

Input 1:
    A = "hit"
    B = "cog"
    C = ["hot", "dot", "dog", "lot", "log"]

Output 1:
    5

Explanation 1:
    "hit" -> "hot" -> "dot" -> "dog" -> "cog"
    */
    
    
  
  // i have absolutely no idea wtf is wrong with this code
//anyway this is the concept

bool isadjacent(string A,string B){
    
    int count = 0;
    for(int i=0 ;i<A.size() ;i++){
        if (A[i]!= B[i])
            count ++;
        
        if(count>1)
            return false;
    }
    return true;
}    

int Solution::solve(string A, string B, vector<string> &dict) {
    
    queue<pair<string,int> > q;
 
    q.push({A, 1});
    int n = dict.size();
    vector<bool> visited(n,false);
    
    while(!q.empty()){
        
        string curr = q.front().first;
        int len = q.front().second;
        q.pop();
        
        if(curr == B)
            return len;
        
        if(isadjacent(curr,B))
            return len+1;
        
        for(int i=0; i < n; i++){
            
            if(!visited[i] && isadjacent(curr,dict[i])){
                    q.push({dict[i],len+1});
                    visited[i] = true;
            }
        }
    }
    return 0;
}



//alternate solution

void transform(string temp,queue<string> &q,unordered_set<string> &mp,unordered_set<string> &vis)
{
    for(int i=0;i<temp.size();i++)
    {
        string s=temp;
        for(int j=0;j<26;j++)
        {
            s[i]='a'+j;
            if(mp.find(s)!=mp.end() && vis.find(s)==vis.end())
            {
                q.push(s);
                vis.insert(s);
            }
        }
    }
}
int Solution::solve(string A, string B, vector<string> &C) {
    int steps=0;
    if(A==B)return 0;
    
    unordered_set<string> mp;
    for(auto x:C)
        mp.insert(x);
    
    if(mp.find(B)==mp.end())
    return steps;
    
    queue<string> q;
    q.push(A);
    unordered_set<string> vis;
    vis.insert(A);
    steps=1;
    while(!q.empty())
    {
        int sz=q.size();
        for(int i=0;i<sz;i++)
        {
            auto temp=q.front();
            q.pop();
            if(temp==B)return steps;
            transform(temp,q,mp,vis);
        }
        steps++;
    }
    return steps;
}
