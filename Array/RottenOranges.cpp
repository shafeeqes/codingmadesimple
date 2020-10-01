/*
Given a matrix of dimension r*c where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

So, we have to determine what is the minimum time required to rot all oranges. 
A rotten orange at index [i,j] can rot other fresh orange at indexes 
[i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. If 
it is impossible to rot every orange then simply return -1.

Input:
The first line of input contains an integer T denoting the number of test cases. 
Each test case contains two integers r and c, where r is the number of rows and c 
is the number of columns in the array a[]. Next line contains space separated r*c 
elements each in the array a[].

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



//A better solution is presented in the Hashser folder


void rot(vector<vector<int>> &A,int i,int j,int &count,bool &changed){
    int r = A.size(), c = A[0].size();
    if(i<0 or i>=r or j<0 or j>=c or A[i][j] !=1)
        return;
    
    A[i][j] = 2;
    count++;
    changed = true;
}
int solution(vector<vector<int>> &A,int orangecount){
    int r = A.size(), c = A[0].size();
    int loopcount = 0;
    vector<vector<int>> temp;
    int x[] = {-1,1,0,0};
    int y[] = {0,0,-1,1};
    while(true){
        bool changed = false;
        int rottencount = 0;
        loopcount ++;
        //In the present iteration we only rot using the initial present rotten
        // oranges, not the oranges which got infected in this iteration
        temp = A;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(temp[i][j] == 2){
                    rottencount ++;
                    for(int k=0;k<4;k++)
                        rot(A,i+x[k],j+y[k],rottencount,changed);
                }
            }
        }
        if(rottencount == orangecount)
            return loopcount;
        if(!changed)
            return -1;
    }
    return -1;
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
	            if(A[i][j]!=0)
	                orangecount++;
	        }
	    }
	    cout<<solution(A,orangecount)<<endl;         
	}
	return 0;
}
