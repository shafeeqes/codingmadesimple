/*
Given a string, sort it in decreasing order based on the frequency of characters.

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
      
      unordered_map<char, int> M;
      for(char c:s)
        M[c]++;
      
      priority_queue< pair<char, int>, vector<pair<char, int>>,
                      function<bool(pair<char, int>, pair<char, int>)>>
        max_heap([](pair<char, int> a, pair<char, int> b){return a.second < b.second;});
      
      unordered_map<char, int>::iterator it = M.begin();
      
      while(it != M.end())
        max_heap.push(*it++);
      
      int i = 0;
      while(!max_heap.empty())
      {
        pair<char, int> p = max_heap.top();
        int freq = p.second;
        char c = p.first;
        while(freq--)
          s[i++] = c;
        max_heap.pop();
      }
      
      return s;
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
