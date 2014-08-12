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

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
 
class Solution {
public:
    void connect(TreeLinkNode *root) {
        connect2(root);
    }

    void connect2(TreeLinkNode *root) {
        if ( !root ) return;
        while( root && root->left ) {
            auto cur = root;
            while( cur ) {
                cur->left->next = cur->right;
                cur->right->next = cur->next ? cur->next->left : NULL;
                cur = cur->next;
            }
            root = root->left;
        }
    }

    void connect1(TreeLinkNode *root) {
        if ( !root ) return;
        queue<TreeLinkNode*> cq,nq;
        cq.push(root);

        while( !cq.empty() ) {
            while( !cq.empty() ) {
                auto cur = cq.front();
                cq.pop();
                cur->next = cq.empty() ? NULL : cq.front();
                if ( cur->left ) nq.push(cur->left);
                if ( cur->right ) nq.push(cur->right);
            }
            swap(cq, nq);
        }
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    return 0;
}

