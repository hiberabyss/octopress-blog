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
    void solve(vector<vector<char>> &board) {
        if ( board.empty() ) return;
        const char rc = 'R';
        int M = board.size();
        int N = board[0].size();
        auto repChar = [&] (int x, int y, char ch) {
            queue<pair<int,int>> que;
            que.push({x,y});
            board[x][y] = ch;

            while( !que.empty() ) {
                int x = que.front().first;
                int y = que.front().second;
                que.pop();
                for (int i = -2; i <= 2; ++i ) {
                    int nx = x + i/2;
                    int ny = y + i%2;
                    if ( nx>=0 && nx<M &&
                            ny>=0 && ny<N && board[nx][ny] == 'O' ) {
                        que.push({nx,ny});
                        board[nx][ny] = ch;
                    }
                }
            }
        };
        
        for (int j = 0; j < N; ++j ) {
            if ( board[0][j] == 'O' ) repChar(0, j, rc);
            if ( board[M-1][j] == 'O' ) repChar(M-1, j, rc);
        }

        for (int i = 0; i < M; ++i ) {
            if ( board[i][0] == 'O' ) repChar(i, 0, rc);
            if ( board[i][N-1] == 'O' ) repChar(i, N-1, rc);
        } 

        for (int i = 0; i < M; ++i ) {
            for (int j = 0; j < N; ++j ) {
                if ( board[i][j] == 'O' ) repChar(i, j, 'X');
                if ( board[i][j] == 'O' ) board[i][j] = 'X';
                else if ( board[i][j] == rc ) board[i][j] = 'O';
            }
        } 
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<vector<char>> board{
            {'X', 'X', 'X', 'X',},
            {'X', 'O', 'O', 'X',},
            {'X', 'X', 'O', 'X',},
            {'X', 'O', 'X', 'X',},
        };

        sol.solve(board);
        for (auto ct : board) {
            for (auto i : ct){
                cout << i << " ";
            }
            cout <<endl;
        }
    }  

    {
        vector<vector<char>> board{
            {'O','O','O',},
            {'O','O','O',},
            {'O','O','O',},
        };

        sol.solve(board);
        for (auto ct : board) {
            for (auto i : ct){
                cout << i << " ";
            }
            cout <<endl;
        }
    }
    return 0;
}

