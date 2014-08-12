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

// ToReview

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        return pathSum1(root, sum);
    }

    vector<vector<int> > pathSum1(TreeNode *root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        function<void(TreeNode*,int)> getPath = [&] (TreeNode *root, int sum) {
            if ( !root ) return;
            sum -= root->val;
            path.push_back(root->val);
            if ( !root->left && !root->right && !sum ) {
                res.push_back(path);
            }

            getPath(root->left, sum);
            getPath(root->right, sum);
            path.pop_back();
        };

        getPath(root, sum);
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        string tree = "5,4,8,11,#,13,4,7,2,#,3,5,1";
        auto root = deserialBTree(tree);
        printPretty(root, 1, 1, cout);
        auto res = sol.pathSum(root, 22);
        for (auto ct : res) {
            for (auto i : ct){
                cout << i << " ";
            }
            cout <<endl;
        }
    }
    return 0;
}

