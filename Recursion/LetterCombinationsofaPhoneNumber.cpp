/*

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/

class Solution {
public:
    vector<string> ans;
    
    vector<string> letterCombinations(string digits) {
        
        int n = digits.size();
        if (n < 1){
            return {};
        }
        vector<int> A;
        for(char c:digits){
            if(c -'0' >1 and c-'0' <=9)
                A.push_back(c-'0');
        }
        make(A,"",0);
        
        return ans;
    }
    
    void make(vector<int> &A, string temp, int index){
        
        if(temp.size() == A.size()){
            ans.push_back(temp);
            return;
        }
        //add first letter corresponding to first number
        // make recursive call with next letter
        vector<char> letters = getLetters(A[index]);
        for(char c:letters){
            string backup = temp;
            //make change
            temp += c;
            make(A,temp,index+1);
            //reverse change
            temp = backup;
        } 
    }
    
    vector<char> getLetters(int n){
        switch(n){
            case 2 : return {'a','b','c'};
            case 3 : return {'d','e','f'};
            case 4 : return {'g','h','i'};
            case 5 : return {'j','k','l'};
            case 6 : return {'m','n','o'};
            case 7 : return {'p','q','r','s'};
            case 8 : return {'t','u','v'};
            case 9 : return {'w','x','y','z'};
        }
        return {};
    }
    
};
