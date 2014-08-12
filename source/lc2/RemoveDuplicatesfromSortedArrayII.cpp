#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if ( n<3 ) return n;
        int i = 2;
        for (int j = 2; j < n; ++j ) {
            if ( A[j] != A[i-2] ) A[i++] = A[j];
        }

        return i;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        int A[] = {1,1,1,2,2,3};
        int len = sizeof(A)/sizeof(*A);
        auto res = sol.removeDuplicates(A,len);
        for (int i = 0; i < res; ++i ) {
            cout << A[i] << " ";
        }
        cout <<endl;
    }

    {
        int A[] = {1,2,3};
        int len = sizeof(A)/sizeof(*A);
        auto res = sol.removeDuplicates(A,len);
        for (int i = 0; i < res; ++i ) {
            cout << A[i] << " ";
        }
    }

    return 0;
}

