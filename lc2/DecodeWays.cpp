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

using namespace std;

// ToReview

class Solution {
public:
    int numDecodings(string s) {
        if ( s.empty() || s[0] == '0' ) return 0;
        int n0 = 1;
        int n1 = 1;
        for (int i = 1; s[i]; ++i ) {
            int cur = 0;
            if ( s[i] != '0' ) cur += n1;
            int tmp = stoi(s.substr(i-1,2));
            if ( tmp > 9 && tmp < 27 ) cur += n0;
            n0 = n1;
            n1 = cur;
        }
        return n1;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        string str = "10";
        cout << sol.numDecodings(str) <<endl;
    }
    return 0;
}
