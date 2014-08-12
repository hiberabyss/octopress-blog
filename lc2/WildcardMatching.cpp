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

// ToReview

using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        return isMatch2(s, p);
    }

    bool isMatch2(const char *s, const char *p) {
        const char *lp = NULL;
        auto ls = lp;
        while( s[0] ) {
            if ( p[0] == '?' || s[0] == p[0] ) s++,p++;
            else if ( p[0] == '*' ) {
                ls = s;
                lp = p;
                p++;
            } else if ( lp ) {
                s = ls+1;
                p = lp+1;
                ls++;
            } else return false;
        }

        while( p[0] == '*' ) p++;
        return !p[0];
    }

    bool isMatch1(const char *s, const char *p) {
        if ( !p[0] ) return !s[0];
        if ( p[0] == '*' ) {
            while ( s[0] ) {
                if ( isMatch1(s, p+1) ) return true;
                s++;
            } 
            return isMatch1(s,p+1);
        }

        if ( s[0] && ( p[0] == '?' || p[0] == s[0] ) ) return isMatch1(s+1, p+1);
        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
         cout << boolalpha << sol.isMatch("aa", "*a") <<endl;
    }
    return 0;
}

