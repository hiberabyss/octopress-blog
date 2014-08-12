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
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        return wordBreak1(s, dict);
    }

    vector<string> wordBreak1(string s, unordered_set<string> &dict) {
        int N = s.size();
        vector<int> dp(N+1,false);
        dp[N] = true;
        for (int i = N-1; i >= 0; --i ) {
            for (int l = 1; l <= N-i; ++l ) {
                if ( dict.count(s.substr(i,l)) && dp[i+l] ) {
                    dp[i] = true;
                    break;
                }
            }
        }

        vector<string> res;
        string sol;
        function<void(int)> getBreak = [&] (int b) {
            if ( b == N ) {
                sol.pop_back();
                res.push_back(sol);
                return;
            }

            for (int l = 1; l <= N-b; ++l ) {
                auto sub = s.substr(b, l);
                if ( dict.count(sub) && dp[b+l] ) {
                    auto tmp = sol;
                    sol += sub + ' ';
                    getBreak(b+l);
                    sol = tmp;
                }
            }
        };

        getBreak(0);
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        string s = "catsanddog";
        unordered_set<string> dict{ "cat", "cats", "and", "sand", "dog" };
        auto res = sol.wordBreak(s, dict);
        for (auto s : res) cout << s <<endl;
        cout <<endl;
    }
    return 0;
}

