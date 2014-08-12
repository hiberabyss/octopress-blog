#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // return combine1(n, k);
        return combine2(n, k);
    }

    vector<vector<int> > combine2(int n, int k) {
        vector<vector<int>> res(1);
        while( k-- ) {
            int M = res.size();
            for (int i = 0; i < M; ++i ) {
                int begin = !res[i].empty() ? res[i].back()+1 : 1;
                for (int j = begin+1; j+k <= n; ++j ) {
                    auto copy = res[i];
                    copy.push_back(j);
                    res.push_back(copy);
                }
                res[i].push_back(begin);
            }
        }
        return res;
    }

    vector<vector<int> > combine1(int n, int k) {
        vector<vector<int>> res;
        vector<int> cb;
        if ( k>n ) return res;

        function<void(int,int)> getCombine = [&] (int ind, int len) {
            if ( !len ) {
                res.push_back(cb);
                return;
            }

            for (int i = ind; i+len <= n; ++i ) {
                cb.push_back(i+1);
                getCombine(i+1, len-1);
                cb.pop_back();
            }
        };

        getCombine(0, k);
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        auto res = sol.combine(4, 2);
        for (auto ct : res) {
            for (auto i : ct){
                cout << i << " ";
            }
            cout <<endl;
        }
    }
    return 0;
}

