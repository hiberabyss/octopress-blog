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
    bool isInterleave(string s1, string s2, string s3) {
        return isInterleave2(s1,s2,s3);
        return isInterleave1(s1,s2,s3);
    }

    bool isInterleave2(string s1, string s2, string s3) {
        int N1 = s1.size();
        int N2 = s2.size();
        int N3 = s3.size();
        if ( N3 != N1+N2 ) return false;
        vector<vector<bool>> dp(N1+1, vector<bool>(N2+1, false));
        dp[0][0] = true;
        for (int i = 0; i <= N1; ++i ) {
            for (int j = 0; j <= N2; ++j ) {
                if ( i>0 ) {
                    dp[i][j] = ( s1[i-1] == s3[i+j-1] && dp[i-1][j] );
                    if ( dp[i][j] ) continue;
                }

                if ( j > 0 ) {
                    dp[i][j] = ( s2[j-1] == s3[i+j-1] && dp[i][j-1] );
                }
            }
        }
        return dp[N1][N2];
    }

    bool isInterleave1(string s1, string s2, string s3) {
        int N1 = s1.size();
        int N2 = s2.size();
        int N3 = s3.size();
        if ( N3 != N1+N2 ) return false;
        int i = 0;
        int j = 0;
        int k = 0;
        while( k<N3 ) {
            if ( j == N2 ) {
                if ( s1[i] != s3[k] ) return false;
                else i++;
            } else if ( i == N1 ) {
                 if ( s2[j] != s3[k] ) return false;
                 else j++;
            } else {
                if ( s1[i] == s2[j] ) {
                    if ( s3[k] != s1[i] ) return false;
                    return isInterleave1(s1.substr(i), s2.substr(j+1), s3.substr(k+1)) ||
                        isInterleave1(s1.substr(i+1), s2.substr(j), s3.substr(k+1));
                }

                if ( s1[i] == s3[k] ) i++;
                else if ( s2[j] == s3[k] ) j++;
                else return false;
            }
            k++;
        }

        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
         string s1 = "aabcc";
         string s2 = "dbbca";
         string s3 = "aadbbcbcac";
         cout << boolalpha << sol.isInterleave(s1,s2,s3) <<endl;
    }

    {
         string s1 = "aabcc";
         string s2 = "dbbca";
         string s3 = "aadbbbaccc";
         cout << boolalpha << sol.isInterleave(s1,s2,s3) <<endl;
    }
    return 0;
}

