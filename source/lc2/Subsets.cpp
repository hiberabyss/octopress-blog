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

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // return subsets1(S);
        return subsets2(S);
    }

    vector<vector<int> > subsets2(vector<int> &S) {
        vector<vector<int>> res(1);
        sort( S.begin(), S.end() );
        for (auto i : S) {
            int M = res.size();
            for (int j = 0; j < M; ++j ) {
                auto copy = res[j];
                copy.push_back(i);
                res.push_back(copy);
            }
        }
        return res;
    }

    vector<vector<int> > subsets1(vector<int> &S) {
        vector<vector<int>> res;
        sort( S.begin(), S.end() );
        int N = S.size();
        for (int i = 0; i < (1<<N); ++i ) {
            vector<int> sub;
            int j = 0;
            int tmp = i;
            while( tmp ) {
                if ( tmp&1 ) sub.push_back(S[j]);
                j++;
                tmp >>= 1;
            }
            res.push_back(sub);
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<int> num{1,2,3};
        auto res = sol.subsets(num);
        for (auto ct : res) {
            for (auto i : ct){
                cout << i << " ";
            }
            cout <<endl;
        }
    }
    return 0;
}

