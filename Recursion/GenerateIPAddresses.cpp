/*
Given a string s containing only digits, return all possible valid IP addresses that can be obtained from s. You can return them in any order.

A valid IP address consists of exactly four integers, each integer is between 0 and 255, separated by single dots and cannot have leading zeros. For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses and "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses. 

 

Example 1:

Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]
Example 2:

Input: s = "0000"
Output: ["0.0.0.0"]
Example 3:

Input: s = "1111"
Output: ["1.1.1.1"]
Example 4:

Input: s = "010010"
Output: ["0.10.0.10","0.100.1.0"]
Example 5:

Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 

Constraints:

0 <= s.length <= 3000
s consists of digits only.
*/


class Solution {
public:
    vector<string> ans;
    vector<string> restoreIpAddresses(string s) {
        
        int n = s.size();
        if (n < 4 or n > 12)
            return {};
        vector<string> tokens;
        generate(s, 0, tokens);
            
        return ans;
    }
    
    void generate(string s, int index, vector<string> &tokens){
        
        //if we have 4 valid tokens and we have reached the final index
        if(index == s.size() and tokens.size() == 4){
            string t = "";
            for(string str : tokens){
                t += str + ".";
            }
            //to remove the last "."
            ans.push_back(t.substr(0,t.size()-1));
        }
        if(index >= s.size() or tokens.size() >= 4){
            return;
        }
        
        tokens.push_back(s.substr(index,1));
        generate(s,index + 1,tokens);
        tokens.pop_back();
        
        //generating 2digit strings
        string s2 = s.substr(index,2);
        if(stoi(s2) >= 10){
            tokens.push_back(s2);
            generate(s,index+2, tokens);
            tokens.pop_back();
        }
        //generating 3digit strings
        string s3 = s.substr(index,3);
        if(stoi(s3) >= 100 and stoi(s3) <= 255){
            tokens.push_back(s3);
            generate(s,index+3, tokens);
            tokens.pop_back();
        }
        
    }
};
