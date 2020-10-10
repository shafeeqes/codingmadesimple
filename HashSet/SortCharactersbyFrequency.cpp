/*
Given a string, sort it in decreasing order based on the a.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/


class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> hash;
        for(char a:s){
            hash[a]++;
        }
        
        vector<pair<char, int> > A;
        for(auto it:hash){
            A.push_back(it);
        }
        sort(A.begin(),A.end(),cmp);
         //sort(A.begin(),A.end(), [](pair<char,int> a,pair<char,int> b) ->bool {return a.second > b.second;});
         //sort(A.begin(),A.end(), [](pair<char,int> a,pair<char,int> b) {return a.second > b.second;});
        string ans = "";
        for(auto item:A){
            while(item.second--){
                ans+= item.first;
            }
        }
        return ans;
    }
    
    static bool cmp(pair<char, int> & a, pair<char, int> & b) 
    { 
        return a.second > b.second; 
    } 
};


class Solution {
public:
    
    string frequencySort(string s) {
        unordered_map<char,int> hash;
        for(char a:s){
            hash[a]++;
        }
        
        priority_queue< pair<char, int>, vector<pair<char, int>>,
                function <bool(pair<char, int>, pair<char, int>)>> 
                    q([](pair<char, int> a, pair<char, int>  b){return a.second<b.second;});
        
        
        for(auto it:hash){
            q.push(it);
        }
        
        string ans = "";
        while(!q.empty()){
            pair<char,int> item = q.top();
            while(item.second--){
                ans+= item.first;
            }
            q.pop();
        }
        return ans;
    }
    
};



class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freqMap; // {char, frequency}
        multimap<int, char, greater<int>> sortedFreqsMap;
        string res = "";
        for (char chr : s) {
            freqMap[chr]++;
        }
        for (auto tuple : freqMap) {
            sortedFreqsMap.insert({tuple.second, tuple.first});
        }
        for (auto tuple : sortedFreqsMap) {
            int freq = tuple.first;
            while (freq--) {
                res += tuple.second;
            }
        }
        return res;
    }
};
