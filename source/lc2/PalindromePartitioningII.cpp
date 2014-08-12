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
    int minCut(string s) {
        return minCut2(s);
    }

    int minCut2(string s) {
        if ( s.empty() ) return 0;
        int N = s.size();
        vector<vector<bool>> dp1(N, vector<bool>(N, false));
        vector<int> dp2(N+1, N);
        dp2[0] = -1;
        for (int j = 0; j < N; ++j ) {
            for (int i = j; i >= 0; --i ) {
                if ( s[i]==s[j] && (j-i<2 || dp1[i+1][j-1]) ) {
                    dp1[i][j] = true;
                    dp2[j+1] = min(dp2[j+1], dp2[i]+1);
                }
            }
        }
        return dp2[N];
    }

    int minCut1(string s) {
        int N = s.size();
        vector<vector<bool>> isPalind(N, vector<bool>(N, false));
        for (int j = 0; j < N; ++j ) {
            for (int i = j; i >= 0; --i ) {
                if ( s[i] == s[j] && ( j-i<2 || isPalind[i+1][j-1] ) ) 
                    isPalind[i][j] = true;
            }
        }

        vector<int> mc(N+1, N);
        mc[0] = -1;
        for (int j = 1; j <= N; ++j ) {
            for (int i = 0; i < j; ++i ) {
                if ( isPalind[i][j-1] ) {
                    mc[j] = min(mc[i]+1, mc[j]);
                    // cout << mc[j] <<endl;
                }
            }
        }
        return mc[N];
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        string s = "aab";
        cout << sol.minCut(s) <<endl;
    }
    return 0;
}

