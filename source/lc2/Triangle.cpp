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

// ToReview

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        return minimumTotal3(triangle);
        return minimumTotal2(triangle);
        return minimumTotal1(triangle);
    }

    int minimumTotal3(vector<vector<int> > &triangle) {
        int N = triangle.size();
        vector<int> dp(N,0);
        copy( triangle[N-1].begin(), triangle[N-1].end(), dp.begin() );
        for (int i = N-2; i >= 0; --i ) {
            for (int j = 0; j <= i; ++j ) {
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }
        return dp[0];
    }

    int minimumTotal2(vector<vector<int> > &triangle) {
        int N = triangle.size();

        vector<int> dp(N,0);
        dp[0] = triangle[0][0];
        for (int i = 1; i < N; ++i ) {
            for (int j = i; j >= 0; --j ) {
                if ( j == i ) dp[j] = dp[i-1];
                else if ( j > 0 ) dp[j] = min(dp[j], dp[j-1]);
                dp[j] += triangle[i][j];
            }
        }

        return *min_element( dp.begin(), dp.end() );
    }

    int minimumTotal1(vector<vector<int> > &triangle) {
        if ( triangle.empty() ) return -1;
        int M = triangle.size();
        int N = triangle[0].size();

        function<int(int,int)> getMinPath = [&] (int i, int j) {
            if ( i == M ) return 0;
            int res = min(getMinPath(i+1, j), getMinPath(i+1, j+1));
            return res+triangle[i][j];
        };

        return getMinPath(0, 0);
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<vector<int>> triangle{
            {2},
            {3,4},
            {6,5,7},
            {4,1,8,3},
        };

        cout << sol.minimumTotal(triangle) <<endl;
    }
    return 0;
}

