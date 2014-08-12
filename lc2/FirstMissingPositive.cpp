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
    int firstMissingPositive(int A[], int n) {
        int i = 0;
        while( i<n ) {
            if ( A[i]>0 && A[i]<=n && i != A[i]-1 && A[i] != A[A[i]-1] ) swap(A[i], A[A[i]-1]);
            else i++;
        }

        i = 0;
        while( i<n && A[i] == i+1 ) i++;
        return i+1;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        int A[] = {1,2,0};
        int n = sizeof(A)/sizeof(*A);
        cout << sol.firstMissingPositive(A,n) <<endl;
    }
    return 0;
}

