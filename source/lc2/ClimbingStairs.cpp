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
    int climbStairs(int n) {
        // return climbStairs1(n);
        // return climbStairs2(n);
        return climbStairs3(n);
    }

    int climbStairs3(int n) {
        vector<vector<int>> m = {
            {1,1},
            {1,0},
        };
        auto mul = [&] (decltype(m) &a, decltype(m) &b) {
            decltype(m) c(2, vector<int>(2));
            for (int i = 0; i < 2; ++i ) {
                for (int j = 0; j < 2; ++j ) {
                    for (int k = 0; k < 2; ++k ) {
                        c[i][j] += a[i][k] * b[k][j];
                    }
                }
            }
            return c;
        };
        decltype(m) base=m;
        decltype(m) res = {
            {1,0},
            {0,1},
        };

        while( n ) {
            if(n&1) res = mul(res, base);
            base = mul(base, base);
            n >>= 1;
        }
        return res[0][0];
    }

    int climbStairs2(int n) {
        int steps[3] = {1,1};
        for (int i = 2; i <= n; ++i ) {
            steps[2] = steps[0] + steps[1];
            steps[0] = steps[1];
            steps[1] = steps[2];
        }
        return steps[1];
    }

    int climbStairs1(int n) {
        if ( n<0 ) return 0;
        if ( !n ) return 1;
        return climbStairs1(n-1) + climbStairs1(n-2);
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        cout << sol.climbStairs(38) <<endl;
    }
    return 0;
}

