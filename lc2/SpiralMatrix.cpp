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
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        if ( matrix.empty() ) return res;
        int M = matrix.size();
        int N = matrix[0].size();
        int bx = 0;
        int by = 0;
        int ex = M;
        int ey = N;
        while( bx < ex && by < ey ) {
            for (int j = by;j < ey; ++j ) res.push_back(matrix[bx][j]);
            bx++;
            for (int i = bx; i < ex; ++i ) res.push_back(matrix[i][ey-1]);
            ey--;
            if ( bx == ex ) break;
            for (int j = ey-1; j >= by; --j ) res.push_back(matrix[ex-1][j]);
            ex--;
            if ( by == ey ) break;
            for (int i = ex-1; i >= bx; --i ) res.push_back(matrix[i][by]);
            by++;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<vector<int>> matrix{
            {1,2,3},
            {4,5,6},
            {7,8,9},
        };
        auto res = sol.spiralOrder(matrix);
        for (auto i : res) cout << i << " ";
        cout <<endl;
    }
    {
        vector<vector<int>> matrix{
            {2,3},
        };
        auto res = sol.spiralOrder(matrix);
        for (auto i : res) cout << i << " ";
        cout <<endl;
    }
    {
        vector<vector<int>> matrix{
            {1},
            {2},
            {3},
        };
        auto res = sol.spiralOrder(matrix);
        for (auto i : res) cout << i << " ";
        cout <<endl;
    }
    return 0;
}
