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
    bool isValidBST(TreeNode *root) {
        // return isValidBST1(root);
        return isValidBST2(root);
    }

    bool isValidBST2(TreeNode *root) {
        function<bool(TreeNode*,int,int)> isValid = [&] (TreeNode *cur, int lo, int hi) {
            if ( !cur ) return true;
            return (cur->val > lo && cur->val < hi) && 
                isValid(cur->left, lo, cur->val) &&
                isValid(cur->right, cur->val, hi);
        };
        return isValid(root, INT_MIN, INT_MAX);
    }

    bool isValidBST1(TreeNode *root) {
        if ( !root ) return true;
        if ( root->left ) {
            auto node = root->left;
            if ( root->val <= node->val ) return false;
            while( node->right ) node = node->right;
            if ( root->val <= node->val ) return false;
        }

        if ( root->right ) {
             auto node = root->right;
             if ( root->val >= node->val ) return false;
             while( node->left ) node = node->left;
             if ( root->val >= node->val ) return false;
        }

        return isValidBST1(root->left) && isValidBST1(root->right);
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    return 0;
}

