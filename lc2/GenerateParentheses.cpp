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

// ToReview

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string sol;
        function<void(int,int)> putParen = [&] (int l, int r) {
            if ( !l && !r ) {
                res.push_back(sol);
                return;
            }

            if ( l>0 ) {
                sol += '(';
                putParen(l-1, r);
                sol.pop_back();
            } 

            if ( r>l ) {
                sol += ')';
                putParen(l, r-1);
                sol.pop_back();
            } 
        };
        putParen(n,n);
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        auto res = sol.generateParenthesis(3);
        for (auto i : res) cout << i <<endl;
        cout <<endl;
    }
    return 0;
}

