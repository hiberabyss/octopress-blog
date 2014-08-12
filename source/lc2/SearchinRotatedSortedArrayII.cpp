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
    bool search(int A[], int n, int target) {
        return search2(A, n, target);
    }

    bool search2(int A[], int n, int target) {
        int l = 0;
        int h = n-1;
        while( l<=h ) {
            int m = l + (h-l)/2;
            if ( A[m] == target ) return true;
            if ( A[m] > A[l] ) {
                if ( target < A[m] && target >= A[l] ) h = m-1;
                else l = m+1;
            } else if ( A[m] < A[l] ) {
                if ( target > A[m] && target <= A[h] ) l = m+1;
                else h = m-1;
            } else l++;
        }
        return false;
    }

    bool search1(int A[], int n, int target) {
        int l = 0;
        int h = n-1;
        while( l<=h ) {
            int m = l + (h-l)/2;
            if ( A[m] == target ) return true;
            if ( A[m] > A[l] ) {
                if ( target < A[m] && target >= A[l] ) h = m-1;
                else l = m+1;
            } else if ( A[m] < A[l] ) {
                if ( target > A[m] && target <= A[h] ) l = m+1;
                else h = m-1;
            } else l++;
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        int A[] = {1,3};
        int N = sizeof(A)/sizeof(*A);
        cout << boolalpha << sol.search(A, N, 3) <<endl;
    }
    {
        int A[] = {3,1};
        int N = sizeof(A)/sizeof(*A);
        cout << boolalpha << sol.search(A, N, 1) <<endl;
    }
    return 0;
}
