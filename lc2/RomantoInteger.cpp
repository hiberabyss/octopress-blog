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

/*
I = 1;
IV = 4;
V = 5;
IX = 9;
X = 10;
XL = 40;
L = 50;
XC = 90;
C = 100;
CD = 400;
D = 500;
CM = 900
M = 1000;
*/

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        for (int i = 0; s[i]; ++i ) {
            if ( symb[s[i]] < symb[s[i+1]]  ) res -= symb[s[i]];
            else res += symb[s[i]];
        }

        return res;
    }

    // int romanToInt(string s) {
        // int res = 0;
        // for (int i = 0; s[i]; ++i ) {
            // if ( s[i+1] && symb.count(s.substr(i,2)) ) {
                // res += symb[s.substr(i++,2)];
            // } else {
                // res += symb[s.substr(i,1)];
            // } 
        // }
        // return res;
    // }

private:
    unordered_map<char,int> symb = {
        {NULL, 0},
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        string str = "a";
        cout << str.substr(0,2) <<endl;
    }
    {
        cout << sol.romanToInt("IV") <<endl;
    }
    return 0;
}
