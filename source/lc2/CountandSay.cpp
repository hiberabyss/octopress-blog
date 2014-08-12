#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        if ( n<2 ) return res;
        for (int i = 2; i <= n; ++i ) {
            string prev = res;
            res.clear();
            for (int i = 0; prev[i]; ++i ) {
                int cnt=1;
                while ( prev[i] == prev[i+1] ) i++,cnt++;
                res += to_string(cnt) + prev[i];
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        cout << sol.countAndSay(5) <<endl;
    }
    return 0;
}

