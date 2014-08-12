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
#include <climits>

using namespace std;

// ToReview

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        return minPathSum2(grid);
    }

    int minPathSum2(vector<vector<int> > &grid) {
        int M = grid.size();
        int N = grid[0].size();
        vector<vector<int>> dp(M, vector<int>(N));
        dp[M-1][N-1] = grid[M-1][N-1];
        for (int j = N-2; j >= 0; --j ) dp[M-1][j] = grid[M-1][j] + dp[M-1][j+1];
        for (int i = M-2; i >= 0; --i ) dp[i][N-1] = grid[i][N-1] + dp[i+1][N-1];
        for (int i = M-2; i >= 0; --i ) {
            for (int j = N-2; j >= 0; --j ) {
                dp[i][j] = min(dp[i+1][j], dp[i][j+1]);
                dp[i][j] += grid[i][j];
            }
        }
        return dp[0][0];
    }

    int minPathSum1(vector<vector<int> > &grid) {
        if ( grid.empty() ) return 0;
        int M = grid.size();
        int N = grid[0].size();

        function<int(int,int)> getMinSum = [&] (int x, int y) {
            if ( x == M-1 || y == N-1 ) return grid[x][y];
            int res = INT_MAX;
            if ( x<M-1 ) res = min(res, getMinSum(x+1,y));
            if ( y<N-1 ) res = min(res, getMinSum(x,y+1));
            res += grid[x][y];
            return res;
        };

        return getMinSum(0,0);
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<vector<int>> grid{
            {1,2},
            {1,1},
        };

        cout << sol.minPathSum(grid) <<endl;
    }
    return 0;
}

