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
    bool isSymmetric(TreeNode *root) {
        return isSymmetric1(root);
    }
    bool isSymmetric1(TreeNode *root) {
        function<bool(TreeNode*,TreeNode*)> isSym = [&] (TreeNode *t1, TreeNode *t2) {
            if ( !t1 || !t2 ) return t1 == t2;
            if ( t1->val != t2->val ) return false;
            return isSym(t1->left, t2->right) && isSym(t1->right, t2->left);
        };
        
        if ( !root ) return true;
        return isSym(root->left, root->right);
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        string tree = "1,2,2,3,4,4,3";
        auto root = deserialBTree(tree);
        cout << boolalpha << sol.isSymmetric(root) <<endl;
    }
    return 0;
}
