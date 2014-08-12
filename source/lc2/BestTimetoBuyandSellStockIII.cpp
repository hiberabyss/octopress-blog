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
#include <climits>

using namespace std;

// ToReview

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int N = prices.size();
        if ( prices.size() < 2 ) return 0;
        vector<int> lp(N, 0);
        int curMin = prices[0];
        for (int i = 1; i < N; ++i ) {
            curMin = min(curMin, prices[i]);
            lp[i] = max(lp[i-1], prices[i]-curMin);
        }

        vector<int> rp(N,0);
        int curMax = prices[N-1];
        for (int i = N-2; i >= 0; --i ) {
            curMax = max(curMax, prices[i]);
            rp[i] = max(rp[i+1], curMax-prices[i]);
        }

        int res = 0;
        for (int i = 0; i < N; ++i ) res = max(res, lp[i]+rp[i]);
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<int> prices{2,1,2,0,1};
        cout << sol.maxProfit(prices) <<endl;
    }
    {
        vector<int> prices{1,2};
        cout << sol.maxProfit(prices) <<endl;
    }
    return 0;
}

