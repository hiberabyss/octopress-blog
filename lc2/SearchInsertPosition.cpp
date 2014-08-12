#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        return lower_bound(A, n, target);
       // return upper_bound(A, n, target);
    }

    int lower_bound(int A[], int n, int target) {
        int l = 0;
        int h = n;
        while( l<h ) {
            int m = l + (h-l)/2;
            if ( A[m]<target ) l = m+1;
            else h = m;
        }
        return l;
    }

    int upper_bound(int A[], int n, int target) {
        int l=0, h=n;
        while( l<h ) {
            int m = l + (h-l)/2;
            if ( A[m] <= target ) l = m+1;
            else h=m;
        }

        return h;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    return 0;
}

