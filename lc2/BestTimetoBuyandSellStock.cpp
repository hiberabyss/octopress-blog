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
    int maxProfit(vector<int> &prices) {
        int res = 0;
        int curMin = INT_MAX;
        for (int i = 0; i < prices.size(); ++i ) {
            curMin = min(curMin, prices[i]);
            res = max(res, prices[i] - curMin);
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    return 0;
}

