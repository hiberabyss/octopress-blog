#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// ToReview

class Solution {
public:
    int maxArea(vector<int> &height) {
        int res = 0;
        int i = 0;
        int j = height.size()-1;
        while( i<j ) {
            int tmp = (j-i) * min(height[i], height[j]);
            res = max(res, tmp);
            if ( height[i] < height[j] ) i++;
            else j--;
        }

        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<int> num{1,1};
        cout << "res: " << sol.maxArea(num) <<endl;
    }
    return 0;
}
