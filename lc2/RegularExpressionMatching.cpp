#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// ToReview Important
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if ( !p[0] ) return !s[0];

        if ( p[1] == '*' ) {
            // this is important
            while ( s[0] && ( p[0] == '.' || s[0] == p[0] ) ) {
            // if ( p[0] == '.' || s[0] == p[0] ) {
                if ( isMatch(s, p+2) ) return true;
                s++;
            }

            return isMatch(s, p+2);
        }

        if ( (s[0] && p[0] == '.') || s[0] == p[0] ) return isMatch(s+1, p+1);
        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        cout << boolalpha;
        cout << sol.isMatch("aa", "a") <<endl;
        cout << sol.isMatch("aa", "aa") <<endl;
        cout << sol.isMatch("aaa", "aa") <<endl;
        cout << sol.isMatch("aa", ".*") <<endl;
        cout << sol.isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*c") <<endl;
        cout << sol.isMatch("a", "ab*") <<endl;;
        cout << sol.isMatch("", ".") <<endl;
    }
    return 0;
}

