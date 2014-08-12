#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "tree.h"
#include <stack>

using namespace std;

// ToReview

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        // return preorderTraversal1(root);
        // return preorderTraversal2(root);
        return preorderTraversal2(root);
    }


    vector<int> preorderTraversal2(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> stk;
        if ( !root ) return res;
        stk.push(root);
        while( !stk.empty() ) {
            auto node = stk.top();
            res.push_back(node->val);
            stk.pop();
            if ( node->right ) stk.push(node->right);
            if ( node->left ) stk.push(node->left);
        }
        return res;
    }

    vector<int> preorderTraversal1(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> stk;
        auto pushPath = [&](TreeNode *cur) {
            while( cur ) {
                stk.push(cur);
                res.push_back(cur->val);
                cur = cur->left;
            }
        };

        pushPath(root);
        while( !stk.empty() ) {
            auto node = stk.top();
            stk.pop();
            pushPath(node->right);
        }

        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        string tree = "1,#,2,3";
        auto root = deserialBTree(tree);
        printPretty(root, 1, 1, cout);
        auto res = sol.preorderTraversal(root);
        for (auto i : res) cout << i << " ";
        cout <<endl;
    }
    {
        string tree = "3,1,#,#,2";
        auto root = deserialBTree(tree);
        printPretty(root, 1, 1, cout);
        auto res = sol.preorderTraversal(root);
        for (auto i : res) cout << i << " ";
        cout <<endl;
    }
    return 0;
}

