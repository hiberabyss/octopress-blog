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
    int uniquePaths(int m, int n) {
        return uniquePaths2(m, n);
    }

    int uniquePaths2(int m, int n) {
        vector<int> dp(n);
        for (int i = 0; i < m; ++i ) {
            for (int j = 0; j < n; ++j ) {
                if ( !i || !j ) dp[j] = 1;
                else dp[j] += dp[j-1];
            }
        }
        return dp[n-1];
    }

    int uniquePaths1(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; ++i ) {
            for (int j = 0; j < n; ++j ) {
                if ( !i || !j ) dp[i][j] = 1;
                else dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    return 0;
}

