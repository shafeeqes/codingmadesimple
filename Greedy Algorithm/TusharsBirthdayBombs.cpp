/*
It’s Tushar’s birthday today and he has N friends.

Friends are numbered [0, 1, 2, ...., N-1] and ith friend have a positive strength B[i].

Today being his birthday, his friends have planned to give him birthday bombs (kicks).

Tushar's friends know Tushar's pain bearing limit and would hit accordingly.

If Tushar’s resistance is denoted by A (>=0) then find the lexicographically smallest order of friends to kick Tushar so that the cumulative kick strength (sum of the strengths of friends who kicks) doesn’t exceed his resistance capacity and total no. of kicks hit are maximum.

Also note that each friend can kick unlimited number of times (If a friend hits x times, his strength will be counted x times)

Return the lexicographically smallest array of maximum length where the ith index represents the index of the friend who will hit.

NOTE:

[a1, a2, ...., am] is lexicographically smaller than [b1, b2, .., bm] if a1 < b1 or (a1 = b1 and a2 < b2) ... .
Input cases are such that the length of the answer does not exceed 100000.


Problem Constraints
1 <= N <= 100

1 <= A <= 15 * 106

1 <= B[i] <= 105



Input Format
The first argument contains an integer, A of length N.

The second argument contains an array of integers B.



Output Format
Return an array of integer, as described in the problem statement.



Example Input
Input 1:

 A = 12
 B = [3, 4]
Input 2:

 A = 11
 B = [6, 8, 5, 4, 7]


Example Output
Output 1:

 [0, 0, 0, 0]
Output 2:

 [0, 2]
 */
 
 vector<int> Solution::solve(int a, vector<int> &b) {
    int m=*min_element(b.begin(),b.end());
    int ind;
    for(int i=0;i<b.size();i++){
        if(b[i]==m){
            ind=i;
            break;
        }
    }
    int len=a/m;
    if(a%m==0){
        vector<int> ans;
        for(int i=0;i<a/m;i++){
            ans.push_back(ind);
        }
        return ans;
    }else{
        int temp=a-(a/m)*m;
        vector<int> ans;int i=0;
        while(ans.size()<len){
            if((b[i]-m)<=temp){
                ans.push_back(i);
                temp=temp-(b[i]-m);
            }else{
                i++;
            }
        }
        return ans;
    }
}
