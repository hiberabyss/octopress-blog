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
#include "tree.h"

using namespace std;

// ToReview

class Solution {
public:
    void flatten(TreeNode *root) {
        // flatten1(root);
        flatten2(root);
    }

    void flatten2(TreeNode *root) {
        while( root ) {
            if ( root->left ) {
                auto cur = root->left;
                while ( cur->right ) cur = cur->right;
                cur->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }
    }

    void flatten1(TreeNode *root) {
        if ( !root ) return;
        TreeNode dummy(-1);
        auto cur = &dummy;
        stack<TreeNode*> stk;

        stk.push(root);
        while( !stk.empty() ) {
            auto node = stk.top();
            cur->right = node;
            cur = cur->right;
            stk.pop();
            if ( node->right ) stk.push(node->right);
            if ( node->left ) stk.push(node->left);
            node->left = NULL;
        }
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        string tree = "1,2,5,3,4,#,6";
        auto root = deserialBTree(tree);
        printPretty(root, 1, 1, cout);
        sol.flatten(root);
        printPretty(root, 1, 1, cout);
    }
    return 0;
}

