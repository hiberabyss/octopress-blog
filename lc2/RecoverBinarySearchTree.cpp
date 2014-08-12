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
    void recoverTree(TreeNode *root) {
        // recoverTree1(root);
        // recoverTree2(root);
        recoverTree3(root);
    }

    void recoverTree3(TreeNode *root) {
        TreeNode *pre = NULL;
        auto first = pre;
        auto second = pre;
        while( root ) {
            auto visitNode = [&] (TreeNode * &cur) {
                if ( pre && pre->val > cur->val ) {
                    if ( !first ) first = pre;
                    second = cur;
                }
                pre = cur;
                cur = cur->right;
            };

            if ( root->left ) {
                auto node = root->left;
                while ( node->right && node->right != root ) node = node->right;
                if ( !node->right ) {
                    node->right = root;
                    root = root->left;
                } else {
                    node->right = NULL;
                    visitNode(root);
                }
            } else visitNode(root);
        }

        swap(first->val, second->val);
    }

    void recoverTree2(TreeNode *root) {
        TreeNode *pre = NULL;
        auto first = pre;
        auto second = pre;
        stack<TreeNode*> stk;
        auto pushRootLeft = [&] ( TreeNode *root ) {
            while( root ) {
                stk.push(root);
                root = root->left;
            }
        };

        pushRootLeft(root);
        while( !stk.empty() ) {
            auto cur = stk.top();
            stk.pop();
            if ( pre && pre->val > cur->val ) {
                if ( !first ) first = pre;
                second = cur;
            }
            pre = cur;
            if ( cur->right ) pushRootLeft(cur->right);
        }

        swap(first->val, second->val);
    }

    void recoverTree1(TreeNode *root) {
        TreeNode *pre = NULL;
        TreeNode *first = NULL;
        TreeNode *second;
        function<void(TreeNode*)> inTra = [&] (TreeNode *cur) {
            if ( !cur ) return;
            inTra(cur->left);
            if ( pre && pre->val > cur->val ) {
                if ( !first ) first = pre;
                second = cur;
            }
            pre = cur;
            inTra(cur->right);
        };
        inTra(root);
        swap(first->val, second->val);
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
         string tree = "0,1";
         auto root = deserialBTree(tree);
         sol.recoverTree(root);
         printPretty(root, 1, 1, cout);
    }
    return 0;
}

