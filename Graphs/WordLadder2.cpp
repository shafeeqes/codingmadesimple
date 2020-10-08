/*
Given two words (start and end), and a dictionary, find the shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
If there are multiple such sequence of shortest length, return all of them. Refer to the example for more details.

Note:

All words have the same length.
All words contain only lowercase alphabetic characters.
Input Format

The first argument is string start.
The second argument is string end.
The third argument is an array of strings dict
Output Format

Return all transformation sequences such that first word of each sequence is start and last word is end, all intermediate words belongs to dictionary(dict) and consecutive words had atmost 1 difference.  
Example :

:

start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return

  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
  */
  
  
  bool isadjacent(string A, string B){
    int n = A.size();
    int count = 0;
    for(int i=0 ;i<n ;i++){
        if(A[i]!=B[i])
            count++;
        if(count>1)
            return false;
    }
    return true;
}
 
vector<vector<string> > Solution::findLadders(string start, string end, vector<string> &d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<vector<string> > ans;
    queue<vector<string>> paths;
    set<string> dict;
    
    if(start==end){
        ans.push_back({start});
            return ans;
    }
    
    for(int i=0;i<d.size();++i){
        dict.insert(d[i]);
    }
    
    paths.push({start});
    
    int level = 1;
    int min_level = INT_MAX;
    unordered_set<string>visited;
    
    while(!paths.empty()){
        
        vector<string> path = paths.front();
        paths.pop();
        
        if(path.size()>level){
            for(auto w:visited){
                dict.erase(w);
            }
            visited.clear();
            if(path.size()>min_level)
                break;
            else
                level = path.size();
        }
        
        string last = path.back();
        
        for(auto it : dict){
            string word = it;
            if(isadjacent(last,word)){
                vector<string>newpath = path;
                   newpath.push_back(word);
                   visited.insert(word);
            
                if(word ==end){
                    min_level = level;
                    ans.push_back(newpath);
                }
                else
                    paths.push(newpath);
            }
        }
    }
    
    return ans;
}
