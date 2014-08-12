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
    bool isScramble(string s1, string s2) {
        return isScramble2(s1, s2);
        return isScramble1(s1, s2);
    }

    bool isScramble2(string s1, string s2) {
        int N = s1.size();
        vector<vector<vector<bool>>> dp(N+1, vector<vector<bool>>(N, vector<bool>(N,false)));
        for (int l = 1; l <= N; ++l ) {
            for (int i = 0; i+l <= N; ++i ) {
                for (int j = 0; j+l <= N; ++j ) {
                    if ( l == 1 ) dp[l][i][j] = (s1[i] == s2[j]);
                    else {
                        for (int k = 1; k < l; ++k ) {
                            dp[l][i][j] = ( dp[k][i][j] && dp[l-k][i+k][j+k] ) ||
                                          ( dp[k][i][j+l-k] && dp[l-k][i+k][j] );
                            if ( dp[l][i][j] ) break;
                        }
                    }
                }
            }
        }
        return dp[N][0][0];
    }

    bool isScramble1(string s1, string s2) {
        if ( s1 == s2 ) return true;

        int N = s1.size();
        for (int i = 1; i < N; ++i ) {
            if ( (isScramble1(s1.substr(0,i), s2.substr(0,i)) && isScramble1(s1.substr(i), s2.substr(i))) ||
                 (isScramble1(s1.substr(0,i), s2.substr(N-i)) && isScramble1(s1.substr(i), s2.substr(0, N-i))) )
                return true;
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        string s1 = "rgtae";
        string s2 = "great";
        cout << boolalpha << sol.isScramble(s1, s2) <<endl;
    }
    return 0;
}

