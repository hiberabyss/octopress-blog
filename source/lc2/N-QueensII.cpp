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
    int totalNQueens(int n) {
        return totalNQueens1(n);
    }

    int totalNQueens1(int n) {
        vector<int> rowInd(n, -1);
        int cnt = 0;
        function<void(int)> getQueenCount = [&] (int r) {
            if ( r == n ) cnt++;
            for (int j = 0; j < n; ++j ) {
                bool canPlace = true;
                for (int i = 0; i < r; ++i ) {
                    if ( j == rowInd[i] || r-i == abs(j-rowInd[i]) )
                        canPlace = false;
                }

                if ( canPlace ) {
                    rowInd[r] = j;
                    getQueenCount(r+1);
                }
            }
        };
        getQueenCount(0);
        return cnt;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        cout << sol.totalNQueens(4) <<endl;
        cout << sol.totalNQueens(8) <<endl;
    }
    return 0;
}

