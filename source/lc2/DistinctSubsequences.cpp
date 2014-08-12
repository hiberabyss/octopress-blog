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

// ToReview

class Solution {
public:
    int numDistinct(string S, string T) {
        return numDistinct3(S,T);
        return numDistinct2(S,T);
        return numDistinct1(S,T);
    }

    int numDistinct3(string S, string T) {
        int M = T.size();
        int N = S.size();
        vector<vector<int>> dp(M+1, vector<int>(N+1));
        fill( dp[0].begin(), dp[0].end(), 1 );
        for (int i = 1; i <= M; ++i ) {
            for (int j = i; j <= N; ++j ) {
                dp[i][j] += dp[i][j-1];
                if ( T[i-1] == S[j-1] ) dp[i][j] += dp[i-1][j-1];
            }
        }
        return dp[M][N];
    }

    int numDistinct2(string S, string T) {
        int M = T.size();
        int N = S.size();
        vector<vector<int>> dp(M+1, vector<int>(N+1));
        fill( dp[M].begin(), dp[M].end(), 1 );
        for (int i = M-1; i >= 0; --i ) {
            for (int j = N-(M-i); j >= 0; --j ) {
                dp[i][j] += dp[i][j+1];
                if ( T[i] == S[j] ) {
                    dp[i][j] += dp[i+1][j+1];
                } 
            }
        }
        return dp[0][0];
    }

    int numDistinct1(string S, string T) {
        if ( T.empty() ) return 1;
        int cnt = 0;
        for (int i = 0; S[i]; ++i ) {
            if ( S[i] == T[0] ) {
                cnt += numDistinct1(S.substr(i+1), T.substr(1));
            }
        }
        return cnt;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        string S = "rabbbit";
        string T = "rabbit";
        cout << sol.numDistinct(S,T) <<endl;
    }
    return 0;
}

