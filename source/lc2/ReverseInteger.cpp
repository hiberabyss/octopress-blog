#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        // must init
        long long rev = 0;
        while( x ) {
            rev = rev*10 + x%10;
            x /= 10;
        }
        return rev;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        cout << sol.reverse(0) <<endl;
    }
    return 0;
}

