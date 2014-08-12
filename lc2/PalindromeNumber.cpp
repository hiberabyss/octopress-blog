#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// ToReview

class Solution {
public:
    bool isPalindrome(int x) {
        return isPalindrome2(x);
    }

    bool isPalindrome2(int x) {
        if ( x<0 ) return false;
        int d = 1;
        while ( x/d >= 10 ) d *= 10;

        while( x ) {
            if ( x/d != x%10 ) return false;
            x = (x%d) /10;
            d /= 100;
        }

        return true;
    }

    bool isPalindrome1(int x) {
        if ( x<0 ) return false;
        int tmp = x;
        long long rev = 0;

        while( tmp ) {
            rev = rev*10 + tmp%10;
            tmp /= 10;
        }

        return rev == x;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        cout << boolalpha << sol.isPalindrome(11) <<endl;
    }

    {
        cout << boolalpha << sol.isPalindrome(0) <<endl;
    }

    {
        cout << boolalpha << sol.isPalindrome(10000021) <<endl;
    }

    {
        cout << boolalpha << sol.isPalindrome(10000001) <<endl;
    }
    {
        cout << boolalpha << sol.isPalindrome(1001) <<endl;
    }

    return 0;
}
