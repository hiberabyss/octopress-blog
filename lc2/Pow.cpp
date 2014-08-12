#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    // be cautious with INT_MAX
    double pow(double x, int n) {
        double res = 1.0;
        bool isNeg = false;
        long long p = n;
        if ( n<0 ) isNeg = true, p=-p;
        double base = x;
        while(p) {
            if ( p&1 ) res *= base;
            base *= base;
            p >>= 1;
        }
        return isNeg ? 1.0/res : res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        int a = 0x80000000;
        cout << a <<endl;
        long long b = abs(a);
        cout << b <<endl;
        return 0;
    } 
    {
        cout << sol.pow(2, -3) <<endl;
    }
    {
        cout << sol.pow(3, 4) <<endl;
    }
    {
        cout << sol.pow(1.00000, -2147483648) <<endl;
    }
    return 0;
}

