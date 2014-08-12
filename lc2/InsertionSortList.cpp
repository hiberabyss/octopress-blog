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
#include "listnode.h"

using namespace std;

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if ( !head ) return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *cur = head;
        while( cur->next ) {
            auto curNext = cur->next;
            auto insP = &dummy;
            while ( insP != cur && cur->next->val > insP->next->val ) insP = insP->next;
            if ( insP == cur ) {
                cur = cur->next;
                continue;
            }
            cur->next = curNext->next;
            curNext->next = insP->next;
            insP->next = curNext;
        }
        return dummy.next;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<int> num{9,9,2,5,4,6,2,9,1};
        auto head = initList(num);
        printList(head);
        auto res = sol.insertionSortList(head);
        printList(res);
    }
    {
        vector<int> num{1,2,3,4};
        auto head = initList(num);
        printList(head);
        auto res = sol.insertionSortList(head);
        printList(res);
    }
    return 0;
}

