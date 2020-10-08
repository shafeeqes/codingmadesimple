/*

You are given an integer N. You have to find smallest multiple of N which consists of digits 0 and 1 only. Since this multiple could be large, return it in form of a string.

Note:

Returned string should not contain leading zeroes.
For example,

For N = 55, 110 is smallest multiple consisting of digits 0 and 1.
For N = 2, 10 is the answer.
*/

/*
we take 1 first, push 10 and 11, check. then push 100 and 101 for 10 and 110 and 111 for ll.
again 1000 and 1001 for 100 and so on.if at any point remainder is 0, we have found our element
*/
string Solution::multiple(int A) {
    
    queue<int> q;
    
    q.push((1%A));
    vector<int> vis(A+1,-1);
    vis[1%A]=1;
    vector<pair<int,char>> par(A+1,{-1,'1'});
    while(!q.empty()){
       int tp = q.front();
        q.pop();
        
        if(tp==0){
            string s="";
            
            s+=par[0].second;
            int p = par[0].first;
            while(p!=-1){
                s+=par[p].second;
                p = par[p].first;
            }
            
            reverse(s.begin(),s.end());
            
            return s;
        }
        
        int a1 = (tp*10)%A;
        int a2 = ((tp*10)%A+1)%A;
        if(vis[a1]==-1){   
        
         q.push(a1);
          
         vis[a1] =1;
         par[a1] = {tp,'0'};
        }
         
        if(vis[a2]==-1){   
         
          q.push(a2);
          
          vis[a2]=1;
          
          par[a2] = {tp,'1'};
        }
    }
}


//slower method


// Method return t % N, where t is stored as 
// a string 
int mod(string t, int N) 
{ 
    int r = 0; 
    for (int i = 0; i < t.length(); i++) 
    { 
        r = r * 10 + (t[i] - '0'); 
        r %= N; 
    } 
    return r; 
} 
  
// method returns smallest multiple which has 
// binary digits 
string Solution::multiple(int N)
{ 
    queue<string> q; 
    unordered_set<int> visit; 
  
    string t = "1"; 
  
    //  In starting push 1 into our queue 
    q.push(t); 
  
    //  loop untill queue is not empty 
    while (!q.empty()) 
    { 
        // Take the front number from queue. 
        t = q.front();      q.pop(); 
  
        // Find remainder of t with respect to N. 
        int rem = mod(t, N); 
  
        // if remainder is 0 then we have 
        // found our solution 
        if (rem == 0) 
            return t; 
  
        // If this remainder is not previously seen, 
        // then push t0 and t1 in our queue 
        else if(visit.find(rem) == visit.end()) 
        { 
            visit.insert(rem); 
            q.push(t + "0"); 
            q.push(t + "1"); 
        } 
    } 
}
