//Kruskal's algorithm
/*

There are A islands and there are M bridges connecting them. Each bridge has some cost attached to it.

We need to find bridges with minimal cost such that all islands are connected.

It is guaranteed that input data will contain at least one possible scenario in which all islands are connected with each other.

Input Format:

The first argument contains an integer, A, representing the number of islands.
The second argument contains an 2-d integer matrix, B, of size M x 3:
    => Island B[i][0] and B[i][1] are connected using a bridge of cost B[i][2].
Output Format:

Return an integer representing the minimal cost required.
Constraints:

1 <= A, M <= 6e4
1 <= B[i][0], B[i][1] <= A
1 <= B[i][2] <= 1e3
Examples:

Input 1:
    A = 4
    B = [   [1, 2, 1]
            [2, 3, 4]
            [1, 4, 3]
            [4, 3, 2]
            [1, 3, 10]  ]

Output 1:
    6

Explanation 1:
    We can choose bridges (1, 2, 1), (1, 4, 3) and (4, 3, 2), where the total cost incurred will be (1 + 3 + 2) = 6.

Input 2:
    A = 4
    B = [   [1, 2, 1]
            [2, 3, 2]
            [3, 4, 4]
            [1, 4, 3]   ]

Output 2:
    6

Explanation 2:
    We can choose bridges (1, 2, 1), (2, 3, 2) and (1, 4, 3), where the total cost incurred will be (1 + 2 + 3) = 6.
    */
    
    
    int find(vector<int> &parent, int i) {
    if(parent[i]==-1)
        return i;
    return find(parent, parent[i]);
}
void Union(vector<int> &parent, int x, int y) {
    int xp = find(parent, x);
    int yp = find(parent, y);
    parent[xp] = yp;
}
bool comp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}
int Solution::solve(int A, vector<vector<int> > &B) {
    //sort based on cost
    sort(B.begin(), B.end(), comp);
    
    vector<int> parent(A,-1);
    int ans = 0;
    
    for(int i=0;i<B.size();i++) {
        int up = find(parent, B[i][0]-1);
        int vp = find(parent, B[i][1]-1);
        //If both parents are not same, which means they are not connected
        //so connect them;
        if(up!=vp) {
            Union(parent, up, vp);
            ans += B[i][2];
        }
    }
    return ans;
}
