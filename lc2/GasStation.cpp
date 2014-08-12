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
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int rem = 0;
        int curMax = 0;
        int res = 0;
        for (int i = 0; i < gas.size(); ++i ) {
            int diff = gas[i] -cost[i];
            rem += diff;
            curMax += diff;
            if ( curMax < 0 ) curMax=0, res=i+1;
        }
        if ( rem<0 ) return -1;
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<int> gas = {1,2,3,4,5};
        vector<int> cost = {3,4,5,1,2};
        cout << sol.canCompleteCircuit(gas,cost) <<endl;
    }
    return 0;
}
