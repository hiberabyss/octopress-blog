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
    void rotate(vector<vector<int> > &matrix) {
        // return rotate1(matrix);
        return rotate2(matrix);
    }

    // move square
    void rotate2(vector<vector<int> > &matrix) {
        int N = matrix.size();
        for (int i = 0; i < (N>>1); ++i ) {
            // little square
            for (int j = i; j < (N-1-i); ++j ) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[N-1-j][i];
                matrix[N-1-j][i] = matrix[N-1-i][N-1-j];
                matrix[N-1-i][N-1-j] = matrix[j][N-1-i];
                matrix[j][N-1-i] = tmp;
            }
        }
    }

    void rotate1(vector<vector<int> > &matrix) {
        int N = matrix.size();
        for (int i = 0; i < N; ++i ) {
            for (int j = i+1; j < N; ++j ) {
                swap(matrix[i][j], matrix[j][i]);
            }
            reverse( matrix[i].begin(), matrix[i].end() );
        }
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    return 0;
}

