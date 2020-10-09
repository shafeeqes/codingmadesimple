/*

Problem Description

Given A and B you have to find all stepping numbers in range A to B.

The stepping number:

A number is called as a stepping number if the adjacent digits have a difference of 1.

e.g. 123 is stepping number, but 358 is not a stepping number



Input Format
First argument is an integer A.

Second argument is an integer B.



Output Format
Return a integer array sorted in ascending order denoting the stepping numbers between A and B.



Example Input
Input 1:

 A = 10
 B = 20


Example Output
Output 1:

 [10, 12]


Example Explanation
Explanation 1:

 All stepping numbers are 10 , 12 
 */
 
 
 void stepno(int A,int B, int stepno, vector<int> &ans){
    
    queue<int> q;
    q.push(stepno);
    
    while(!q.empty()){
        int no = q.front();
        q.pop();
        
        if(no>=A && no<=B)
            ans.push_back(no);
            
        if(no ==0 || no>B )
            continue;
            
        int lastdigit = no % 10;
        // two cases. next number  = lastdigit + 1 or -1
        int stepA = no*10 + lastdigit -1;
        int stepB = no*10 + lastdigit +1;
        
        // if last digit is 0, say for 210, then pushing 0 - 1 will not do any good
        // ie, 210 * 10 + 0 - 1 will be 2099 so we push only stepB 2101
        if(lastdigit==0){
            q.push(stepB);
        }
        // if last digit is 9, say 89, 89 + 9 + 1 will be 99, which is wrong
        // so we push only stepA 89 *10 + 9 -1 = 898
        else if(lastdigit ==9){
            q.push(stepA);
        }
        //else both are okay
        else{
            q.push(stepA);
            q.push(stepB);
        }
    }
    
}
vector<int> Solution::stepnum(int A, int B) {

    vector<int> ans;
    for(int i = 0; i <= 9; i++)
    {
        stepno(A,B,i,ans);
    }
    sort(ans.begin(),ans.end());
    return ans;
}
