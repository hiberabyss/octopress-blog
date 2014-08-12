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

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int k = 1;
        int bx = 0;
        int by = 0;
        int ex = n;
        int ey = n;

        while( bx < ex && by < ey ) {
            for (int j = by; j < ey; ++j ) res[bx][j] = k++;
            bx++;
            for (int i = bx; i < ex; ++i ) res[i][ey-1] = k++;
            ey--;
            if ( bx == ex ) break;
            for (int j = ey-1; j >= by; --j ) res[ex-1][j] = k++;
            ex--;
            if ( by == ey ) break;
            for (int i = ex-1; i >= bx; --i ) res[i][by] = k++;
            by++;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        auto res = sol.generateMatrix(3);
        for (auto ct : res) {
            for (auto i : ct){
                cout << i << " ";
            }
            cout <<endl;
        }
    }
    return 0;
}

