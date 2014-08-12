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
#include <cmath>
#include "tree.h"

using namespace std;

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        // return isBalanced1(root);
        return isBalanced2(root);
    }

    bool isBalanced2(TreeNode *root) {
        function<bool(TreeNode*,int&)> check = [&] (TreeNode *root, int &depth) {
            if ( !root ) {
                depth = 0;
                return true;
            }

            int ld, rd;
            if ( !check(root->left, ld) ) return false;
            if ( !check(root->right, rd) ) return false;
            depth = max(ld, rd) +1;
            return abs(ld-rd) < 2;
        };
        int depth;
        return check(root, depth);
    }

    bool isBalanced1(TreeNode *root) {
        function<int(TreeNode*)> getHeight = [&](TreeNode *root) {
            if ( !root ) return 0;
            return 1 + max(getHeight(root->left), getHeight(root->right));
        };
        if ( !root ) return true;
        if ( abs( getHeight(root->left)-getHeight(root->right) ) > 1 )
            return false;
        return isBalanced1(root->left) && isBalanced1(root->right);
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        string tree = "1,2,2,3,#,#,3,4,#,#,4";
        auto root = deserialBTree(tree);
        printPretty(root, 1, 1, cout);
        cout << boolalpha << sol.isBalanced(root) <<endl;
    }
    return 0;
}

