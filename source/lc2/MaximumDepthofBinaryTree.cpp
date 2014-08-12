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
    int maxDepth(TreeNode *root) {
        return maxDepth1(root);
    }

    int maxDepth1(TreeNode *root) {
        if ( !root ) return 0;
        return 1+ max( maxDepth1(root->left), maxDepth1(root->right) );
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    return 0;
}

