#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// ToReview

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if ( n<2 ) return n;
        int i = 1;
        for (int j = 1; j < n; ++j ) {
            if ( A[j] != A[i-1] ) A[i++] = A[j];
        }
        return i;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        int arr[] = {1,1,2};
        int len = sizeof(arr)/sizeof(*arr);
        int res = sol.removeDuplicates(arr, len);
        cout << "res: " << res <<endl;
        for (int i = 0; i < res; ++i ) {
            cout << arr[i] << " ";
        }
        cout <<endl;
    }
    return 0;
}

