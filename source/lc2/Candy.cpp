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
    int candy(vector<int> &ratings) {
        int N = ratings.size();
        vector<int> C(N, 1);

        for (int i = 1; i < N; ++i ) {
            if ( ratings[i] > ratings[i-1] ) C[i] = C[i-1] + 1;
        }
        
        for (int i = N-2; i >= 0; --i ) {
            if ( ratings[i] > ratings[i+1] && C[i] <= C[i+1] ) C[i] = C[i+1] + 1;
        }

        int res = 0;
        for (int i = 0; i < N; ++i ) res += C[i];
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<int> num{4,2,3,4,1};
        cout << sol.candy(num) <<endl;
    }
    {
        vector<int> num{1,3,4,3,2,1};
        cout << sol.candy(num) <<endl;
    }
    return 0;
}

