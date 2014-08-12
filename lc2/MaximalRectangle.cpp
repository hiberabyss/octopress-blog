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
    int maximalRectangle(vector<vector<char> > &matrix) {
        // return maximalRectangle1(matrix);
        return maximalRectangle2(matrix);
    }

    int maximalRectangle3(vector<vector<char> > &matrix) {
        if ( matrix.empty() ) return 0;
        int M = matrix.size();
        int N = matrix[0].size();
        vector<int> hs(N+1, 0);

        int res = 0;
        for (int i = 0; i < M; ++i ) {
            for (int j = 0; j < N; ++j ) {
                if ( matrix[i][j] == '0' ) hs[j] = 0;
                else hs[j]++; 
            }

            stack<int> stk;
            for (int j = 0; j <= N; ++j ) {
                while( !stk.empty() && hs[j] <= hs[stk.top()] ) {
                    int h = hs[stk.top()];
                    stk.pop();
                    int w = stk.empty() ? j : j - stk.top() -1;
                    res = max(res, h*w);
                }
                stk.push(j);
            }
        }
        return res;
    }

    int maximalRectangle2(vector<vector<char> > &matrix) {
        if ( matrix.empty() ) return 0;
        int M = matrix.size();
        int N = matrix[0].size();
        vector<vector<int>> ws(M, vector<int>(N));

        for (int i = 0; i < M; ++i ) {
            int cnt = 0;
            for (int j = 0; j < N; ++j ) {
                if ( matrix[i][j] == '1' ) cnt++;
                else cnt = 0;
                ws[i][j] = cnt;
            }
        }

        int res = 0;
        for (int j = 0; j < N; ++j ) {
            stack<int> stk;
            for (int i = 0; i <= M; ++i ) {
                while( !stk.empty() && (i==M || ws[i][j] <= ws[stk.top()][j] ) ) {
                    int h = ws[stk.top()][j];
                    stk.pop();
                    int w = stk.empty() ? i : i - stk.top() - 1;
                    res = max(res, h*w);
                }
                stk.push(i);
            }
        }
        return res;
    }

    int maximalRectangle1(vector<vector<char> > &matrix) {
        if ( matrix.empty() ) return 0;
        int M = matrix.size();
        int N = matrix[0].size();
        vector<vector<int>> cnt(M, vector<int>(N));

        for (int i = 0; i < M; ++i ) {
            int cur = 0;
            for (int j = 0; j < N; ++j ) {
                if ( matrix[i][j] == '1' ) cur++;
                else cur = 0;
                cnt[i][j] = cur;
            }
        }

        int res = 0;
        for (int i = M-1; i >= 0; --i ) {
            for (int j = N-1; j >= 0; --j ) {
                if ( !cnt[i][j] ) continue;
                int minh = cnt[i][j];
                for (int k = i; k >= 0 && cnt[k][j]; --k ) {
                    minh = min(minh, cnt[k][j]);
                    res = max(res, minh * (i-k+1));
                }
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<vector<char>> matrix{ {'0', '1'} };
        cout << sol.maximalRectangle(matrix) <<endl;
    }
    return 0;
}

