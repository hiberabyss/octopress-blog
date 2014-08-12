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
    bool isValidSudoku(vector<vector<char> > &board) {
        int N = board.size();
        auto isRowValid = [&] (int ind) {
            vector<bool> visit(N, false);
            for (int j = 0; j < N; ++j ) {
                char ch = board[ind][j];
                if ( ch == '.' ) continue;
                if ( visit[ch-'1'] ) return false;
                visit[ch-'1'] = true;
            }
            return true;
        };

        auto isColValid = [&] (int ind) {
            vector<bool> visit(N, false);
            for (int i = 0; i < N; ++i ) {
                char ch = board[i][ind];
                if ( ch == '.' ) continue;
                if ( visit[ch-'1'] ) return false;
                visit[ch-'1'] = true;
            }
            return true;
        };

        auto isSquareValid = [&] (int ind) {
            int k = sqrt(N);
            int x = (ind/k) * k;
            int y = (ind%k) * k;
            vector<bool> visit(N, false);
            for (int i = 0; i < N; ++i ) {
                char ch = board[x + i/k][y + i%k];
                if ( ch == '.' ) continue;
                if ( visit[ch-'1'] ) return false;
                visit[ch-'1'] = true;
            }
            return true;
        };

        for (int i = 0; i < N; ++i ) {
            if ( !isRowValid(i) ) return false;
            if ( !isColValid(i) ) return false;
            if ( !isSquareValid(i) ) return false;
        }

        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        /* vector<vector<char>> board{
             "..4...63.",".........","5......9.","...56....","4.3.....1","...7.....","...5.....",".........","........."
        }; */

        cout << sqrt(9) <<endl;
    }
    return 0;
}

