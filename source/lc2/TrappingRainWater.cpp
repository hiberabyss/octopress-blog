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
    int trap(int A[], int n) {
        return trap2(A, n);
    }

    int trap2(int A[], int n) {
        // left wall height
        vector<int> lh(n,0);
        for (int i = 1; i < n; ++i ) lh[i] = max(lh[i-1], A[i-1]);

        // right wall height
        vector<int> rh(n,0);
        for (int i = n-2; i >= 0; --i ) rh[i] = max(rh[i+1],A[i+1]);

        int res = 0;
        for (int i = 1; i < n-1; ++i ) {
            int h = min(lh[i], rh[i]);
            if ( h>A[i] ) res += h-A[i];
        }
        return res;
    }

    int trap1(int A[], int n) {
        int maxi = 0;
        for (int i = 0; i < n; ++i ) {
            if ( A[i] > A[maxi] ) maxi = i;
        }

        int curMax = 0;
        int res = 0;
        for (int i = 0; i < maxi; ++i ) {
            if ( A[i] > curMax ) curMax = A[i];
            else res += curMax - A[i];
        }

        curMax = 0;
        for (int i = n-1; i > maxi; --i ) {
            if ( A[i] > curMax ) curMax = A[i];
            else res += curMax - A[i];
        }

        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
         int num[] = {0,1,0,2,1,0,1,3,2,1,2,1};
         int n = sizeof(num)/sizeof(*num);
         cout << sol.trap(num, n) <<endl;
    }
    return 0;
}

