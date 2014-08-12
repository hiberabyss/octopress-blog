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
#include <limits>

using namespace std;

// ToReview

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if ( points.empty() ) return 0;
        int N = points.size();
        int maxP = 1;
        for (int i = 0; i < N-1; ++i ) {
            unordered_map<double,int> slopes;
            int ep = 1;
            int curMax = 0;
            for (int j = i+1; j < N; ++j ) {
                int x = points[i].x - points[j].x;
                int y = points[i].y - points[j].y;
                double sl = numeric_limits<double>::infinity(); 

                if ( !x && !y ) {
                    ep++;
                    continue;
                }

                if ( x ) sl = y * 1.0 / x;
                curMax = max(curMax, ++slopes[sl]);
            }
            maxP = max(maxP, ep+curMax);
        }
        return maxP;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    return 0;
}
