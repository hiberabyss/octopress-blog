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
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> res;
        if ( numRows < 1 ) return res;
        for (int i = 0; i < numRows; ++i ) {
            vector<int> line(i+1, 1);
            for (int j = 1; j < i; ++j ) {
                line[j] = res[i-1][j] + res[i-1][j-1];
            }
            res.push_back(line);
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        auto res = sol.generate(5);
        for (auto ct : res) {
            for (auto i : ct){
                cout << i << " ";
            }
            cout <<endl;
        }
    }
    return 0;
}

