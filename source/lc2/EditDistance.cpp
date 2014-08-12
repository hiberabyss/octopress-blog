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
    int minDistance(string word1, string word2) {
        // return minDistance1(word1, word2);
        return minDistance2(word1, word2);
    }

    int minDistance2(string word1, string word2) {
        int M = word1.size();
        int N = word2.size();
        vector<vector<int>> dp(2,vector<int>(N+1));
        int pre = -1, cur = 0;
        for (int j = 1; j <= N; ++j ) dp[cur][j] = j;
        for (int i = 1; i <= M; ++i ) {
            pre = cur;
            cur = !cur;
            dp[cur][0] = i;
            for (int j = 1; j <= N; ++j ) {
                if ( word1[i-1] == word2[j-1] ) dp[cur][j] = dp[pre][j-1];
                else {
                    auto tmp = dp[pre][j-1];
                    tmp = min(tmp, dp[pre][j]);
                    tmp = min(tmp, dp[cur][j-1]);
                    dp[cur][j] = tmp + 1;
                }
            }
        }
        return dp[cur][N];
    }

    int minDistance1(string word1, string word2) {
        int M = word1.size();
        int N = word2.size();
        vector<vector<int>> dp(M+1, vector<int>(N+1));
        for (int j = 1; j <= N; ++j ) dp[0][j] = j;
        for (int i = 1; i <= M; ++i ) dp[i][0] = i;
        for (int i = 1; i <= M; ++i ) {
            for (int j = 1; j <= N; ++j ) {
                if ( word1[i-1] == word2[j-1] ) dp[i][j] = dp[i-1][j-1];
                else {
                    int tmp = dp[i-1][j-1];
                    tmp = min(tmp, dp[i-1][j]);
                    tmp = min(tmp, dp[i][j-1]);
                    dp[i][j] = tmp+1;
                }
            }
        }
        return dp[M][N];
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    return 0;
}

