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

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        auto cmp = [] (const Interval &iv1, const Interval &iv2) {
            return iv1.start < iv2.start;
        };
        
        sort( intervals.begin(), intervals.end(), cmp );
        vector<Interval> res;

        int N = intervals.size();
        int i = 0;
        while( i<N ) {
            auto cur = intervals[i];
            int j = i+1;
            while ( j < N && intervals[j].start <= cur.end ) {
                cur.end = max(cur.end, intervals[j].end);
                j++;
            }
            res.push_back(cur);
            i=j;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<Interval> ivs{
            Interval(1,3),
            Interval(2,6),
            Interval(8,10),
            Interval(15,18),
        };
        auto res = sol.merge(ivs);
        for (auto i : res) {
            cout << i.start << " " << i.end <<endl;
        }
    }
    return 0;
}

