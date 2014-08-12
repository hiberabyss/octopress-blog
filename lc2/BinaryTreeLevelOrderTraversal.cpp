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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if ( !root ) return res;
        queue<TreeNode*> cq,nq;
        cq.push(root);
        while( !cq.empty() ) {
            vector<int> lev;
            while( !cq.empty() ) {
                auto node = cq.front();
                cq.pop();
                lev.push_back(node->val);
                if ( node->left ) nq.push(node->left);
                if ( node->right ) nq.push(node->right);
            }
            swap(cq,nq);
            res.push_back(lev);
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    return 0;
}

