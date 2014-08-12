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
    bool wordBreak(string s, unordered_set<string> &dict) {
        return wordBreak1(s, dict);
    }

    bool wordBreak1(string s, unordered_set<string> &dict) {
        if ( s.empty() ) return dict.count(s);
        int N = s.size();
        vector<bool> dp(N+1, false);
        dp[0] = true;
        for (int j = 1; j <= N; ++j ) {
            for (int i = 0; i < j; ++i ) {
                if ( dict.count(s.substr(i,j-i)) && dp[i] ) {
                    dp[j] = true;
                    break;
                }
            }
        }
        return dp[N];
    }

    bool wordBreak2(string s, unordered_set<string> &dict) {
        if ( s.empty() ) return dict.count(s);
        int N = s.size();
        vector<vector<bool>> canBreak(N, vector<bool>(N,false));
        for (int j = 0; j < N; ++j ) {
            for (int i = j; i >= 0; --i ) {
                if ( dict.count(s.substr(i,j-i+1)) ) {
                    canBreak[i][j] = true;
                    continue;
                }

                for (int k = i; k < j; ++k ) {
                    canBreak[i][j] = canBreak[i][k] && canBreak[k+1][j];
                    if ( canBreak[i][j] ) break;
                }
            }
        }

        return canBreak[0][N-1];
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        string s = "leetcode";
        unordered_set<string> dict{ "leet", "code" };
        cout << boolalpha << sol.wordBreak(s, dict) <<endl;
    }
    return 0;
}

