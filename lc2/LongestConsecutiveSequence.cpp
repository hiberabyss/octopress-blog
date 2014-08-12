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
    int longestConsecutive(vector<int> &num) {
        return longestConsecutive1(num);
    }

    int longestConsecutive1(vector<int> &num) {
        int N = num.size();
        unordered_map<int,int> map;
        int res = 0;
        for (auto i : num) {
            if ( !map.count(i) ) {
                map[i] = 1;
                int b = i;
                int e = i;
                if ( map.count(i-1) ) {
                    b = i - map[i-1];
                    map[i] += map[i-1];
                } 

                if ( map.count(i+1) ) {
                    e = i + map[i+1];
                    map[i] += map[i+1];
                }

                map[b] = map[e] = map[i];
                res = max(res, map[i]);
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<int> num{100, 4, 200, 1, 3, 2};
        cout << sol.longestConsecutive(num) <<endl;
    }
    return 0;
}

