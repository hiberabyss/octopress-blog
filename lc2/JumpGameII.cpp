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
    int jump(int A[], int n) {
        int res = 0;
        int last = 0;
        int next = 0;
        for (int i = 0; i < n; ++i ) {
            if ( i>last ) {
                res++;
                if ( last == next ) return -1;
                last = next;
                if ( last >= n-1 ) break;
            }
            
            next = max(next, i+A[i]);
        }

        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    return 0;
}

