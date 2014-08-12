#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// ToReview: second solution

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> res;
        sort( num.begin(), num.end() );
        int N = num.size();
        for (int i = 0; i+3 < N; ++i ) {
            if ( i>0 && num[i] == num[i-1] ) continue;
            for (int j = i+1; j+2 < N; ++j ) {
                if ( j>i+1 && num[j] == num[j-1] ) continue;
                int x = j+1;
                int y = N-1;
                while( x<y ) {
                    int sum = num[i] + num[j] + num[x] + num[y];
                    if ( sum>target ) y--;
                    else if ( sum<target ) x++;
                    else {
                        res.push_back({num[i],num[j],num[x],num[y]});
                        do{x++;} while ( x<y && num[x] == num[x-1] );
                        do{y--;} while ( x<y && num[y] == num[y+1] );
                    }
                }
            }
        }

        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<int> num{1, 0, -1, 0, -2, 2,};
        auto res = sol.fourSum(num, 0);
        for (auto ct : res) {
            for (auto i : ct){
                cout << i << " ";
            }
            cout <<endl;
        }
    }
    return 0;
}

