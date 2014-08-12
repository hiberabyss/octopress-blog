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
    void solveSudoku(vector<vector<char> > &board) {
        solveSudoku3(board);
        // solveSudoku2(board);
        // solveSudoku1(board);
    }

    void solveSudoku3(vector<vector<char> > &board) {
        int N = board.size();
        int K = sqrt(N);
        auto getPoss = [&](int x, int y) {
            vector<bool> visit(N);
            for (int k = 0; k < N; ++k ) {
                if ( board[x][k] != '.' ) visit[board[x][k] - '1'] = true;
                if ( board[k][y] != '.' ) visit[board[k][y] - '1'] = true;
                int xx = x/K*K + k/K;
                int yy = y/K*K + k%K;
                if ( board[xx][yy] != '.' ) visit[board[xx][yy] - '1'] = true;
            }

            vector<char> res;
            for (int i = 0; i < N; ++i ) {
                if ( !visit[i] ) res.push_back(i+'1');
            }
            return res;
        };

        function<bool(int)> solve = [&] (int ind) {
            for (int k = ind; k < N*N; ++k ) {
                auto &ch = board[k/N][k%N];
                if ( ch == '.' ) {
                    auto res = getPoss(k/N, k%N);
                    for (auto c : res) {
                        ch = c;
                        if ( solve(ind+1) ) return true;
                        ch = '.';
                    }
                    return false;
                }
            }
            return true;
        };

        solve(0);
    }

    // fastest
    void solveSudoku2(vector<vector<char> > &board) {
        int N = board.size();
        int K = sqrt(N);
        vector<vector<vector<bool>>> mark(3, vector<vector<bool>>(N, vector<bool>(N, false)));
        auto setMark = [&](int x, int y, bool val) {
            int i = board[x][y] - '1';
            mark[0][x][i] = val;
            mark[1][y][i] = val;
            mark[2][x/K * K + y/K][i] = val;
        };

        auto isPoss = [&] (int x, int y, int i) {
                return !mark[0][x][i] && !mark[1][y][i] &&
                       !mark[2][x/K*K + y/K][i];
        };

        for (int i = 0; i < N; ++i ) {
            for (int j = 0; j < N; ++j ) {
                if ( board[i][j] != '.' ) setMark(i,j,true);
            }
        }

        // be cautious
        function<bool(int)> solve = [&] (int ind) {
            for (int d = ind; d < N*N; ++d ) {
                int i = d/N;
                int j = d%N;

                if ( board[i][j] == '.' ) {
                    for (int k = 0; k < N; ++k ) {
                        if ( !isPoss(i, j, k) ) continue;
                        board[i][j] = k + '1';
                        setMark(i,j,true);
                        if ( solve(d+1) ) return true;
                        setMark(i,j,false);
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
            return true;
        };

        solve(0);
    }

    void solveSudoku1(vector<vector<char> > &board) {
        int N = board.size();
        auto isValid = [&]() {
            for (int i = 0; i < N; ++i ) {
                vector<bool> visit(N, false);
                auto check = [&](int i, int j) {
                    char ch = board[i][j];
                    if ( board[i][j] == '.' ) return true;
                    if ( visit[ch-'1'] ) return false;
                    visit[ch-'1'] = true;
                    return true;
                };

                for (int k = 0; k < N; ++k ) {
                    if ( !check(i,k) ) return false;
                }

                fill( visit.begin(), visit.end(), false );
                for (int k = 0; k < N; ++k ) {
                    if ( !check(k,i) ) return false;
                }

                fill( visit.begin(), visit.end(), false );
                int d = sqrt(N);
                for (int k = 0; k < N; ++k ) {
                    int x = (i/d)*d + k/d;
                    int y = (i%d)*d + k%d; 
                    if ( !check(x,y) ) return false;
                }
            }
            return true;
        };

        function<bool(int)> solveRec = [&] (int ind) {
            if ( !isValid() ) return false;
            while( ind<N*N && board[ind/N][ind%N] != '.' ) ind++;
            if ( ind == N*N ) return true;

            int i = ind/N;
            int j = ind%N;
            if ( board[i][j] == '.' ) {
                for (int k = 0; k < N; ++k ) {
                    board[i][j] = k + '1';
                    if ( solveRec(ind+1) ) return true;
                    board[i][j] = '.';
                }
            }
            return false;
        };

        solveRec(0);
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<vector<char>> board{
            {'.','.','9','7','4','8','.','.','.',},
            {'7','.','.','.','.','.','.','.','.',},
            {'.','2','.','1','.','9','.','.','.',},
            {'.','.','7','.','.','.','2','4','.',},
            {'.','6','4','.','1','.','5','9','.',},
            {'.','9','8','.','.','.','3','.','.',},
            {'.','.','.','8','.','3','.','2','.',},
            {'.','.','.','.','.','.','.','.','6',},
            {'.','.','.','2','7','5','9','.','.',}
        };
        sol.solveSudoku(board);
        for (auto ct : board) {
            for (auto i : ct){
                cout << i << " "; 
            }
            cout <<endl;
        }
        cout <<endl;
    }

    {

        vector<vector<char> > board = {
            { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
            { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
            { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
            { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
            { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
            { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
            { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
            { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
            { '.', '.', '.', '.', '8', '.', '.', '7', '9' },
        };
        sol.solveSudoku(board);
        for (auto ct : board) {
            for (auto i : ct){
                cout << i << " "; 
            }
            cout <<endl;
        }
        cout <<endl;
    }
    return 0;
}

