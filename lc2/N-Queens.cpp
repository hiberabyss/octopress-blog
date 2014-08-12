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
    vector<vector<string> > solveNQueens(int n) {
        return solveNQueens1(n);
    }

    vector<vector<string> > solveNQueens1(int n) {
        vector<vector<string>> res;
        vector<string> sol(n, string(n, '.'));
        vector<int> rowInd(n, -1);

        function<void(int r)> getNQueen = [&] (int r) {
            if ( r == n ) res.push_back(sol);

            for (int j = 0; j < n; ++j ) {
                bool canPlace = true;
                for (int i = 0; i < r; ++i ) {
                    if ( j == rowInd[i] || r-i == abs(j-rowInd[i]) )
                        canPlace = false;
                }

                if ( canPlace ) {
                    sol[r][j] = 'Q';
                    rowInd[r] = j;
                    getNQueen(r+1);
                    sol[r][j] = '.';
                }
            }
        };

        getNQueen(0);
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        auto res = sol.solveNQueens(4);
        for (auto ct : res) {
            for (auto i : ct){
                cout << i <<endl;
            }
            cout <<endl;
        }
    }
    return 0;
}

