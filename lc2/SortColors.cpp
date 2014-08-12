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
    void sortColors(int A[], int n) {
        // sortColors1(A,n);
        sortColors2(A,n);
    }

    void sortColors2(int A[], int n) {
        int zero = -1;
        int one = -1;
        int two = -1;
        for (int i = 0; i < n; ++i ) {
            if ( !A[i] ) {
                A[++two] = 2;
                A[++one] = 1;
                A[++zero] = 0;
            } else if ( A[i] == 1 ) {
                A[++two] = 2;
                A[++one] = 1;
            } else {
                A[++two] = 2;
            }
        }
    }

    void sortColors1(int A[], int n) {
        vector<int> cnt(3, 0);
        for (int i = 0; i < n; ++i ) cnt[A[i]]++;
        int k = 0;
        for (int i = 0; i < 3; ++i ) {
            for (int j = 0; j < cnt[i]; ++j ) A[k++] = i;
        }
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    return 0;
}

