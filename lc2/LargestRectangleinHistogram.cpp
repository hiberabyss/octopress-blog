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
#include <climits>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // return largestRectangleArea1(height);
        return largestRectangleArea2(height);
    }

    int largestRectangleArea2(vector<int> &height) {
        int N = height.size();
        height.push_back(-1);
        stack<int> stk;

        int res = 0;
        for (int i = 0; i <= N; ++i ) {
            while( !stk.empty() && height[i] < height[stk.top()] ) {
                int h = height[stk.top()];
                stk.pop();
                int w = i - 1 - (stk.empty() ? -1 : stk.top());
                res = max(res, h*w);
            }
            stk.push(i);
        }
        return res;
    }

    int largestRectangleArea1(vector<int> &height) {
        int N = height.size();
        int res = 0;
        for (int i = 0; i < N; ++i ) {
            int minH = INT_MIN;
            for (int j = i; j < N && height[j]; ++j ) {
                minH = min(minH, height[j]);
                res = max(res, (j-i+1)*minH);
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<int> height{2,1,5,6,2,3};
        cout << sol.largestRectangleArea(height) <<endl;
    }
    {
        vector<int> height{2,1,2};
        cout << sol.largestRectangleArea(height) <<endl;
    }
    return 0;
}

