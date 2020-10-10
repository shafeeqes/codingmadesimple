/*

Given a list accounts, each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some email that is common to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

Example 1:
Input: 
accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
Explanation: 
The first and third John's are the same person as they have the common email "johnsmith@mail.com".
The second John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
Note:

The length of accounts will be in the range [1, 1000].
The length of accounts[i] will be in the range [1, 10].
The length of accounts[i][j] will be in the range [1, 30].
*/


class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        unordered_map <string,int> map;
        
        int n = accounts.size();
        parent.resize(n);
        rank.resize(n,0);
        
        for(int i = 0; i< n; i++)
            parent[i] = i;
        
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string email = accounts[i][j];
                //if email is already present, Union this index with original index
                if(map.find(email) != map.end()){
                    Union(map[email], i); 
                }
                else{
                    map.insert({email, i});
                }
            }
        }
        
        unordered_map<int,vector<string>> tempResult;
        //create new map with index and vector of strings
        //NB: index should be the parent most, so use find
        for(auto it: map){
            tempResult[find(it.second)].push_back(it.first);
        }
        
        vector<vector<string>>result (tempResult.size());
        int k = 0;
        for(auto it: tempResult){
            int index = it.first;
            vector<string> emails = it.second;
            //sort emails
            sort(it.second.begin(),emails.end());
            //push name
            result[k].push_back(accounts[index][0]);
            //push emails
            for(string email:emails){
                result[k].push_back(email);
            }
            //increment index of result
            k++;  
        }
        //another method, also works
        /*
        vector<vector<string>> ans(n);
        for(int i = 0; i < n; i++){
            ans[i].push_back(accounts[i][0]);
        }
        
        for(auto it: map){
            string email = it.first;
            int parent_index = find(it.second);
            ans[parent_index].push_back(email);
        }
        
        vector<vector<string>> result;
        for(auto item : ans){
            if(item.size() > 1){
                result.push_back(item);
            }
        }
        
        for(int i = 0; i < result.size(); i++){
            sort(result[i].begin()+1, result[i].end());
        }
        */  
        return result;
        
    }
    
    int find(int x){
        if( parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void Union(int x, int y){
    
        int xp = find(x);
        int yp = find(y);
        if (xp == yp)
            return;
        if( rank[xp] > rank[yp]){
            parent[yp] = xp;
        }
        else if( rank[xp] < rank[yp]){
            parent[xp] = yp;
        }
        else{
            parent[yp] = xp;
            rank[xp] ++;
        }
    }
};
