/* 
 * 10-1
 */

// ToReview

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s) {
        return partition1(s);
    }

    vector<vector<string> > partition2(string &s) {
    }

    vector<vector<string> > partition1(string &s) {
        auto isPal = [&] (const string &str) {
            int N = str.size();
            for (int i = 0; i < N/2; ++i ) {
                if ( str[i] != str[N-i-1] ) return false;
            }
            return true;
        };

        // cout << boolalpha << isPal("ab") <<endl;

        vector<string> part;
        vector<vector<string>> res;

        function<void(string)> getPart = [&] (string str) {
            if ( str.empty() ) {
                res.push_back(part);
                return;
            }

            for (size_t i = 1; i <= str.size(); ++i ) {
                if ( !isPal(str.substr(0,i)) ) continue;
                part.push_back(str.substr(0,i));
                getPart(str.substr(i));
                part.pop_back();
            }
        };

        getPart(s);

        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        string s = "aab";
        auto res = sol.partition(s);

        for (auto ct : res) {
            for (auto i : ct){
                cout << i << " ";
            }
            cout <<endl;
        }
    }
    return 0;
}

