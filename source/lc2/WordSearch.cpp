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
    bool exist(vector<vector<char> > &board, string word) {
        return exist1(board, word);
    }

    /* bool exist2(vector<vector<char> > &board, string word) {
        if ( board.empty() ) return false;
        int M = board.size();
        int N = board[0].size();
        vector<vector<bool> > visit(M, vector<bool>(N, false));

        auto dfs = [&] (int x, int y) {
            int k = 0;
            stack<pair<int,int>> stk;
            stk.push({x,y});
            while( !stk.empty() ) {
                if( !word[k] ) return true;
                x = stk.front().first;
                y = stk.front().second;
                if ( x<0 || x>=M || y<0 || y>= N ) continue;

                if ( visit[x][y] || board[x][y] != word[k] ) continue;

                visit[x][y] = true;

                stk.push({x-1,y});
                stk.push({x+1,y});
                stk.push({x,y-1});
                stk.push({x,y+1});
                k++;
            }
        };
    } */

    bool exist1(vector<vector<char> > &board, string word) {
        if ( board.empty() ) return false;
        int M = board.size();
        int N = board[0].size();
        vector<vector<bool> > visit(M, vector<bool>(N, false));

        function<bool(int,int,int)> dfs = [&](int x, int y, int k) {
            if ( !word[k] ) return true;
            if ( x<0 || x>=M || y<0 || y>=N ) return false;
            if ( visit[x][y] || board[x][y] != word[k] ) return false;
            visit[x][y] = true;

            // why this will timeout???
            /* for (int d = -2; d <= 2; ++d ) {
                int cx = x + d/2;
                int cy = y + d%2;
                if ( cx<0 || cx>=M || cy<0 || cy>=N ||
                     visit[cx][cy] ) continue;
                if ( dfs(cx, cy, k+1) ) {
                    res = true;
                    break;
                }
            }  */

            auto res = dfs(x-1, y, k+1) ||
                       dfs(x+1, y, k+1) ||
                       dfs(x, y-1, k+1) ||
                       dfs(x, y+1, k+1);
            visit[x][y] = false;
            return res;
        };

        for (int i = 0; i < M; ++i ) {
            for (int j = 0; j < N; ++j ) {
                if ( dfs(i,j,0) ) return true;
            }
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    /* {
        vector<vector<char>> board{
              {'A','B','C','E',},
              {'S','F','C','S',},
              {'A','D','E','E',},
        };

        string word = "ABCCED";
        cout << boolalpha << sol.exist(board, word) <<endl;
    } 
    {
        vector<vector<char>> board{
              {'a', 'b'},
              {'c', 'd'},
        };

        string word = "abcd";
        cout << boolalpha << sol.exist(board, word) <<endl;
    } */
    {
        vector<vector<char>> board{
            {'A','B','C','E',},
            {'S','F','E','S',},
            {'A','D','E','E',}
        };

        string word = "ABCESEEEFS";
        cout << boolalpha << sol.exist(board, word) <<endl;
    }
    return 0;
}

