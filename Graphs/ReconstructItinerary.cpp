/*
Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary
in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a
single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
One must use all the tickets once and only once.
Example 1:

Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
Example 2:

Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
             But it is larger in lexical order.
             */
             
             
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        //multiset is must because , duplicate tickets can occur
        //so we have to visit twice
        unordered_map<string, multiset<string>> m;
        
        for(auto ticket: tickets){
            string src = ticket[0];
            string dest = ticket[1];
            m[src].insert(dest);
        }
        
        //we use stack not to meet a dead end
        stack<string> s;
        vector<string> ans;
        
        s.push("JFK");
        while(!s.empty()){
            string curr = s.top();
            //if no place to visit from the curr stop, pop it from the stack
            if(m[curr].size() == 0){
                s.pop();
                ans.push_back(curr);
            }
            //else visit it and add it to stack
            else{
                string next = *m[curr].begin();
                s.push(next);
                m[curr].erase(m[curr].begin());
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
