#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string,vector<string>> map;
        for (auto &s : strs) {
            map[strSort(s)].push_back(s);
        }

        vector<string> res;
        for (auto m : map) {
            auto &vec = m.second;
            if ( vec.size() > 1 )
                copy( vec.begin(), vec.end(), back_inserter(res) );
        }

        return res;
    }

    string strSort(string &s) {
        string res;
        vector<int> cnt(26,0);
        for (auto c : s) cnt[c-'a']++;
        for (size_t i = 0; i < cnt.size(); ++i ) {
            res += string(cnt[i], i+'a');
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    return 0;
}

