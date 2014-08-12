// http://leetcodenotes.wordpress.com/2013/10/19/leetcode-longest-valid-parentheses-%E8%BF%99%E7%A7%8D%E6%8B%AC%E5%8F%B7%E7%BB%84%E5%90%88%EF%BC%8C%E6%9C%80%E9%95%BF%E7%9A%84valid%E6%8B%AC%E5%8F%B7%E7%BB%84%E5%90%88%E6%9C%89%E5%A4%9A/
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
    int longestValidParentheses(string s) {
        return longestValidParentheses2(s);
    }

    int longestValidParentheses2(string &s) {
        int N = s.size();
        int res = 0;
        int l = 0;
        int r = 0;
        for (int i = 0; i < N; ++i ) {
            if ( s[i] == '(' ) l++;
            else r++;
            if ( l == r ) res = max(res, 2*l);
            else if ( l<r ) l = 0, r = 0;
        }

        l = 0;
        r = 0;
        for (int i = N-1; i >= 0; --i ) {
            if ( s[i] == ')' ) r++;
            else l++;
            if ( l == r ) res = max(res, 2*l);
            if ( l>r ) l=0,r=0;
        }
        return res;
    }

    int longestValidParentheses1(string &s) {
        int res = 0;
        stack<int> stk;
        for (int i = 0; s[i]; ++i ) {
            if ( s[i] == ')' && !stk.empty() && s[stk.top()] == '(' ) {
                stk.pop();
                if ( stk.empty() ) res = i+1;
                else res = max(res, i-stk.top());
            } else {
                stk.push(i);
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        cout << sol.longestValidParentheses("()()") <<endl;
    }
    {
        cout << sol.longestValidParentheses("()(()") <<endl;
    }
    {
        cout << sol.longestValidParentheses(")(") <<endl;
    }
    return 0;
}
