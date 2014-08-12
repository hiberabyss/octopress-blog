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
    int sumNumbers(TreeNode *root) {
        return sumNumbers1(root);
    }

    int sumNumbers1(TreeNode *root) {
        int res = 0;
        int path = 0;
        function<void(TreeNode*)> getPath = [&] (TreeNode *cur) {
            if ( !cur ) return;
            int tmp = path;
            path = path*10 +  cur->val;
            if ( !cur->left && !cur->right ) res += path;
            getPath(cur->left);
            getPath(cur->right);
            path = tmp;
        };
        getPath(root);
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        string tree = "1,2,3";
        auto root = deserialBTree(tree);
        cout << sol.sumNumbers(root) <<endl;
    }
    return 0;
}

