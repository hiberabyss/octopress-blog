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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST1(num);
    }

    TreeNode *sortedArrayToBST1(vector<int> &num) {
        function<TreeNode*(int,int)> toBST = [&](int begin, int end) {
            if ( begin == end ) return (TreeNode*)NULL;
            int mid = begin + (end-begin)/2;
            auto root = new TreeNode(num[mid]);
            root->left = toBST(begin, mid);
            root->right = toBST(mid+1, end);
            return root;
        };

        return toBST(0, num.size());
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    return 0;
}
