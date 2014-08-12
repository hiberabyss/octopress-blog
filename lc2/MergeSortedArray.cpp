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
    void merge(int A[], int m, int B[], int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        while( k>=0 ) {
            if ( i<0 ) A[k] = B[j--];
            else if ( j<0 ) A[k] = A[i--];
            else if ( A[i] > B[j] ) A[k] = A[i--];
            else A[k] = B[j--];
            k--;
        }
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        int A[10] = {2};
        int B[] = {1};
        sol.merge(A, 1, B, 1);
        for (int i = 0; i < 2; ++i ) {
            cout << A[i] << " ";
        }
        cout <<endl;
    }
    return 0;
}

