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
#include <climits>
#include "tree.h"

using namespace std;

class Solution {
public:
    int minDepth(TreeNode *root) {
        return minDepth1(root);
    }

    int minDepth1(TreeNode *root) {
        if ( !root ) return 0;
        if ( !root->left && !root->right ) return 1;

        int minD = INT_MAX;
        if ( root->left ) minD = min(minD, minDepth1(root->left));
        if ( root->right ) minD = min(minD, minDepth1(root->right));
        return minD+1;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
         string tree = "1,2";
         auto root = deserialBTree(tree);
         cout << sol.minDepth(root) <<endl;
    }
    return 0;
}

