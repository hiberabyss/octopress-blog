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
    int singleNumber(int A[], int n) {
        int res;
        int even = 0;
        int odd = 0;
        for (int i = 0; i < n; ++i ) {
            even |= (odd & A[i]);
            odd ^= A[i];
            int tmp = ~(even&odd);
            even &= tmp;
            odd &= tmp;
        }

        return odd;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        int A[] = {1,2,1,1};
        int n = sizeof(A)/sizeof(*A);
        cout << sol.singleNumber(A, n) <<endl;
    }
    return 0;
}

