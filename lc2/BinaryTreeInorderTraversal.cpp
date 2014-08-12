#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "tree.h"
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // return inorderTraversal1(root);
        // return inorderTraversal2(root);
        return inorderTraversal3(root);
    }

    // thread tree: O(n), O(1)
    vector<int> inorderTraversal3(TreeNode *root) {
        vector<int> res;
        while( root ) {
            if ( root->left ) {
                auto pre = root->left;
                while ( pre->right && pre->right != root ) pre = pre->right;
                if ( !pre->right ) {
                    pre->right = root;
                    root = root->left;
                } else {
                    pre->right = NULL;
                    res.push_back(root->val);
                    root = root->right;
                }
            } else {
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
    }

    vector<int> inorderTraversal2(TreeNode *root) {
        stack<TreeNode*> stk;
        vector<int> res;
        auto pushLeft = [&] (TreeNode *node) {
            while( node ) {
                stk.push(node);
                node = node->left;
            }
        };
        
        pushLeft(root);
        while( !stk.empty() ) {
            auto node = stk.top();
            stk.pop();
            res.push_back(node->val);
            pushLeft(node->right);
        }

        return res;
    }

    vector<int> inorderTraversal1(TreeNode *root) {
        vector<int> res;
        function<void(TreeNode*)> inTra = [&] (TreeNode *root) {
            if ( !root ) return;
            inTra(root->left);
            res.push_back(root->val);
            inTra(root->right);
        };
        inTra(root);
        return res;
    } 
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        string tree = "2,1,3";
        auto root = deserialBTree(tree);
        auto res = sol.inorderTraversal(root);
        for (auto i : res) cout << i << " ";
        cout <<endl;
    }
    return 0;
}

