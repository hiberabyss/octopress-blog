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
    int evalRPN(vector<string> &tokens) {
        stack<int> stk;
        for (auto s : tokens) {
            if ( opSet.count(s) ) {
                int op1,op2;
                op2 = stk.top();
                stk.pop();
                op1 = stk.top();
                stk.pop();
                switch(s[0]) {
                    case '+':
                        stk.push(op1+op2);
                        break;
                    case '-':
                        stk.push(op1-op2);
                        break;
                    case '*':
                        stk.push(op1*op2);
                        break;
                    case '/':
                        stk.push(op1/op2);
                        break;
                    default: break;
                }
            } else {
                stk.push(stoi(s));
            }
        }

        return stk.top();
    }
private:
    unordered_set<string> opSet = { "+", "-", "*", "/" };
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<string> tokens{"2", "1", "+", "3", "*"};
        cout << sol.evalRPN(tokens) <<endl;
    } 
    {
        vector<string> tokens{"0","3","/"};
        cout << sol.evalRPN(tokens) <<endl;
    } 
    {
        vector<string> tokens{"-1","1","*","-1","+"};
        cout << sol.evalRPN(tokens) <<endl;
    }
    return 0;
}

