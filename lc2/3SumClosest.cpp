#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int N = num.size();
        if ( N<3 ) return -1;
        sort( num.begin(), num.end() );
        // must be initilized
        int res = num[0] + num[1] + num[2];
        for (int i = 0; i+2 < N; ++i ) {
            if ( i>0 && num[i] == num[i-1] ) continue;
            int x = i+1;
            int y = N-1;
            while( x<y ) {
                int sum = num[i] + num[x] + num[y];
                if ( abs(sum-target) < abs(res-target) ) res = sum;
                if ( sum > target ) y--;
                else if ( sum<target ) x++;
                else return res;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<int> num{-1, 2, 4};
        cout << "res: " << sol.threeSumClosest(num, 1) <<endl;
    }
    {
        vector<int> num{0,1,2};
        cout << "res: " << sol.threeSumClosest(num, 1) <<endl;
    }
    return 0;
}

