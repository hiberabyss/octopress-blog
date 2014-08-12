#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        vector<int> cb;
        sort( candidates.begin(), candidates.end() );
        function<void(int,int)> getCombSum = [&] (int ind, int curSum) {
            if ( curSum > target ) return;
            if ( curSum == target ) {
                res.push_back(cb);
                return;
            }

            for (int i = ind; i < candidates.size(); ++i ) {
                cb.push_back(candidates[i]);
                getCombSum(i, curSum+candidates[i]);
                cb.pop_back();
            }
        };

        int sum = 0;
        getCombSum(0, sum);
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<int> cand{2,3,6,7};
        auto res = sol.combinationSum(cand, 7);
        for (auto ct : res) {
            for (auto i : ct){
                cout << i << " ";
            }
            cout <<endl;
        }
    }
    return 0;
}

