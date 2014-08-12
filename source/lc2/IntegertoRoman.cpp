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
    string intToRoman(int num) {
        string res;
        for (int i = 0; num && i < val.size(); ++i ) {
            for (int j = 0; j < num/val[i]; ++j ) res += symb[i];
            num %= val[i];
        }
        return res;
    }

private:
    vector<int> val = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> symb{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        cout << sol.intToRoman(5);
    }
    return 0;
}

