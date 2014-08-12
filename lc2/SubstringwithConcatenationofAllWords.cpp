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

// ToReview: There is a better solution, slide window

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        int M = S.size();
        vector<int> res;
        if ( L.empty() ) return res;
        int K = L[0].size();
        int N = L.size();

        unordered_map<string,int> map;
        for (auto s : L) map[s]++;
        for (int i = 0; i + K*N <= M; ++i ) {
            unordered_map<string,int> visit;
            int j;
            for (j = 0; j < N; ++j ) {
                auto str = S.substr(i+j*K, K);
                visit[str]++;
                if ( !map.count(str) || visit[str] > map[str] ) break;
            }
            if ( j==N ) res.push_back(i);
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
         string S = "barfoothefoobarman";
         vector<string> L = { {"foo"}, {"bar"} };
         auto res = sol.findSubstring(S, L);
         for (auto i : res) cout << i << " ";
         cout <<endl;
    }

    {
         string S = "aaa";
         vector<string> L = {"a", "b"};
         auto res = sol.findSubstring(S, L);
         for (auto i : res) cout << i << " ";
         cout <<endl;
    }
    return 0;
}

