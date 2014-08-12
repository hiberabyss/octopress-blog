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
    int search(int A[], int n, int target) {
        return search2(A, n , target);
    }

    int search2(int A[], int n, int target) {
        int l = 0;
        int h = n-1;
        while( l<=h ) {
            int m = l + (h-l)/2;
            if ( A[m] == target ) return m;
            if ( A[m] >= A[l] ) {
                if ( target < A[m] && target >= A[l] ) h = m-1;
                else l = m+1;
            } else {
                if ( target > A[m] && target <= A[h] ) l = m+1;
                else h = m-1;
            }
        }
        return -1;
    }

    int search1(int A[], int n, int target) {
        int l = 0;
        int h = n-1;
        while( l<=h ) {
            int m = l + (h-l)/2;
            if ( target == A[m] ) return m;
            if ( target == A[l] ) return l;
            if ( target == A[h] ) return h;
            if ( A[m] > A[l] ) {
                if ( target > A[l] && target < A[m] ) h = m-1;
                else l = m+1;
            } else {
                if ( target > A[m] && target < A[h] ) l = m+1;
                else h = m-1;
            }
        }
        return -1;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    return 0;
}

