/*

https://www.hackerrank.com/challenges/down-to-zero-ii/problem


Given an integer N, the task is to count the minimum steps required to reduce the value of N to 0 by performing the following two operations:

Consider integers A and B where N = A * B (A != 1 and B != 1), reduce N to max(A, B)
Decrease the value of N by 1
Examples :

Input: N = 3
Output: 3
Explanation:
Steps involved are 3 -> 2 -> 1 -> 0
Therefore, the minimum steps required is 3.
 
Input: N = 4
Output: 3
Explanation:
Steps involved are 4->2->1->0.
Therefore, the minimum steps required is 3
*/


#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the downToZero function below.
 */
int downToZero(int n) {
    
    int dp[n + 1] = {0};

    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        
        //set default solution to N - 1 + 1 step
        dp[i] = dp[i-1] + 1;

        for(int j = 2; j*j <= i; j++){
            if( i % j == 0){
                //choose the max number among a,b ie, j and i/j
                dp[i] = min(dp[i], 1 + dp[i/j]);
            }
        }
    }

    return dp[n];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = downToZero(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}



#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the downToZero function below.
 */
int downToZero(int n) {
    
if (n == 0) {
        return 0;
    }
    
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_map<int, int> moves;
    
    pq.push(n);
    moves.insert(make_pair(n, 0));
    
    int minMoves = 1e9;
    while (!pq.empty()) {
        int x = pq.top();
        int m = moves.find(x)->second;
        pq.pop();
        
        if (x > 0 && m + 1 < minMoves) {
            auto it = moves.insert(make_pair(x - 1, 1e9)).first;
            if (it->second > m + 1) {
                it->second = m + 1;
                pq.push(x - 1);
                if (x - 1 == 0) {
                    minMoves = it->second;
                }
            }
            for (int k = (int)floor(sqrt(x)); k > 1; k--) {
                if (x % k == 0) {
                    int factor = x / k;
                    auto it2 = moves.insert(make_pair(factor, 1e9)).first;
                    if (it2->second > m + 1) {
                        it2->second = m + 1;
                        pq.push(factor);
                    }
                }
            }
        }
    }
    
    return minMoves;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = downToZero(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
