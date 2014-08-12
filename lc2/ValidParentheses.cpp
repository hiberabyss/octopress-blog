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
    bool isValid(string s) {
        stack<char> stk;
        for (auto c : s) {
            if ( mat.count(c) ) stk.push(c);
            else if ( !stk.empty() && mat[stk.top()] == c ) stk.pop();
            else return false;
        }
        return stk.empty();
    }
private:
    unordered_map<char,char> mat{ {'(',')'}, {'[', ']'}, {'{', '}'} };
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        string s = "()";
        cout << boolalpha << sol.isValid(s) <<endl;
    }
    return 0;
}

