#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        return getPermutation1(n, k);
    }

    string getPermutation1(int n, int k) {
        vector<int> fa(n+1, 1);
        for (int i = 2; i <= n; ++i ) fa[i] = fa[i-1] * i;
        k--;
        // cycle
        k %= fa[n];
        vector<int> ind(n, 0);
        iota( ind.begin(), ind.end(), 0 );

        string res;
        for (int i = 0; i < n; ++i ) {
            int pfa = fa[n-i-1];
            int j = k/pfa;
            k %= pfa;
            res += ind[j] + '1';

            for (int k = j; k < n-i-1; ++k ) ind[k] = ind[k+1];
        }

        return res;
    }

    string getPermutation2(int n, int k) {
        string res(n, '1');
        iota( res.begin(), res.end(), '1' );
        for (int i = 1; i < k; ++i ) {
            next_permutation( res.begin(), res.end() );
        }

        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        cout << sol.getPermutation(3, 5) <<endl;
    }
    return 0;
}
