/*
Given a 3 x A board, find the number of ways to color it using at most 4 colors such that no 2 adjacent boxes have same color.

Diagonal neighbors are not treated as adjacent boxes.

Return the ways modulo 109 + 7 as the answer grows quickly.

Input Format:

The first and the only argument contains an integer, A.
Output Format:

Return an integer representing the number of ways to color the board.
Constraints:

1 <= A < 100000
Examples:

Input 1:
    A = 1

Output 1:
    36

Input 2:
    A = 2

Output 2:
    588
    */
    
  int Solution::solve(int A) {
    long int color3 = 24;
    long int color2 = 12;
    long int temp = 0;
    for (int i = 2; i <= A; i++) {
        temp = color3;
        color3 = (11 * color3 + 10 * color2) % 1000000007;
        color2 = (5 * temp + 7 * color2) % 1000000007;
    }
    return (color3 + color2) % 1000000007;
}


//normal solution


#define mod 1000000007
#define ll long long

struct triplet{
	int x, y, z;
};

vector<triplet> trip;  //vector of 36 triplets

void fillTriplets(){
	//trip vector contain the triplets of color that can be used to paint a certain column
       trip.clear();
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			for(int k=0; k<4; k++){
				if(i!=j && j!=k) trip.push_back({i,j,k});
			}
		}
	}
}

int dp[4][4][4][100005];


bool isCompatible(const triplet& t1,  const triplet& t2){
	//check if triplets t1 and t2 are compatible
	if(t1.x==t2.x || t1.y==t2.y || t1.z==t2.z ){
		return 0;
	}
	return 1;
}

int Solution::solve(int n){
        fillTriplets();
	if(n<=0) return -1;
	
       //Bottom-up dp
	for(int i=1; i<=n; i++){
		for(int j=0; j<36; j++){
			if(i==1) dp[trip[j].x][trip[j].y][trip[j].z][i] = 1;
			else{
				ll temp = 0;
				
				for(int k=0; k<36; k++){
					if(isCompatible(trip[j], trip[k])){
						temp += dp[trip[k].x][trip[k].y][trip[k].z][i-1];
						temp %= mod;
					}
				}
				dp[trip[j].x][trip[j].y][trip[j].z][i] = temp;
			}
		}
	}
	
	ll ans = 0;
	for(int i=0; i<trip.size(); i++){
		ans = (ans + dp[trip[i].x][trip[i].y][trip[i].z][n])%mod;
	}
         int res = ans;

	return ans;
}


/*
You have a grid of size n x 3 and you want to paint each cell of the grid with exactly one of the three 
colours: Red, Yellow or Green while making sure that no two adjacent cells have the same colour (i.e no two c
ells that share vertical or horizontal sides have the same colour).

You are given n the number of rows of the grid.

Return the number of ways you can paint this grid. As the answer may grow large, the answer must be computed modulo 10^9 + 7.

 

Example 1:

Input: n = 1
Output: 12
Explanation: There are 12 possible way to paint the grid as shown:

Example 2:

Input: n = 2
Output: 54
Example 3:

Input: n = 3
Output: 246
Example 4:

Input: n = 7
Output: 106494
Example 5:

Input: n = 5000
Output: 30228214
*/



class Solution {
public:
    
    // all different
    // For RGB
    // ---
    // BRG
    // GBR
    // ---
    // GRG
    // GBG
    
    // two same
    // For RBR
    // ---
    // BRG
    // GRB
    // ---
    // GRG
    // BRB
    // GBG
    // 
    // D_i+1 = 2 * D_i + 2 * S_i
    // S_i+1 = 2 * D_i + 3 * S_i
    
    int numOfWays(int n) {
        
        auto modulo = (int) pow(10, 9) + 7;
        
        long long d = 6;
        long long  s = 6;
        for(int i = 1; i < n; ++i) {
            
            long long d1 = 2 * d + 2 * s;
            long long s1 = 2 * d + 3 * s;
            
            d = (d1 % modulo);
            s = (s1 % modulo);
        }
        
        return (d + s) % modulo;
    }
};




class Solution {
public:
    
    struct triplet{
        int x;
        int y;
        int z;
        
        triplet(int x,int y, int z){
            this-> x = x;
            this-> y = y;
            this-> z = z;
        }
    };
    
    vector<triplet> triplets;
    
    void generateTriplets(){
        
        triplets.clear();
        
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    if( i!=j and j!=k)
                        triplets.push_back(triplet(i,j,k));
                }
            }
        }
    }
    
    bool isOkay(const triplet& a, const triplet& b){
        if(a.x != b.x and a.y != b.y and a.z != b.z)
            return true;
        return false;
    }
    
    int dp[3][3][3][5001];
    
    int numOfWays(int n) {
        if(n <= 0)
            return 1;
        
        generateTriplets();
        int M = pow(10,9) + 7;
        
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < triplets.size(); j++){
                if(i == 1){
                    dp[triplets[j].x][triplets[j].y][triplets[j].z][i] = 1;
                }
                else{
                    long long int temp = 0;
                    
                    for(int k = 0; k < triplets.size(); k++){
                        if(isOkay(triplets[j],triplets[k])){
                            temp += dp[triplets[k].x][triplets[k].y][triplets[k].z][i-1];
                            temp %= M;
                        }       
                    }
                    dp[triplets[j].x][triplets[j].y][triplets[j].z][i] = temp;
                }  
            }            
        }
        
        long long int ans = 0;
        for(int j = 0; j < triplets.size(); j++){
            ans = (ans + dp[triplets[j].x][triplets[j].y][triplets[j].z][n]) % M;
        }
        return ans;
    }
};








