
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        return permute2(num);
    }

    vector<vector<int> > permute2(vector<int> &num) {
        int N = num.size();
        auto nextPerm = [&] () {
            int i = N-2;
            while ( i>=0 && num[i] >= num[i+1] ) i--;
            if ( i<0 ) return false;
            int j = i+1;
            while ( j<N && num[j] > num[i] ) j++;
            swap(num[i], num[j-1]);
            reverse(num.begin()+i+1, num.end());
            return true;
        };

        vector<vector<int>> res;
        do {
            res.push_back(num);
        } while( nextPerm() );

        return res;
    }

    vector<vector<int> > permute1(vector<int> &num) {
        vector<vector<int>> res;
        if ( num.empty() ) return res;

        function<void(int)> getPermute = [&] (int n) {
            if ( n >= num.size()-1 ) {
                res.push_back(num);
                // shouldn't forget this
                return;
            }

            for (int i = n; i < num.size(); ++i ) {
                swap(num[n], num[i]);
                getPermute(n+1);
                swap(num[n], num[i]);
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
        auto res = sol.permute(num);
        for (auto ct : res) {
            for (auto i : ct){
                cout << i << " ";
            }
            cout <<endl;
        }
    }
    {
        vector<int> num;
        auto res = sol.permute(num);
        for (auto ct : res) {
            for (auto i : ct){
                cout << i << " ";
            }
            cout <<endl;
        }
    }
    return 0;
}

