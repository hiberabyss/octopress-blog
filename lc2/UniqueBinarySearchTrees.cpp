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
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i ) {
            for (int j = 0; j < i; ++j ) {
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
        return dp[n];
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        cout << sol.numTrees(3) <<endl;
    }
    return 0;
}

