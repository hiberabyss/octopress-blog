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
    int lengthOfLongestSubstring(string s) {
        if ( s.empty() ) return 0;
        int res = 0;
        int i = 0;
        int j = i;
        unordered_map<char,int> map;
        while( s[j] ) {
            if ( map.count(s[j]) && map[s[j]] >= i ){
                res = max(res, j-i);
                i = map[s[j]]+1;
            }
            map[s[j]] = j;
            j++;
        }
        res = max(res, j-i);
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        string str = "abcabcbb";
        cout << sol.lengthOfLongestSubstring(str) <<endl;
    }
    {
        string str = "bbbbb";
        cout << sol.lengthOfLongestSubstring(str) <<endl;
    }
    return 0;
}

