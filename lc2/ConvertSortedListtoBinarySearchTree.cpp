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
#include "listnode.h"

using namespace std;

// ToReview

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        return sortedListToBST2(head);
        return sortedListToBST1(head);
    }

    TreeNode *sortedListToBST2(ListNode *head) {
        function<TreeNode*(ListNode*,int)> genTree = [&](ListNode*cur, int n) {
            if ( n<=0 ) return (TreeNode*)NULL;
            auto mn = cur;
            int m = n/2;
            for (int i = 0; i < m; ++i ) mn = mn->next;
            auto root = new TreeNode(mn->val);
            root->left = genTree(cur, m);
            root->right = genTree(mn->next, n-m-1);
            return root;
        };

        int N = 0;
        auto cur = head;
        while( cur ) {
            cur = cur->next;
            N++;
        }

        return genTree(head, N);
    }

    TreeNode *sortedListToBST1(ListNode *head) {
        vector<int> num;
        while( head ) num.push_back(head->val),head=head->next;

        function<TreeNode*(int,int)> genTree = [&] (int b, int e) {
            if ( b == e ) return (TreeNode*)nullptr;
            int m = b + (e-b)/2;
            auto root = new TreeNode(num[m]);
            root->left = genTree(b,m);
            root->right = genTree(m+1, e);
            return root;
        };

        return genTree(0, num.size());
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        auto head = initList({1,2,5,7});
        auto root = sol.sortedListToBST(head);
        printPretty(root, 1, 1, cout);
    }
    return 0;
}

