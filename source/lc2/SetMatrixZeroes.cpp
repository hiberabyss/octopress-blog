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
    void setZeroes(vector<vector<int> > &matrix) {
        if ( matrix.empty() ) return;
        int M = matrix.size();
        int N = matrix[0].size();
        bool isFirRow = false;
        for (int j = 0; j < N && !isFirRow; ++j ) {
            if ( !matrix[0][j] ) isFirRow=true;
        }
        bool isFirCol = false;
        for (int i = 0; i < M && !isFirCol; ++i ) {
            if ( !matrix[i][0] ) isFirCol=true;
        }

        for (int i = 1; i < M; ++i ) {
            for (int j = 1; j < N; ++j ) {
                if ( !matrix[i][j] ) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < M; ++i ) {
            if ( !matrix[i][0] )
                for (int j = 1; j < N; ++j ) matrix[i][j] = 0;
        }

        for (int j = 1; j < N; ++j ) {
            if ( !matrix[0][j] )
                for (int i = 1; i < M; ++i ) matrix[i][j] = 0;
        }

        if ( isFirRow ) for (int j = 0; j < N; ++j ) matrix[0][j] = 0;
        if ( isFirCol ) for (int i = 0; i < M; ++i ) matrix[i][0] = 0;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    return 0;
}

