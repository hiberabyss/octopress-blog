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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> res;
        queue<TreeNode*> cq,nq;
        if ( !root ) return res;
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
        reverse( res.begin(), res.end() );
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        string tree = "3,9,20,#,#,15,7";
        auto root = deserialBTree(tree);
        auto res = sol.levelOrderBottom(root);
        for (auto ct : res) {
            for (auto i : ct){
                cout << i << " ";
            }
            cout <<endl;
        }
    }
    return 0;
}

