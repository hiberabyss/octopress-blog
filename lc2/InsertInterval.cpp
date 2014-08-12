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

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    }

    vector<Interval> insert1(vector<Interval> &intervals, Interval newInterval) {
        int N = intervals.size();
    }

    vector<Interval> insert2(vector<Interval> &intervals, Interval newInterval) {
        int N = intervals.size();
        int l = 0;
        int h = N;
        while( l<h ) {
            int m = l + (h-l)/2;
            if ( intervals[m].start < newInterval.start ) l = m+1;
            else h = m;
        }

        vector<Interval> res;
        for (int i = 0; i < l; ++i ) {
            if ( i == l-1 && intervals[i].end >= newInterval.start ) {
                newInterval.start = intervals[i].start;
                newInterval.end = max(newInterval.end, intervals[i].end);
                break;
            }
            res.push_back(intervals[i]);
        } 

        int i = l;
        while( i<N && intervals[i].start <= newInterval.end ) {
            newInterval.end = max(intervals[i].end, newInterval.end);
            i++;
        }

        res.push_back(newInterval);
        for (int j = i; j < N; ++j ) res.push_back(intervals[j]);
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<Interval> ivs{
            Interval(1,3),
            Interval(6,9),
        };
        auto res = sol.insert(ivs, Interval(2,5));
        for (auto i : res) {
            cout << i.start << " " << i.end <<endl;
        }
    }
    return 0;
}

