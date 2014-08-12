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

// ToReview

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        return sortList1(head);
    }

    ListNode *sortList1(ListNode *head) {
        if ( !head || !head->next ) return head;
        auto slow = head;
        auto fast = head->next;

        while( fast && fast->next ) {
            slow = slow->next;
            fast = fast->next->next;
        }

        auto mergeList = [&] (ListNode *l1, ListNode *l2) {
            ListNode dummy(-1);
            auto curP = &dummy;
            while( l1 && l2 ) {
                if ( l1->val <= l2->val ) {
                    curP->next = l1;
                    l1 = l1->next;
                } else {
                    curP->next = l2;
                    l2 = l2->next;
                }
                curP = curP->next;
            }
            curP->next = l1 ? l1 : l2;
            return dummy.next;
        };

        auto l1 = sortList1(slow->next);
        slow->next = NULL;
        auto l2 = sortList1(head);
        return mergeList(l2, l1);
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        vector<int> num{9,9,2,5,4,6,2,9,1};
        auto head = initList(num);
        printList(head);
        head = sol.sortList(head);
        printList(head);
    }
    return 0;
}

