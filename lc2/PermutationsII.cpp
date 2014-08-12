#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // return permuteUnique1(num);
        return permuteUnique2(num);
    }

    vector<vector<int> > permuteUnique2(vector<int> &num) {
        int N = num.size();
        auto nextPerm = [&] () {
            int i = N-2;
            while ( i>=0 && num[i] >= num[i+1] ) i--;
            if ( i<0 ) return false;
            int j = i+1;
            while ( j<N && num[j] > num[i] ) j++;
            swap(num[i], num[j-1]);
            reverse( num.begin()+i+1, num.end() );
            return true;
        };

        sort( num.begin(), num.end() );
        vector<vector<int>> res;
        do {
            res.push_back(num);
        } while ( nextPerm() );

        return res;
    }

    vector<vector<int> > permuteUnique1(vector<int> &num) {
        vector<vector<int>> res;
        if ( num.empty() ) return res;
        int N = num.size();

        function<void(int)> exchange = [&] (int ind) {
            if ( ind >= N-1 ) {
                res.push_back(num);
                return;
            }

            unordered_set<int> visit;
            for (int i = ind; i < N; ++i ) {
                if ( visit.count(num[i]) ) continue;
                visit.insert(num[i]);
                swap(num[ind], num[i]);
                exchange(ind+1);
                swap(num[ind], num[i]);
            }
        };

        exchange(0);
        return res;
    }

    // two sets must be different
    // 1, 1, 2, 2
    vector<vector<int> > permuteUniqueError(vector<int> &num) {
        int N = num.size();
        vector<vector<int>> res;

        function<void(int)> getPermute = [&] (int n) {
            if ( n == N ) {
                res.push_back(num);
                return;
            }

            for (int i = n; i < N; ++i ) {
                if ( i != n && num[n] == num[i] ) continue;
                swap(num[n],num[i]);
                getPermute(n+1);
                swap(num[n],num[i]);
            }
        };

        getPermute(0);
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<int> num{1,2,3};
        auto res = sol.permuteUnique(num);
        for (auto ct : res) {
            for (auto i : ct){
                cout << i << " ";
            }
            cout <<endl;
        }
    }

    {
        vector<int> num{1,1,2,2};
        auto res = sol.permuteUnique(num);
        for (auto ct : res) {
            for (auto i : ct){
                cout << i << " ";
            }
            cout <<endl;
        }
    }
    return 0;
}

