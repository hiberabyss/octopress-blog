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
#include <cstring>

using namespace std;

// ToReview
// DFA

class Solution {
public:
    bool isNumber(const char *s) {
        int i = 0;
        while ( s[i] == ' ' ) i++;
        if ( s[i] == '+' || s[i] == '-' ) i++;

        bool isFirDot = true;
        bool isFirE = true;
        bool isNum = false;

        while( s[i] ) {
            if ( s[i] == '.' && isFirDot && isFirE ) {
                isFirDot = false;
                i++;
                continue;
            }

            if ( toupper(s[i]) == 'E' && isFirE && isNum ) {
                isNum = false;
                isFirE = false;
                i++;
                if ( s[i] == '+' || s[i] == '-' ) i++;
                continue;
            }

            if ( isdigit(s[i]) ) isNum = true;
            else if ( s[i] == ' ' ) break;
            else return false;
            i++;
        }
        while ( s[i] == ' ' ) i++;
        return !s[i] && isNum;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        cout << 3E10 <<endl;
        cout << boolalpha << sol.isNumber(".") <<endl;
    }
    {
        cout << boolalpha << sol.isNumber("2e10") <<endl;
    }

    {
        cout << boolalpha << sol.isNumber("3.") <<endl;
    }

    {
        cout << boolalpha << sol.isNumber("  ") <<endl;
    }

    {
        cout << boolalpha << sol.isNumber("6e6.5") <<endl;
    }

    {
        cout << boolalpha << sol.isNumber("005047e+6") <<endl;
    }
    return 0;
}

