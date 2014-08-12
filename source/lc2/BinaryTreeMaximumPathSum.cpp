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

// ToReview

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        return maxPathSum1(root);
    }

    int maxPathSum1(TreeNode *root) {
        int res = INT_MIN;

        function<int(TreeNode*)> getMaxPath = [&] (TreeNode *cur) {
            if ( !cur ) return 0;
            int lsub = getMaxPath(cur->left);
            int rsub = getMaxPath(cur->right);
            int sub = max(cur->val, cur->val + max(lsub, rsub));
            res = max(res, max(sub, cur->val + lsub + rsub));
            return sub;
        };

        getMaxPath(root);

        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        string tree = "1,2,3";
        auto root = deserialBTree(tree);
        cout << sol.maxPathSum(root) <<endl;
    }
    {
        string tree = "1,-2,-3,1,3,-2,#,-1";
        auto root = deserialBTree(tree);
        printPretty(root, 1, 1, cout);
        cout << sol.maxPathSum(root) <<endl;
    }
    return 0;
}

