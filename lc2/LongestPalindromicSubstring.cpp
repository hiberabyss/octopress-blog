#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

// ToReview

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // return longestPalindrome1(s);
        return longestPalindrome2(s);
    }

    string longestPalindrome2(string &s) {
        int maxi = 0, maxl = 0;
        int N = s.size();
        auto expand = [&] (int k1, int k2) {
            while( k1>=0 && k2<N && s[k1] == s[k2] ) k1--,k2++;
            k1++;
            k2--;
            int l = k2-k1+1;
            if ( l>maxl ) maxl=l,maxi=k1;
        };

        for (int i = 0; i < N; ++i ) {
            expand(i,i);
            expand(i,i+1);
        }

        return s.substr(maxi, maxl);
    }

    string longestPalindrome1(string s) {
        int N = s.size();
        vector<vector<int>> dp(N, vector<int>(N,false));
        int maxi = 0, maxl = 1;
        for (int j = 0; j < N; ++j ) {
            for (int i = j; i >= 0; --i ) {
                int l = j-i+1;
                if ( s[i] == s[j] && (l<=2 || dp[i+1][j-1]) ) {
                    if ( l>maxl ) maxl = l, maxi = i;
                    dp[i][j] = true;
                }
            }
        }
        return s.substr(maxi, maxl);
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        cout << sol.longestPalindrome("abccbd") << endl;
    }

    {
        cout << sol.longestPalindrome("bbbbb") << endl;
    }

    {
        cout << sol.longestPalindrome("ba");
    }
    return 0;
}

