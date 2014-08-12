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
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees1(n);
    }

    vector<TreeNode*> generateTrees1(int n) {
        function<vector<TreeNode*>(int,int)> genTree = [&] (int l, int h) {
            vector<TreeNode*> res;
            if ( l>h ) {
                res.push_back(nullptr);
                return res;
            }

            for (int i = l; i <= h; ++i ) {
                auto ln = genTree(l,i-1);
                auto rn = genTree(i+1, h);
                for (auto l : ln) {
                    for (auto r : rn) {
                        auto root = new TreeNode(i);
                        root->left = l;
                        root->right = r;
                        res.push_back(root);
                    }
                }
            }
        };

        return genTree(1, n);
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        auto res = sol.generateTrees(3);
        for (auto t : res) {
            printPretty(t, 1, 1, cout);
        }
    }
    return 0;
}

