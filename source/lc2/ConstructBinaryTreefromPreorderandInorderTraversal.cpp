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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        unordered_map<int,int> map;
        for (size_t i = 0; i < inorder.size(); ++i ) map[inorder[i]] = i;
        function<TreeNode*(int,int,int)> buildRec = [&](int ps, int is, int len) -> TreeNode* {
            if ( !len ) return NULL;
            int val = preorder[ps];
            int m = map[val];
            TreeNode *root = new TreeNode(val);
            int ll = m-is;
            root->left = buildRec(ps+1, is, ll);
            root->right = buildRec(ps+1+ll, m+1, len-ll-1);
            return root;
        };
        return buildRec(0, 0, inorder.size());
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<int> inorder{1,2,3};
        vector<int> preorder{2,1,3};
        auto root = sol.buildTree(preorder, inorder);
        printPretty(root, 1, 1, cout);
    }
    return 0;
}

