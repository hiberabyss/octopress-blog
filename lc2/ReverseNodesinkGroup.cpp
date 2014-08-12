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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if ( !k ) return head;
        ListNode dummy(-1);
        dummy.next = head;
        auto slow = &dummy;
        auto fast = slow;
        while( fast ) {
            int cnt = k;
            while( cnt-- && fast ) fast = fast->next;
            if ( fast ) {
                auto next = slow->next;
                slow->next = fast;
                auto cur = next;
                while( slow != fast ) {
                    auto tmp = cur->next;
                    cur->next = slow;
                    slow = cur;
                    cur = tmp;
                }
                next->next = cur;
                slow = fast = next;
            }
        }
        return dummy.next;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        auto head = initList({1,2,3,4,5});
        printList(head);
        head = sol.reverseKGroup(head, 2);
        printList(head);
    }
    {
        auto head = initList({1,2,3,4,5});
        printList(head);
        head = sol.reverseKGroup(head, 3);
        printList(head);
    }
    return 0;
}
