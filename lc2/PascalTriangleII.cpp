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
    vector<int> getRow(int rowIndex) {
        return getRow2(rowIndex);
    }

    vector<int> getRow2(int rowIndex) {
        vector<int> res(rowIndex+1, 1);
        for (int i = 2; i <= rowIndex; ++i ) {
            for (int j = i-1; j >= 1; --j ) {
                res[j] += res[j-1];
            }
        }
        return res;
    }

    vector<int> getRow1(int rowIndex) {
        vector<int> line(rowIndex+1, 1);
        for (int i = 2; i <= rowIndex; ++i ) {
            int pre = 1;
            for (int j = 1; j < i; ++j ) {
                int tmp = line[j];
                line[j] += pre;
                pre = tmp;
            }
        }
        return line;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        auto res = sol.getRow(3);
        for (auto i : res) cout << i << " ";
        cout <<endl;
    }
    return 0;
}
