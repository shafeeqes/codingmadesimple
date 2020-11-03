/*

https://www.geeksforgeeks.org/longest-subsegment-1s-formed-changing-k-0s/

similar to this but different;

Q: An array of size 26 is given.
  corresponding to each alphabet a-z, 0 or 1 is given
  0 means special char, 1 means normal char;
  
  Q is to find the max length of substring with atmost k special characters.
 
 */
 
#include <iostream> 
using namespace std; 
  
int longestSubSeg(string s, string special, int k) 
{ 

//special string contains 26 char either 0 or 1
//string s can be of any size

    int n = s.size();
    if(n < 1) return n;
    
    vector<int> special_indices;
  
    int count = 0;
    for(int i = 0; i < n; i++){
      int ch = s[i] - 'a';
      //ch will be 0 for a, 1 for b, etc... 25 for z
      
      //if the current char is special
      if(special[ch] == '0'){
        count ++;
        //keep track of index of special chars
        // special_indices will be of size count, obv
        special_indices.push_back(i);
      } 
    }
  
    //if there are max k special chars, then whole string can be the ans
    //so length is n
    if(count <= k){
      return n;
    }
    
    int start = 0;
    int index = 0; //for keeping track of last special index
    int max_len = 0; 
  
    count = 0; //reset count
  
    // i decides current ending point 
    for (int i = 0; i < n; i++) { 
        int ch = s[i] - 'a';
        if (special[ch] == '0'){
          if(count < k){
            count++;
          }
          //when count reaches k
          else{
            index++;
            //reset start to last found special index + 1,
            //we are standing on a special char and we skipped the last standing special char
            //so no need to inc or dec count
            start = special_indices[index] + 1;
          }
        } 
        //update max_len with each iteration
        max_len = max(max_len, i - start + 1); 
    } 
  
    return max_len; 
} 
 
 
  
