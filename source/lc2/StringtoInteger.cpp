#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

// ToReview

class Solution {
public:
    int atoi(const char *str) {
        long long res = 0;
        int i = 0;
        bool isNeg = false;
        bool isFir = true;

        while( str[i] == ' ' ) i++;
        if ( str[i] == '+' || str[i] == '-' ) {
            if ( str[i] == '-' ) isNeg = true;
            i++;
        }

        while( str[i] ) {
            if ( !isdigit(str[i]) ) break;
            res = res*10 + str[i] - '0';
            if ( res > INT_MAX ) {
                if ( isNeg ) return INT_MIN;
                else return INT_MAX;
            }
            i++;
        }

        return isNeg ? -1*res : res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        string num = "010";
        cout << sol.atoi(num.c_str()) <<endl;
    }
    {
        string num = "+-2";
        cout << sol.atoi(num.c_str()) <<endl;
    }
    {
        string num = "     +004500";
        cout << sol.atoi(num.c_str()) <<endl;
    }
    return 0;
}

