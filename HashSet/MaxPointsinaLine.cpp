/*Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Example 1:

Input: [[1,1],[2,2],[3,3]]
Output: 3
Explanation:
^
|
|        o
|     o
|  o  
+------------->
0  1  2  3  4
Example 2:

Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
Explanation:
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6
*/

class Solution {
public:
    int maxPoints(vector<vector<int>>& A) {
        int n = A.size();
        int ans = 0;
        
        for(int i = 0; i< n; i++){
            //use long double because closer points will have only
            //slight slope difference
            unordered_map <long double,int> M;
            int duplicates = 1;
            int vertical = 0;
            for(int j = i+1; j < n; j++){
                //x coordinates same
                if(A[i][0]==A[j][0]){
                    //if y also same
                    if(A[i][1] == A[j][1]){
                        duplicates++;
                    }else{
                        vertical++;
                    }
                }else{
                    int x = A[j][0] - A[i][0];
                    int y = A[j][1] - A[i][1];
                    long double slope = (long double) y/x;
                    M[slope] ++;
                }
            }
            int sol = 0;
            for(auto item:M){
                //duplicates also have same slope
                // and in intial duplicate value = 1, we are 
                //counting the current point
                if(item.second + duplicates > sol){
                    sol = item.second + duplicates;
                }
            }
            // if there are more vertical points
            if(vertical + duplicates > sol){
                sol = vertical + duplicates;
            }
            if(sol>ans){
                ans = sol;
            }
        }
        return ans;
    }
};
