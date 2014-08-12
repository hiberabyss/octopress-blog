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
    vector<int> grayCode(int n) {
        vector<int> res(1);
        for (int i = 0; i < n; ++i ) {
            int N = res.size();
            for (int j = N-1; j >= 0; --j ) {
                int copy = res[j] + (1<<i);
                res.push_back(copy);
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        auto res = sol.grayCode(2);
        for (auto i : res) cout << i << " ";
        cout <<endl;
    }
    return 0;
}

