#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int>> res;
        vector<int> cb;

        sort( num.begin(), num.end() );
        function<void(int,int)> getComb = [&] (int ind, int sum) {
            if ( sum > target ) return;
            if ( sum == target ) {
                res.push_back(cb);
                return;
            }

            for (int i = ind; i < num.size(); ++i ) {
                if ( i>ind && num[i] == num[i-1] ) continue;
                cb.push_back(num[i]);
                getComb(i+1, sum+num[i]);
                cb.pop_back();
                // while ( i+1 < num.size() && num[i] == num[i+1] ) i++;
            }
        };

        getComb(0, 0);
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<int> num{10,1,2,7,6,1,5};
        auto res = sol.combinationSum2(num, 8);
        for (auto ct : res) {
            for (auto i : ct){
                cout << i << " ";
            }
            cout <<endl;
        }
    }
    return 0;
}

