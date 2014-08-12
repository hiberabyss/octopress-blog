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

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        return restoreIpAddresses1(s);
    }

    vector<string> restoreIpAddresses1(string s) {
        int N = s.size();
        vector<string> res;
        string ip;

        function<void(int,int)> getIP = [&](int i, int n) {
            if ( i>=N && n == 4 ) {
                ip.pop_back();
                res.push_back(ip);
                return;
            }

            int L = N-i;
            if ( L<(4-n) || L > 3*(4-n) ) return;

            L = min(L,3);
            for (int l = 1; l <= L; ++l ) {
                auto str = s.substr(i,l);
                if ( stoi(str) < 256 ) {
                    auto tmp = ip;
                    ip += str + '.';
                    getIP(i+l, n+1);
                    ip = tmp;
                    if ( s[i] == '0' ) break;
                }
            }
        };

        getIP(0,0);
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
         string ip = "25525511135";
         auto res = sol.restoreIpAddresses(ip);
         for (auto s : res) {
             cout << s <<endl;
         }
         cout <<endl;
    }
    {
         string ip = "010010";
         auto res = sol.restoreIpAddresses(ip);
         for (auto s : res) {
             cout << s <<endl;
         }
         cout <<endl;
    }
    return 0;
}
