/*
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.
*/
class Solution {
public:
    string addBinary(string a, string b) {
        
        int n1 = a.size();
        int n2 = b.size();
        int carry = 0;
        int i = n1-1;
        int j = n2-1;
    
        stack<char> s;
        while(i >=0 or j >=0){
            int sum = carry;
            if(i >= 0){
                sum += a[i]-'0';
                i--;
            }
            if(j >= 0){
                sum += b[j] -'0';
                j--;
            }
            s.push( sum % 2 + '0');
            carry = sum/2;
        }
  
        if(carry==1){
            s.push('1');
        }
        string ans;
        while(!s.empty()){
            ans += s.top();
            s.pop();
        }
        return ans;
    }
};



//very naive solution

class Solution {
public:
    string addBinary(string a, string b) {
        
        int n1 = a.size();
        int n2 = b.size();
    
        int carry = 0;
        int i = n1-1;
        int j = n2-1;
    
        stack<char> s;
        while( i >= 0 and j >= 0){
            if(a[i] == '1' and b[j] == '1'){
                if(carry == 0)
                    s.push('0');
                else
                    s.push('1');   
                carry = 1;       
            }
            else if(a[i] == '1' or b[j] == '1'){
                if(carry == 0)
                    s.push('1');
                else{
                    s.push('0');
                    carry = 1;
                }
            }
            else{
                if(carry == 1){
                    s.push('1');
                    carry = 0;
                }
                else
                    s.push('0');
            }
            i--;
            j--;  
        }
        while( i >= 0){
            if(a[i] == '1'){
                if(carry == 0)
                    s.push('1');
                else{
                    s.push('0');
                    carry = 1;
                }
            }
            else{
                if(carry == 1){
                    s.push('1');
                    carry = 0;
                }
                else
                    s.push('0');
            }
            i--;
        }
        while( j >= 0){
            if(b[j] == '1'){
                if(carry == 0)
                    s.push('1');
                else{
                    s.push('0');
                    carry = 1;
                }
            }else{
                if(carry == 1){
                    s.push('1');
                    carry = 0;
                }
                else
                    s.push('0');
            }
            j--;
        }
        
        if(carry==1){
            s.push('1');
        }
        string ans;
        while(!s.empty()){
            ans += s.top();
            s.pop();
        }
 
        return ans;
    }
};
