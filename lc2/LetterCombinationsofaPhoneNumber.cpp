#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        return letterCombinations2(digits);
    }

    vector<string> letterCombinations2(string digits) {
        vector<string> res(1, "");
        for (auto dig : digits) {
            string lets = map[dig-'0'];
            int M = res.size();
            for (int i = 0; i < M; ++i ) {
                int N = lets.size();
                if ( !N ) continue;
                for (int j = 1; j < N; ++j ) {
                    auto copy = res[i];
                    copy.push_back(lets[j]);
                    res.push_back(copy);
                }
                res[i].push_back(lets[0]);
            }
        }
        return res;
    }

    vector<string> letterCombinations1(string digits) {
        vector<string> res;
        string letCom;

        function<void(int)> getLetCom = [&] (int ind) {
            if ( !digits[ind] ) {
                res.push_back(letCom);
                return;
            } 

            for (auto c : map[digits[ind]-'0']) {
                letCom.push_back(c);
                getLetCom(ind+1);
                letCom.pop_back();
            }
        };

        getLetCom(0);
        return res;
    }

private:
    string map[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
    };
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        string dig = "23";
        auto res = sol.letterCombinations(dig);
        for (auto s : res) {
            cout << s <<endl;
        }
    }
    return 0;
}

