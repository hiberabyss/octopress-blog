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
    int maxSubArray(int A[], int n) {
        int maxS = INT_MIN;
        int curMax = 0;
        for (int i = 0; i < n; ++i ) {
            curMax += A[i];
            maxS = max(maxS, curMax);
            if ( curMax < 0 ) curMax = 0;
        }
        return maxS;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    return 0;
}
