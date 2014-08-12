#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> res;
        int sum = 1;
        int i = digits.size()-1;
        while( i>=0 ) {
            sum += digits[i];
            res.push_back(sum%10);
            sum /= 10;
            i--;
        }

        if ( sum ) res.push_back(1);
        reverse( res.begin(), res.end() );
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<int> num{0};
        auto res = sol.plusOne(num);
        for (auto i : res) {
            cout << i;
        }
    }
    return 0;
}
