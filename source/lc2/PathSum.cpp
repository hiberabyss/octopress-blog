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

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        return hasPathSum1(root,sum);
    }

    // be caution with the definition of path
    bool hasPathSum1(TreeNode *root, int sum) {
        if ( !root ) return false;
        sum -= root->val;
        if ( !root->left && !root->right ) return sum == 0;
        if ( root->left && hasPathSum1(root->left, sum) ) return true;
        if ( root->right && hasPathSum1(root->right, sum) ) return true;
        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    return 0;
}

