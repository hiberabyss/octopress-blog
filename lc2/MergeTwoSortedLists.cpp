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

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        auto cur = &dummy;
        while( l1 && l2 ) {
            if ( l1->val <= l2->val ) cur->next=l1, l1 = l1->next;
            else cur->next=l2, l2=l2->next;
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return dummy.next;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    return 0;
}

