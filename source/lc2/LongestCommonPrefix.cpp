#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string res;
        if ( strs.empty() ) return res;
        int M = strs.size();
        int N = strs[0].size();
        for (int j = 0; j < N; ++j ) {
            for (int i = 1; i < M; ++i ) {
                if ( strs[i][j] != strs[0][j] ) return res;
            }
            res += strs[0][j];
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    return 0;
}

