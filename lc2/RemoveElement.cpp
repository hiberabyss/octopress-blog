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
    int removeElement(int A[], int n, int elem) {
        int p = 0;
        for (int i = 0; i < n; ++i ) {
            if ( A[i] != elem ) A[p++] = A[i];
        }
        return p;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    return 0;
}

