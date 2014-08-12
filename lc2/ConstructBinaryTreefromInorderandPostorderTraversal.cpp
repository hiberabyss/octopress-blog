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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // return buildTree1(inorder, postorder);
        return buildTree2(inorder, postorder);
    }

    TreeNode *buildTree2(vector<int> &inorder, vector<int> &postorder) {
        unordered_map<int,int> map;
        for (size_t i = 0; i < inorder.size(); ++i ) map[inorder[i]] = i;
        function<TreeNode*(int,int,int)> buildRec = [&](int is, int ps, int len) -> TreeNode* {
            if ( !len ) return NULL;
            int val = postorder[ps+len-1];
            TreeNode *root = new TreeNode(val);
            int m = map[val];
            int llen = m-is;
            root->left = buildRec(is, ps, llen);
            root->right = buildRec(m+1, ps+llen, len-llen-1);
            return root;
        };
        return buildRec(0, 0, inorder.size());
    }

    TreeNode *buildTree1(vector<int> &inorder, vector<int> &postorder) {
        function<TreeNode*(int,int,int)> buildRec = [&](int is, int ps, int len) -> TreeNode* {
            if ( !len ) return NULL;
            int val = postorder[ps+len-1];
            TreeNode *root = new TreeNode(val);
            int m = is;
            while ( inorder[m] != val ) m++;
            int llen = m-is;
            root->left = buildRec(is, ps, llen);
            root->right = buildRec(m+1, ps+llen, len-llen-1);
            return root;
        };
        return buildRec(0, 0, inorder.size());
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<int> inorder{1,2,3};
        vector<int> postorder{1,3,2};
        auto res = sol.buildTree(inorder, postorder);
        printPretty(res, 1, 1, cout);
    }
    return 0;
}

