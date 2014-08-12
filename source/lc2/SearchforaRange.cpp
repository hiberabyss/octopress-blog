#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int l = 0;
        int h = n-1;
        while( l<h ) {
            int m = l + (h-l)/2;
            if ( A[m] < target ) l = m+1;
            else h = m;
        }
        if ( A[l] != target ) return vector<int>({-1,-1});
        while( h<n-1 && A[h] == A[h+1] ) h++;
        return vector<int>({l,h});
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        int A[] = {5, 7, 7, 8, 8, 10};
        int n = sizeof(A)/sizeof(*A);
        auto res = sol.searchRange(A,n,8);
        for (auto i : res) {
            cout << i << " ";
        }
        cout <<endl;
    }
    return 0;
}

