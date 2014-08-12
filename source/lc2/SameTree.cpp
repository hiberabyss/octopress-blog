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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        function<bool(TreeNode*,TreeNode*)> isSame = [&](TreeNode *t1, TreeNode *t2) {
            if ( !t1 || !t2 ) return t1 == t2;
            if ( t1->val != t2->val ) return false;
            return isSame(t1->left, t2->left) && isSame(t1->right, t2->right);
        };
        return isSame(p,q);
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    return 0;
}

