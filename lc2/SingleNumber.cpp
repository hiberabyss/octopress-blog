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
    int singleNumber(int A[], int n) {
        int res = 0;
        for (int i = 0; i < n; ++i ) {
            res ^= A[i];
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    return 0;
}

