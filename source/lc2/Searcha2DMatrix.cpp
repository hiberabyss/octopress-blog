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
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if ( matrix.empty() ) return false;
        int C = matrix[0].size();
        int N = matrix.size() * matrix[0].size();
        int l = 0;
        int h = N-1;
        while( l<=h ) {
            int m = l + (h-l)/2;
            int val = matrix[m/C][m%C];
            if ( val < target ) l = m+1;
            else if ( val > target ) h = m-1;
            else return true;
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<vector<int>> matrix = {
            {1,   3,  5,  7},
            {10, 11, 16, 20},
            {23, 30, 34, 50},
        };
    }
    return 0;
}

