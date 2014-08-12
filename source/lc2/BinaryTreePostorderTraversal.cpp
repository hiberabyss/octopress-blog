#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "tree.h"
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // return postorderTraversal1(root);
        return postorderTraversal2(root);
    }

    vector<int> postorderTraversal2(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode *lastVist = NULL;

        auto pushNodes = [&](TreeNode *cur) {
            while( cur ) {
                stk.push(cur);
                cur = cur->left;
            }
        };

        pushNodes(root);
        while( !stk.empty() ) {
            auto node = stk.top();
            if ( !node->right || node->right == lastVist ) {
                res.push_back(node->val);
                lastVist = node;
                stk.pop();
            } else {
                pushNodes(node->right);
            }
        }

        return res;
    }

    vector<int> postorderTraversal1(TreeNode *root) {
        vector<int> res;
        function<void(TreeNode*)> postTraRec = [&] (TreeNode *cur) {
            if ( !cur ) return;
            postTraRec(cur->left);
            postTraRec(cur->right);
            res.push_back(cur->val);
        };
        postTraRec(root);
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        string tree = "3,1,2";
        auto root = deserialBTree(tree);
        printPretty(root, 1, 1, cout);
        auto res = sol.postorderTraversal(root);
        for (auto i : res) cout << i << " ";
        cout <<endl;
    }
    {
        string tree = "3,1,#,#,2";
        auto root = deserialBTree(tree);
        printPretty(root, 1, 1, cout);
        auto res = sol.postorderTraversal(root);
        for (auto i : res) cout << i << " ";
        cout <<endl;
    }
    return 0;
}

