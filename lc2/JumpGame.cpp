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
    bool canJump(int A[], int n) {
        int far = 0;
        for (int i = 0; i < n; ++i ) {
            if ( i <= far ) far = max(far, i+A[i]);
            else return false;
            if ( far >= n-1 ) return true;
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    return 0;
}

