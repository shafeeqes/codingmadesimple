/*
Given a matrix of dimension r*c where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

So, we have to determine what is the minimum time required to rot all oranges.
A rotten orange at index [i,j] can rot other fresh orange at indexes
[i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. If it 
is impossible to rot every orange then simply return -1.

Input:
The first line of input contains an integer T denoting the number of test cases. 
Each test case contains two integers r and c, where r is the number of rows and c is 
the number of columns in the array a[]. Next line contains space separated r*c elements
each in the array a[].

Output:
Print an integer which denotes the minimum time taken to rot all the oranges (-1 if it is impossible).

Constraints:
1 <= T <= 100
1 <= r <= 100
1 <= c <= 100
0 <= a[i] <= 2

Example:
Input:
2
3 5
2 1 0 2 1 1 0 1 2 1 1 0 0 2 1
3 5
2 1 0 2 1 0 0 1 2 1 1 0 0 2 1

Output:
2
-1

Explanation:
Testcase 1:
2 | 1 | 0 | 2 | 1
1 | 0 | 1 | 2 | 1
1 | 0 | 0 | 2 | 1

Oranges at positions {0,0}, {0, 3}, {1, 3} and {2, 3} will rot oranges at
{0, 1}, {1, 0}, {0, 4}, {1, 2}, {1, 4}, {2, 4} during 1st unit time. And, 
during 2nd unit time, orange at {1, 0} got rotten and will rot orange at {2, 0}. 
Hence, total 2 unit of time is required to rot all oranges.
*/
//An alternate solution is presented at arrays. but T'd say this is still better

// O(n) time
// O(n) space

int solution(vector<vector<int>> &A){
    
    unordered_set <string> fresh;
    unordered_set <string> rotten;
    
    for(int i=0; i<A.size();i++){
        for(int j =0;j<A[i].size(); j++){
            if(A[i][j]!=0){
                string temp = "";
                temp += i+'0';
                temp += j+'0';
            
                if(A[i][j]==1)
                    fresh.insert(temp);
                else if (A[i][j]=2)
                    rotten.insert(temp);
            }
        }
    }
    int iterations = 0;
    int directions [][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    while(fresh.size()>0){
        unordered_set <string> infected;
        for(string item:rotten){
            int i = item[0] -'0';
            int j = item[1] -'0';
            for(auto dir:directions){
                int nextI = i + dir[0];
                int nextJ = j + dir[1];
                string temp = ""; 
                temp += nextI +'0';
                temp += nextJ +'0';
                if(fresh.find(temp)!=fresh.end()){
                    infected.insert(temp);
                    fresh.erase(temp);
                }
            }
        }
        if(infected.size()==0)
            return -1;
        
        rotten = infected;
        iterations ++;
    }   
    
    return iterations;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int r,c;
	    cin>>r>>c;
	    int orangecount = 0;
	    vector<vector<int>> A (r,vector<int> (c,-1));
	    for(int i=0; i<r; i++){
	        for(int j=0; j<c; j++){
	            cin>>A[i][j];
	        }
	    }
	    cout<<solution(A)<<endl;         
	}
	return 0;
}
