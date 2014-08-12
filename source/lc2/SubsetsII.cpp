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

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        return subsetsWithDup1(S);
    }

    vector<vector<int> > subsetsWithDup2(vector<int> &S) {
        vector<vector<int>> res;
    }

    vector<vector<int> > subsetsWithDup1(vector<int> &S) {
        vector<vector<int>> res(1);
        sort( S.begin(), S.end() );
        int cnt = 0;
        for (size_t i = 0; i < S.size(); ++i ) {
            if ( i && S[i] == S[i-1] ) cnt++;
            else cnt = 0;
            int M = res.size();
            for (int j = 0; j < M; ++j ) {
                int L = res[j].size();
                if ( !cnt || (L>=cnt && res[j][L-cnt] == S[i]) ) {
                    auto copy = res[j];
                    copy.push_back(S[i]);
                    res.push_back(copy);
                }
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<int> num{1,2,2};
        auto res = sol.subsetsWithDup(num);
        for (auto ct : res) {
            for (auto i : ct){
                cout << i << " ";
            }
            cout <<endl;
        }
    }
    {
        vector<int> num{5,5,5,5,5};
        auto res = sol.subsetsWithDup(num);
        for (auto ct : res) {
            for (auto i : ct){
                cout << i << " ";
            }
            cout <<endl;
        }
    }
    return 0;
}

