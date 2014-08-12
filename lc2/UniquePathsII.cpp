#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int M = obstacleGrid.size();
        int N = obstacleGrid[0].size();
        vector<int> dp(N);
        if ( obstacleGrid[0][0] ) return 0;
        dp[0] = 1;
        for (int i = 0; i < M; ++i ) {
            for (int j = 0; j < N; ++j ) {
                if ( obstacleGrid[i][j] ) dp[j] = 0;
                else if ( !i && j ) dp[j] = dp[j-1];
                else if ( i && j ) dp[j] += dp[j-1];
            }
        }
        return dp[N-1];
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    return 0;
}

