#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// ToReview

class Solution {
public:
    int sqrt(int x) {
        return sqrt2(x);
    }

    // newton (a+b)/2
    int sqrt2(int x) {
        long long l = 0, h = x;

        while( l<h ) {
            long long m = l + (h-l+1)/2;
            if ( m*m > x ) h = m-1;
            else l = m;
        }

        return l;
    }

    int sqrt1(int x) {
        if ( x<0 ) return -1;
        int res = 1;
        while ( res*res <= x ) res++;
        return res-1;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        cout << sol.sqrt(2147483647) <<endl;
    }
    {
        cout << sol.sqrt(10) <<endl;
    }
    return 0;
}
