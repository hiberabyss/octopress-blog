#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// ToReview

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long dd = dividend;
        long long dr = divisor;
        int isNeg = 0;
        if ( dd<0 ) dd = -dd, isNeg = !isNeg;
        if ( dr<0 ) dr = -dr, isNeg = !isNeg;

        long long res = 0;
        while( dd >= dr ) {
            long long tmp = dr;
            int sf = 0;
            while ( (tmp<<1) <= dd ) tmp <<= 1, sf++;
            dd -= tmp;
            res |= 1<<sf;
        }

        return isNeg ? -res : res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        cout << sol.divide(10, 3);
    }
    return 0;
}

